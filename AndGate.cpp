#include "AndGate.h"

void AndGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void AndGate::draw(QImage &image) {

}
