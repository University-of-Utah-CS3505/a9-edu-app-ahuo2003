#ifndef ORGATE_H
#define ORGATE_H

#include "Gate.h"

class OrGate : public Gate {
  OrGate();

public:
  /**
   * @brief getPosition
   * @param pos_x
   * @param pos_y
   */
  void virtual getPosition(int pos_x, int pos_y);

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // ORGATE_H
