#ifndef ORGATE_H
#define ORGATE_H

#include "Gate.h"

class OrGate : public Gate {

public:
  OrGate(int x, int y);
  QList<QPoint> orGatePixels;
  virtual GateType getType() const;

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // ORGATE_H
