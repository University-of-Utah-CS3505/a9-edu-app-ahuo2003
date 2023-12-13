#include "AndGate.h"

AndGate::AndGate(int x, int y) : Gate(x, y) {
  this->type = GateType::AND;
  this->cableColor = Qt::red;
  this->truth = false;
  this->output = Cable(QPoint(x + 3, y), cableColor);
}

AndGate::~AndGate() = default;

GateType AndGate::getType() const { return this->type; }

bool AndGate::computeTruthValue() const {
  if (inputGates.isEmpty())
    return false;
  for (Gate *inputGate : inputGates) {
    if (!inputGate || !inputGate->getTruthValue())
      return false;
  }
  return true;
}

bool AndGate::isConnected() const { return (inputGates.size() == 2); }

void AndGate::draw(QImage &image) {
  this->painter.begin(&image);

  QPen cursorPen = painter.pen();
  cursorPen.setColor(Qt::darkGreen);
  painter.setPen(cursorPen);

  // Get the center of the gate
  QPoint center(pos_x, pos_y);

  // Draw gate based on agreed shapes.
  for (int i = pos_y - 2; i <= pos_y + 2; i++) {
    for (int j = pos_x - 1; j <= pos_x; j++) {
      QPoint andGate(j, i);
      painter.drawPoint(andGate);
      andGatePixels.append(andGate);
    }
  }

  for (int i = pos_y - 1; i <= pos_y + 1; i++) {
    for (int j = pos_x + 1; j <= pos_x + 2; j++) {
      QPoint andGate(j, i);
      painter.drawPoint(andGate);
      andGatePixels.append(andGate);
    }
  }

  cursorPen.setColor(Qt::yellow);

  // Draw the output wire
  QPoint outputWire(pos_x + 3, pos_y);
  painter.setPen(cursorPen);
  painter.drawPoint(outputWire);
  andGatePixels.append(outputWire);

  // Draw the first input wire
  QPoint inputWire1(pos_x - 2, pos_y - 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire1);
  andGatePixels.append(inputWire1);

  // Draw the second input wire
  QPoint inputWire2(pos_x - 2, pos_y + 1);
  painter.setPen(cursorPen);
  painter.drawPoint(inputWire2);
  andGatePixels.append(inputWire2);

  this->painter.end();
}

QPoint AndGate::getInput1() { return QPoint(pos_x - 2, pos_y - 1); }

QPoint AndGate::getInput2() { return QPoint(pos_x - 2, pos_y + 1); }
