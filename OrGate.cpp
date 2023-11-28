#include "OrGate.h"

void OrGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void OrGate::draw(QImage &image) {

}
