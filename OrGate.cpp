#include "OrGate.h"

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

GateType OrGate::getType() const{
    return this->type;
}

void OrGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::blue);
  painter.setPen(cursorPen);

  QPoint center(pos_x, pos_y);
  painter.drawPoint(center);
  orGatePixels.append(center);

  for (int i = center.y() - 1; i <= center.y() + 1; i++) {
    for (int j = center.x(); j <= center.x() + 1; j++) {
      QPoint orGate(j, i);
      painter.drawPoint(orGate);
      orGatePixels.append(orGate);
    }
  }

  for (int i = center.y()-2; i <= center.y()+2; i++){
    if (i != center.y()) {
      QPoint orGate(center.x()-1, i);
      painter.drawPoint(orGate);
      orGatePixels.append(orGate);
    }
  }

  QPoint right(center.x()+2, center.y());
  painter.drawPoint(right);
  orGatePixels.append(right);

  cursorPen.setColor(Qt::yellow);
  QPoint outputWire(center.x() + 3, center.y());
  painter.setPen(cursorPen);
  painter.drawPoint(outputWire);
  orGatePixels.append(outputWire);

  QPoint inputWire1(center.x() - 2, center.y() - 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire1);
  orGatePixels.append(inputWire1);

  QPoint inputWire2(center.x() - 2, center.y() + 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire2);
  orGatePixels.append(inputWire2);

  this->painter.end();
}
