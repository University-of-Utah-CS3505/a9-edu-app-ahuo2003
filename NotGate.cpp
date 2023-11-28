#include "NotGate.h"

void NotGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void NotGate::draw(QImage &image) {}
