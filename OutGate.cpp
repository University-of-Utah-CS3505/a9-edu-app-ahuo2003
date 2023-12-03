#include "OutGate.h"

OutGate::OutGate(int x, int y) : Gate(x,y){ this->type = GateType::OUTPUT; };

GateType OutGate::getType() const{
    return this->type;
}

void OutGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::black);
  painter.setPen(cursorPen);

  QPoint center(pos_x, pos_y);
  for (int i = center.y() - 1; i <= center.y() + 1; i++) {
    for (int j = center.x() - 1; j <= center.x() + 1; j++) {
      QPoint border(j, i);
      painter.drawPoint(border);
      outGatePixels.append(border);
    }
  }
  cursorPen.setColor(Qt::red);
  painter.setPen(cursorPen);
  painter.drawPoint(center);

  QPoint wire(center.x() - 2, center.y());
  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);
  painter.drawPoint(wire);
  outGatePixels.append(wire);

  this->painter.end();
}
