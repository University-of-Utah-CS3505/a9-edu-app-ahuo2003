#include "NotGate.h"

NotGate::NotGate(int x, int y) : Gate(x, y) {
  this->type = GateType::NOT;
  this->cableColor = Qt::red;
  this->truth = false;
  this->output = Cable(QPoint(x + 2, y), cableColor);
}

NotGate::~NotGate() = default;

GateType NotGate::getType() const { return this->type; }

bool NotGate::computeTruthValue() const
{
  if(inputGates.isEmpty()) return false;
  return !inputGates.front()->getTruthValue();
}

bool NotGate::isConnected() const
{
  return !(inputGates.isEmpty());
}

void NotGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  QColor color(Qt::red);
  cursorPen.setColor(color.darker(120));
  painter.setPen(cursorPen);

  // Get and draw the center of the gate.
  QPoint center(pos_x, pos_y);
  painter.drawPoint(center);
  notGatePixels.append(center);

  // Draw gate based on agreed shape.
  QPoint top(pos_x, pos_y + 1);
  painter.drawPoint(top);
  notGatePixels.append(top);

  QPoint bottom(pos_x, pos_y - 1);
  painter.drawPoint(bottom);
  notGatePixels.append(bottom);

  QPoint right(pos_x + 1, pos_y);
  painter.drawPoint(right);
  notGatePixels.append(right);

  cursorPen.setColor(Qt::yellow);
  painter.setPen(cursorPen);

  // Draw the input wire.
  QPoint inputWire(pos_x - 1, pos_y);
  painter.drawPoint(inputWire);
  notGatePixels.append(inputWire);

  // Draw the output wire.
  QPoint outputWire(pos_x + 2, pos_y);
  painter.drawPoint(outputWire);
  notGatePixels.append(outputWire);

  this->painter.end();
}

QPoint NotGate::getInput() { return QPoint(pos_x - 1, pos_y); }
