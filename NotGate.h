#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"

class NotGate : public Gate {
public:
  /**
   * @brief NotGate
   * @param pos_x
   * @param pos_y
   */
  NotGate(int pos_x, int pos_y);

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // NOTGATE_H
