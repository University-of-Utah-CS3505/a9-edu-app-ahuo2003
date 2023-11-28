#include "InGate.h"

InGate::InGate(int pos_x, int pos_y)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->truth = false;
}

void InGate::draw(QImage &image){
    this->painter.begin(&image);

    QPen cursorPen = painter.pen();
    cursorPen.setColor(Qt::red);
    painter.setPen(cursorPen);

    QPoint point(pos_x, pos_y);
    painter.drawPoint(point);
}
