#ifndef OUTGATE_H
#define OUTGATE_H

#include "Gate.h"

class OutGate : public Gate {
  OutGate() : Gate() { type = GateType::OUTPUT; }

public:
  QList<QPoint> outGatePixels;

  virtual GateType getType() const;

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);
};

#endif // OUTGATE_H
