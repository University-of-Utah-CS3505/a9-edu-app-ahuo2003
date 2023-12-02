#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"

class NotGate : public Gate {
  NotGate() : Gate() { type = GateType::NOT; }

public:
  QList<QPoint> notGatePixels;
  virtual GateType getType() const;

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // NOTGATE_H
