#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

/**
 * @brief The AndGate class provide a visible AND gate using QPoint
 * to draw it onto the canvas. the class also provide logic between
 * AND gate and cable.
 */
class AndGate : public Gate {
public:
  AndGate(int x, int y);
  ~AndGate() override;
  QList<QPoint> andGatePixels;
  /**
   * @brief draw the method draw the AND gate onto the canvas.
   * @param image the canvas to draw onto.
   */
  void draw(QImage &image) override;

  /**
   * @brief getInput1 get the first input wire of the AND gate.
   * @return the position(x,y) of the first input wire.
   */
  QPoint getInput1();

  /**
   * @brief getInput2 get the second input wire of the AND gate.
   * @return the position(x,y) of the second input wire.
   */
  QPoint getInput2();

  /**
   * @brief getType get the type of the gate.
   * @return GateType::AND.
   */
  GateType getType() const override;

  bool computeTruthValue() const override;
};

#endif // ANDGATE_H
