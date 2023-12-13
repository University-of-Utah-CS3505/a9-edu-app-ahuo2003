#include "OrGate.h"

OrGate::OrGate(int x, int y) : Gate(x, y) {
  this->type = GateType::OR;
  this->cableColor = Qt::red;
  this->truth = false;
  this->output = Cable(QPoint(x + 3, y), cableColor);
}

OrGate::~OrGate() = default;

GateType OrGate::getType() const { return this->type; }

bool OrGate::computeTruthValue() const {
  if (inputGates.isEmpty())
    return false;
  if (inputGates.size() == 1)
    return false;
  for (Gate *inputGate : inputGates) {
    if (inputGate->getTruthValue())
      return true;
  }
  return false;
}

bool OrGate::isConnected() const { return (inputGates.size() == 2); }

void OrGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::blue);
  painter.setPen(cursorPen);

  // Get and draw the center of the gate.
  QPoint center(pos_x, pos_y);
  painter.drawPoint(center);
  orGatePixels.append(center);

  // Draw gate based on agreed shape.
  for (int i = pos_y - 1; i <= pos_y + 1; i++) {
    for (int j = center.x(); j <= center.x() + 1; j++) {
      QPoint orGate(j, i);
      painter.drawPoint(orGate);
      orGatePixels.append(orGate);
    }
  }

  for (int i = pos_y - 2; i <= pos_y + 2; i++) {
    if (i != center.y()) {
      QPoint orGate(pos_x - 1, i);
      painter.drawPoint(orGate);
      orGatePixels.append(orGate);
    }
  }

  QPoint right(pos_x + 2, pos_y);
  painter.drawPoint(right);
  orGatePixels.append(right);

  cursorPen.setColor(Qt::yellow);

  // Draw ouput wire.
  QPoint outputWire(pos_x + 3, pos_y);
  painter.setPen(cursorPen);
  painter.drawPoint(outputWire);
  orGatePixels.append(outputWire);

  // Draw the first input wire.
  QPoint inputWire1(pos_x - 2, pos_y - 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire1);
  orGatePixels.append(inputWire1);

  // Draw the second input wire.
  QPoint inputWire2(pos_x - 2, pos_y + 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire2);
  orGatePixels.append(inputWire2);

  this->painter.end();
}

QPoint OrGate::getInput1() { return QPoint(pos_x - 2, pos_y - 1); }

QPoint OrGate::getInput2() { return QPoint(pos_x - 2, pos_y + 1); }
