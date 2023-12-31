#ifndef INGATE_H
#define INGATE_H

#include "Gate.h"
#include <QMouseEvent>

/**
 * @brief The InGate class provide a visible input gate using QPoint
 * to draw it onto the canvas. the class also provide logic between
 * input gate and cable.
 */
class InGate : public Gate {
public:
  InGate(int x, int y, bool truthValue, QColor cableColor);
  ~InGate() override;
  QList<QPoint> inGatePixels;
  /**
   * @brief draw the method draw the input gate onto the canvas.
   * @param image the canvas to draw onto.
   */
  void draw(QImage &image) override;

  /**
   * @brief getType get the type of the gate.
   * @return GateType::INPUT.
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

#endif // INGATE_H
