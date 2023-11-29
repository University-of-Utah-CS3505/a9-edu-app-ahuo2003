#ifndef INGATE_H
#define INGATE_H

#include "Gate.h"
#include <QMouseEvent>

class InGate : public Gate {
  InGate();

public:
  QList<QPoint> inGatePixels;
  /**
   * @brief getPosition
   * @param pos_x
   * @param pos_y
   */
  void virtual getPosition(int pos_x, int pos_y);

  /**
   * @brief draw Draws the InGate Object
   */
  void virtual draw(QImage &image);

  void mousePressed(QMouseEvent *event, QPoint center);
};

#endif // INGATE_H
