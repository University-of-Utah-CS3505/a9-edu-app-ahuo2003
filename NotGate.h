#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"

/**
 * @brief The NotGate class provide a visible NOT gate using QPoint
 * to draw it onto the canvas. the class also provide logic between
 * NOT gate and cable.
 */
class NotGate : public Gate {
public:
  NotGate(int x, int y);
  ~NotGate() override;
  QList<QPoint> notGatePixels;
  /**
   * @brief draw the method draw the NOT gate onto the canvas.
   * @param image the canvas to draw onto.
   */
  void draw(QImage &image) override;

  /**
   * @brief getInput get the input wire of the NOT gate.
   * @return the position(x,y) of the input wire.
   */
  QPoint getInput();

  /**
   * @brief getType get the type of the gate.
   * @return GateType::NOT.
   */
  GateType getType() const override;

  /**
   * @brief computeTruthValue compute the value of the gate
   * @return the gate value, as a true/false variable.
   */
  bool computeTruthValue() const override;

  /**
   * @brief isConnected checks to see if the gate is connected
   * @return the connection status, as a true/false variable.
   */
  bool isConnected() const override;
};

#endif // NOTGATE_H
