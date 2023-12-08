#include "InGate.h"

InGate::InGate(int x, int y, QColor cableColor) : Gate(x, y) {
  this->cableColor = cableColor;
  this->type = GateType::INPUT;
  this->output = Cable(QPoint(x + 2, y), cableColor);
}

InGate::~InGate() = default;

GateType InGate::getType() const { return this->type; }

bool InGate::computeTruthValue() const
{
  return getTruthValue();
}

void InGate::draw(QImage &image) {
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
      inGatePixels.append(border);
    }
  }
  cursorPen.setColor(Qt::red);
  painter.setPen(cursorPen);
  painter.drawPoint(center);

  // Draw the output wire.
  QPoint wire(pos_x + 2, pos_y);
  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);
  painter.drawPoint(wire);
  inGatePixels.append(wire);

  this->painter.end();
}
