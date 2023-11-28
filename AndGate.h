#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

class AndGate : public Gate {
public:
  /**
   * @brief AndGate
   * @param pos_x
   * @param pos_y
   */
  AndGate(int pos_x, int pos_y);

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // ANDGATE_H
