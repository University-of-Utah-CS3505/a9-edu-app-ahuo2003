#include "OrGate.h"

void OrGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
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
  QPoint outputWire(pos_x + 3, pos_y);
  painter.setPen(cursorPen);
  painter.drawPoint(outputWire);
  orGatePixels.append(outputWire);

  QPoint inputWire1(pos_x - 2, pos_y - 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire1);
  orGatePixels.append(inputWire1);

  QPoint inputWire2(pos_x - 2, pos_y + 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire2);
  orGatePixels.append(inputWire2);

  this->painter.end();
}
