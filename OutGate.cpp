#include "OutGate.h"

void OutGate::getPosition(int pos_x, int pos_y) {
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->truth = false;
}

void OutGate::draw(QImage &image) {

}
