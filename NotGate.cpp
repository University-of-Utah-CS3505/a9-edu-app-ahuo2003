#include "NotGate.h"

void NotGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
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
