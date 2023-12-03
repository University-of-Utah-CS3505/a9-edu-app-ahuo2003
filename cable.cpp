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
            qDebug() << dx;
            qDebug() << dy;
            if (*cableEndPos != mouseLocation) {
                if (dx == 0){
                    moveVertical = true;
                }
                else if (dy == 0){
                    moveHorizontal = true;
                }
            }
        }

        drawLine(*cableEndPos, mouseLocation);
        appendToPath(*cableEndPos, mouseLocation);
    }
}

void Cable::drawLine(const QPoint& startPoint, const QPoint& endPoint)
{

    QPoint direction;
    if (moveVertical){
        direction = QPoint(startPoint.x(), endPoint.y());
        painter.drawLine(startPoint, direction);
    }
    //Fix horizontal moving
    else if (moveHorizontal){
        direction = QPoint(endPoint.x(), startPoint.y());
        painter.drawLine(startPoint, direction);
    }
}

void Cable::appendToPath(const QPoint &startPoint, const QPoint &endPoint){
    //Determine whether the line is horizontal or vertical, and add all the pixel coordinates between the 2 points selected.
    int step = 1;
    if (moveVertical){
        if (endPoint.y() < startPoint.y()) step = -1;
        for (int y = startPoint.y(); y != endPoint.y(); y+=step){
            path.append(QPoint(startPoint.x(), y));
        }
        path.append(QPoint(startPoint.x(), endPoint.y()));
    }
    else if (moveHorizontal){
        if (endPoint.x() < startPoint.x()) step = -1;
        for (int x = startPoint.x(); x != endPoint.x(); x+=step){
            path.append(QPoint(x, startPoint.y()));
        }
        path.append(QPoint(endPoint.x(), startPoint.y()));
    }
}

void Cable::changeScaleFactor(int newScaleFactor){
    scaleFactor = newScaleFactor;
}

QPoint *Cable::getCableEndPos() const
{
    return cableEndPos;
}
