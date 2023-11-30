#include "AndGate.h"

void AndGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void AndGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::green);
  painter.setPen(cursorPen);

  QPoint center(pos_x, pos_y);
  for (int i = center.y() - 2; i <= center.y() + 2; i++) {
    for (int j = center.x() - 1; j <= center.x() + 1; j++) {
      QPoint andGate(j, i);
      painter.drawPoint(andGate);
      andGatePixels.append(andGate);
    }
  }

  for (int i = center.y() - 1; i <= center.y() + 1; i++) {
    for (int j = center.x() + 1; j <= center.x() + 2; j++) {
      QPoint andGate(j, i);
      painter.drawPoint(andGate);
      andGatePixels.append(andGate);
    }
  }

  cursorPen.setColor(Qt::yellow);
  QPoint outputWire(center.x() + 3, center.y());
  painter.setPen(cursorPen);
  painter.drawPoint(outputWire);
  andGatePixels.append(outputWire);

  QPoint inputWire1(center.x() - 2, center.y() - 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire1);
  andGatePixels.append(inputWire1);

  QPoint inputWire2(center.x() - 2, center.y() + 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire2);
  andGatePixels.append(inputWire2);

  this->painter.end();
}
