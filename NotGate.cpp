#include "NotGate.h"


NotGate::NotGate(int x, int y) : Gate(x,y){ this->type = GateType::NOT; }

NotGate::~NotGate() = default;

GateType NotGate::getType() const{
    return this->type;
}

void NotGate::draw(QImage &image) {
    this->painter.begin(&image);

    QPen cursorPen = painter.pen();
    cursorPen.setColor(Qt::red);
    painter.setPen(cursorPen);

    QPoint center(pos_x, pos_y);
    painter.drawPoint(center);
    notGatePixels.append(center);

    QPoint top(center.x(), center.y() + 1);
    painter.drawPoint(top);
    notGatePixels.append(top);

    QPoint bottom(center.x(), center.y() - 1);
    painter.drawPoint(bottom);
    notGatePixels.append(bottom);

    QPoint right(center.x() + 1, center.y());
    painter.drawPoint(right);
    notGatePixels.append(right);

    cursorPen.setColor(Qt::yellow);
    painter.setPen(cursorPen);

    QPoint inputWire(center.x() - 1, center.y());
    painter.drawPoint(inputWire);
    notGatePixels.append(inputWire);

    QPoint outputWire(center.x() + 2, center.y());
    painter.drawPoint(outputWire);
    notGatePixels.append(outputWire);

    this->painter.end();
}
