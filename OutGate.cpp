#include "OutGate.h"

OutGate::OutGate(int x, int y) : Gate(x, y) { this->type = GateType::OUTPUT; }

OutGate::~OutGate() = default;

GateType OutGate::getType() const { return this->type; }

void OutGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::black);
  painter.setPen(cursorPen);

  // Get the center of the gate.
  QPoint center(pos_x, pos_y);

  // Draw gate based on agreed shape.
  for (int i = pos_y - 1; i <= pos_y + 1; i++) {
    for (int j = pos_x - 1; j <= pos_x + 1; j++) {
      QPoint border(j, i);
      painter.drawPoint(border);
      outGatePixels.append(border);
    }
  }
  cursorPen.setColor(Qt::red);
  painter.setPen(cursorPen);
  painter.drawPoint(center);

  // Draw the input wire.
  QPoint wire(pos_x - 2, pos_y);
  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);
  painter.drawPoint(wire);
  outGatePixels.append(wire);

  this->painter.end();
}

QPoint OutGate::getInput() { return QPoint(pos_x - 2, pos_y); }
