#include "InGate.h"

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

GateType InGate::getType() const{
    return this->type;
}

void InGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::black);
  painter.setPen(cursorPen);

  QPoint center(pos_x, pos_y);
  for (int i = center.y() - 1; i <= center.y() + 1; i++) {
    for (int j = center.x() - 1; j <= center.x() + 1; j++) {
      QPoint border(j, i);
      painter.drawPoint(border);
      inGatePixels.append(border);
    }
  }
  cursorPen.setColor(Qt::red);
  painter.setPen(cursorPen);
  painter.drawPoint(center);

  QPoint wire(center.x() + 2, center.y());
  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);
  painter.drawPoint(wire);
  inGatePixels.append(wire);

  this->painter.end();
}

void InGate::mousePressed(QMouseEvent *event, QPoint center)
{
  center.setX(pos_x);
  center.setY(pos_y);
  if(event->button() == Qt::LeftButton)
  {

  }
}
