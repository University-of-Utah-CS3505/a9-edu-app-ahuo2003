#include "Gate.h"

Gate::Gate(int x, int y) : pos_x(x), pos_y(y), output(QPoint(x, y), Qt::red) {}

Gate::~Gate() = default;

void Gate::setPos(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
}

void Gate::setTruthValue(bool val) { this->truth = val; }
void Gate::setCableColor(const QColor &color) {
  this->cableColor = color;
  this->getCable()->changeCableColor(color);
}

QPoint Gate::getPos() const {
  QPoint pos(this->pos_x, this->pos_y);
  return pos;
}

bool Gate::getTruthValue() const { return this->truth; }

QColor Gate::getCableColor() const { return this->cableColor; }

Cable *Gate::getCable() { return &(this->output); }

void Gate::addInputGate(Gate* gate)
{
  if(gate != nullptr) inputGates.append(gate);
}

void Gate::removeInputGate(Gate *input)
{
  inputGates.removeAll(input);
}

const QList<Gate *> &Gate::getInputGates()
{
  return inputGates;
}

void Gate::setInputGates(QList<Gate *> &input)
{
  inputGates = input;
}
