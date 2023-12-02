#include "NotGate.h"

void Gate::setPos(int pos_x, int pos_y){
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void Gate::setTruthValue(bool val){
    this->truth = val;
}
void Gate::setCableColor(const QColor &color){
    this->cableColor = color;
}

QPoint Gate::getPos() const{
    QPoint pos(this->pos_x, this->pos_y);
    return pos;
}

bool Gate::getTruthValue() const{
    return this->truth;
}

QColor Gate::getCableColor() const{
    return this->cableColor;
}

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
  painter.drawPoint(top);
  notGatePixels.append(bottom);

  QPoint right(center.x() + 1, center.y());
  painter.drawPoint(top);
  notGatePixels.append(right);

  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);

  QPoint inputWire(center.x() - 1, center.y());
  painter.drawPoint(inputWire);
  notGatePixels.append(inputWire);

  QPoint outputWire(center.x() + 2, center.y());
  painter.drawPoint(outputWire);
  notGatePixels.append(outputWire);
}
