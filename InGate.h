#ifndef INGATE_H
#define INGATE_H

#include "Gate.h"
#include <QMouseEvent>

class InGate : public Gate {
    InGate() : Gate(){
        type = GateType::INPUT;
    }

public:
  QList<QPoint> inGatePixels;

  /**
   * @brief draw Draws the InGate Object
   */
  void virtual draw(QImage &image);

  virtual GateType getType() const;

  void mousePressed(QMouseEvent *event, QPoint center);
};

#endif // INGATE_H
