#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

class AndGate : public Gate {


public:
  AndGate(int x, int y);
  ~AndGate() override;
  QList<QPoint> andGatePixels;
  /**
   * @brief draw Draws the InGate Object
   */
  void draw(QImage &image) override;

  GateType getType() const override;
};

#endif // ANDGATE_H
