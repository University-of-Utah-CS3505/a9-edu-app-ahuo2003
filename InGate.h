#ifndef INGATE_H
#define INGATE_H

#include "Gate.h"

class InGate : public Gate {
public:
  /**
   * @brief InGate The constructor for an InGate Object
   * @param pos_x The x position of the center
   * @param pox_y The y position of the center
   */
  InGate(int pos_x, int pox_y);

  /**
   * @brief draw Draws the InGate Object
   */
  void virtual draw(QImage &image);
};

#endif // INGATE_H
