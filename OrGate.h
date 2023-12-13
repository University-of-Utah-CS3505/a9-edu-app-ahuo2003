#ifndef ORGATE_H
#define ORGATE_H

#include "Gate.h"

/**
 * @brief The OrGate class provide a visible OR gate using QPoint
 * to draw it onto the canvas. the class also provide logic between
 * OR gate and cable.
 */
class OrGate : public Gate {
public:
  OrGate(int x, int y);
  ~OrGate() override;
  QList<QPoint> orGatePixels;
  /**
   * @brief draw the method draw the OR gate onto the canvas.
   * @param image the canvas to draw onto.
   */
  void draw(QImage &image) override;

  /**
   * @brief getInput1 get the first input wire of the OR gate.
   * @return the position(x,y) of the first input wire.
   */
  QPoint getInput1();

  /**
   * @brief getInput2 get the second input wire of the OR gate.
   * @return the position(x,y) of the second input wire.
   */
  QPoint getInput2();

  /**
   * @brief getType get the type of the gate.
   * @return GateType::OR.
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

#endif // ORGATE_H
