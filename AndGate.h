#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

class AndGate : public Gate {


public:
  AndGate(int x, int y);
  QList<QPoint> andGatePixels;
  /**
   * @brief draw Draws the InGate Object
   */
  void virtual draw(QImage &image);

  virtual GateType getType() const;
};

#endif // ANDGATE_H
