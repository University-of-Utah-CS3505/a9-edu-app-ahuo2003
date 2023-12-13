#ifndef OUTGATE_H
#define OUTGATE_H

#include "Gate.h"

/**
 * @brief The OutGate class provide a visible output gate using QPoint
 * to draw it onto the canvas. the class also provide logic between
 * output gate and cable.
 */
class OutGate : public Gate {
public:
  OutGate(int x, int y, bool truthValue);
  ~OutGate() override;
  QList<QPoint> outGatePixels;
  /**
   * @brief draw the method draw the ouput gate onto the canvas.
   * @param image the canvas to draw onto.
   */
  void draw(QImage &image) override;

  /**
   * @brief getInput get the input wire of the output gate.
   * @return the position(x,y) of the input wire.
   */
  QPoint getInput();

  /**
   * @brief getType get the type of the gate.
   * @return GateType::OUTPUT.
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

#endif // OUTGATE_H
