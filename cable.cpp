#include "cable.h"

Cable::Cable(QPoint startPos, QColor cableColor)
{
    cableEndPos = startPos;
    this->cableColor = cableColor;
    cableEndPosColor = cableColor.darker(20);
    path.append(cableEndPos);
    canDraw = false;
//    QPoint cableEndPos;
//    QColor cableColor;
//    QColor cableEndPosColor;
//    QList<QPoint> path;
}

void Cable::mousePressed(QImage &image, const QPoint &mouseLocation)
{
    if ((mouseLocation.x() == cableEndPos.x()) && mouseLocation.y() == cableEndPos.y()){
        canDraw = true;
    }
}

void Cable::mouseReleased(QImage &image, const QPoint &mouseLocation)
{
    canDraw = false;
}

void Cable::mouseMoved(QImage &image, const QPoint &mouseLocation)
{
    if (canDraw){
        //Draw Horizontally or vertically
        //Add location(s) to path
    }
}

void Cable::drawLine()
{

}
