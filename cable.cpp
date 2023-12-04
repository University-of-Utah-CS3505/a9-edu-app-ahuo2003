#include "cable.h"

Cable::Cable(QPoint startPos, QColor cableColor)
{
    //Set the color of the cables
    this->cableColor = cableColor;
    cableEndPosColor = cableColor.darker();
    moveHorizontal = false;
    moveVertical = false;

    //Append the starting position to the path list
    path.append(startPos);

    cableEndPos = &(path[0]);
    canDraw = false;
}



void Cable::mousePressed(QImage &image, const QPoint &mouseLocation)
{
    //If the user clicked at the end of the cable, allow them to draw.
    if ((mouseLocation.x() == cableEndPos->x()) && (mouseLocation.y() == cableEndPos->y())){
        // Start the Painter
        painter.begin(&image);

        // Set the pen to paint based on the cable color
        QPen cursorPen = painter.pen();
        cursorPen.setColor(cableColor);
        painter.setPen(cursorPen);

        //Set ability to draw to true
        canDraw = true;
    }
}

void Cable::mouseReleased(QImage &image)
{
    //Set the end of the cable to the last item in the path list, and set its pixel color in the canvas to a darker version.
    if (canDraw){
        cableEndPos = &(path[path.size() - 1]);
        image.setPixelColor(*cableEndPos, cableEndPosColor);

        //Stop the painter and remove the ability to draw
        canDraw = false;
        moveHorizontal = false;
        moveVertical = false;
        painter.end();
    }
}

void Cable::mouseMoved(const QPoint &mouseLocation)
{
    //If the user starts at a drawable pixel, let it draw
    if (canDraw){
        if (!moveHorizontal && !moveVertical){
            int dx = cableEndPos->x() - mouseLocation.x();
            int dy = cableEndPos->y() - mouseLocation.y();
            if (*cableEndPos != mouseLocation) {
                if (dx == 0){
                    moveVertical = true;
                }
                else if (dy == 0){
                    moveHorizontal = true;
                }

                //Check whether we are drawing on top of existing cable or not
                if (path.contains(mouseLocation)) isDeleting = true;
                else                              isDeleting = false;
            }
        }
        //TODO: Add check to only be able to draw within boundaries
        drawLine(*cableEndPos, mouseLocation);
        appendToPath(*cableEndPos, mouseLocation);
        qDebug() << path.size();
    }
}

void Cable::drawLine(const QPoint& startPoint, const QPoint& endPoint)
{
    //Determine the painter color based on whether the program is drawing or deleting.
    QPen cursorPen = painter.pen();
    if (isDeleting) {
        cursorPen.setColor(Qt::transparent);
        painter.setPen(cursorPen);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
    }
    else {
        cursorPen.setColor(cableColor);
        painter.setPen(cursorPen);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    }

    //Draws either in the vertical or horizontal direction depending on the initial direction determined by the user.
    QPoint direction;
    if (moveVertical){
        direction = QPoint(startPoint.x(), endPoint.y());
        painter.drawLine(startPoint, direction);
    }
    else if (moveHorizontal){
        direction = QPoint(endPoint.x(), startPoint.y());
        painter.drawLine(startPoint, direction);
    }

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
}


void Cable::appendToPath(const QPoint &startPoint, const QPoint &endPoint){
    if (!isDeleting) {
        int step = 1;
        if (moveVertical){
            if (endPoint.y() < startPoint.y())
                step = -1;
            for (int y = startPoint.y(); y != endPoint.y() + step; y += step){
                if (!path.contains(QPoint(startPoint.x(), y)))
                    path.append(QPoint(startPoint.x(), y));
            }
        }
        else if (moveHorizontal){
            if (endPoint.x() < startPoint.x())
                step = -1;
            for (int x = startPoint.x(); x != endPoint.x() + step; x += step){
                if (!path.contains(QPoint(x, startPoint.y())))
                    path.append(QPoint(x, startPoint.y()));
            }
        }
    }
    else {
        // Remove the cable from the path if deleting
        int deleteIndex = path.indexOf(endPoint) + 1;
        if (deleteIndex != -1) {
            path.erase(path.begin() + deleteIndex, path.end());
        }
    }
}

void Cable::changeScaleFactor(int newScaleFactor){
    scaleFactor = newScaleFactor;
}

QPoint *Cable::getCableEndPos() const
{
    return cableEndPos;
}
