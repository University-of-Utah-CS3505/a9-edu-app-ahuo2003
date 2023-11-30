#include "cable.h"

Cable::Cable(QPoint startPos, QColor cableColor)
{
    //Set the color of the cables
    this->cableColor = cableColor;
    cableEndPosColor = cableColor.darker(20);

    //Append the starting position to the path list
    path.append(startPos);

    cableEndPos = &(path[0]);
    scaleFactor = 16; // Default scaleFactor
    canDraw = false;
}



void Cable::mousePressed(QImage &image, const QPoint &mouseLocation)
{
    //Convert the mouse coordinates into image coordinates.
    QPoint mouseLocationInImage = mapToImageCoordinates(mouseLocation, scaleFactor);

    //If the user clicked at the end of the cable, allow them to draw.
    if ((mouseLocationInImage.x() == cableEndPos->x()) && (mouseLocationInImage.y() == cableEndPos->y())){
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

void Cable::mouseReleased(QImage &image, const QPoint &mouseLocation)
{
    //Set the end of the cable to the last item in the path list, and set its pixel color in the canvas to a darker version.
    cableEndPos = &(path[path.size() - 1]);
    image.setPixelColor(mapToImageCoordinates(mouseLocation, scaleFactor), cableEndPosColor);

    //Stop the painter and remove the ability to draw
    canDraw = false;
    painter.end();
}

void Cable::mouseMoved(const QPoint &mouseLocation)
{
    //Convert mouse coordinates into pixel coordinates.
    QPoint startPoint = mapToImageCoordinates(mouseLocation, scaleFactor);
    QPoint endPoint = mapToImageCoordinates(mouseLocation, scaleFactor);

    //If the user starts at a drawable pixel, let it draw
    if (canDraw){
        //Calculate change in y and x, and determine whether the user is drawing a straight line.
        int dx = startPoint.x() - endPoint.x();
        int dy = startPoint.y() - endPoint.y();

        //If the user is drawing in a straight line, draw the line and record the coordinates.
        if (dx == 0 || dy == 0){
            drawLine(startPoint, endPoint);
            appendToPath(startPoint, endPoint, dy, dx);
        }
    }
}

void Cable::drawLine(const QPoint& startPoint, const QPoint& endPoint)
{
    painter.drawLine(startPoint, endPoint);
}

void Cable::appendToPath(const QPoint &startPoint, const QPoint &endPoint, int &dy, int &dx){
    //Determine whether the line is horizontal or vertical, and add all the pixel coordinates between the 2 points selected.
    if (dx == 0){
        for (int y = startPoint.y(); y <= endPoint.y(); y++){
            path.append(QPoint(startPoint.x(), y));
        }
    }
    else if (dy == 0){
        for (int x = startPoint.x(); x <= endPoint.x(); x++){
            path.append(QPoint(x, startPoint.y()));
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


QPoint Cable::mapToImageCoordinates(const QPoint &point, int scaleFactor){
    return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}
