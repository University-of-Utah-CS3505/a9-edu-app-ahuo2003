#ifndef OUTGATE_H
#define OUTGATE_H

#include "Gate.h"

class OutGate : public Gate {
  OutGate();

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

#endif // OUTGATE_H
