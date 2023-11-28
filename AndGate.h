#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

class AndGate : public Gate {
  AndGate();

public:
  /**
   * @brief getPosition
   * @param pos_x
   * @param pos_y
   */
  void virtual getPosition(int pos_x, int pos_y);

  /**
   * @brief draw Draws the InGate Object
   */
  void virtual draw(QImage &image);
};

#endif // ANDGATE_H
