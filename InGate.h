#ifndef INGATE_H
#define INGATE_H

#include "Gate.h"
#include <QMouseEvent>

class InGate : public Gate {

public:
    InGate(int x, int y);
    ~InGate() override;
    QList<QPoint> inGatePixels;

    /**
   * @brief draw Draws the InGate Object
   */
    void draw(QImage &image) override;

    GateType getType() const override;

    void mousePressed(QMouseEvent *event, QPoint center);
};

#endif // INGATE_H
