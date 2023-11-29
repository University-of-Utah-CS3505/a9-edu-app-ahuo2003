#include "OutGate.h"

void OutGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void OutGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::black);
  painter.setPen(cursorPen);

  QPoint point(pos_x, pos_y);
  for (int i = point.y() - 1; i <= point.y() + 1; i++) {
    for (int j = point.x() - 1; j <= point.x() + 1; j++) {
      QPoint border(i, j);
      painter.drawPoint(border);
      outGatePixels.append(border);
    }
  }
  cursorPen.setColor(Qt::red);
  painter.setPen(cursorPen);
  painter.drawPoint(point);

  QPoint wire(pos_x - 2, pos_y);
  cursorPen.setColor(Qt::green);
  painter.setPen(cursorPen);
  painter.drawPoint(wire);
  outGatePixels.append(wire);
}
