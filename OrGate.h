#ifndef ORGATE_H
#define ORGATE_H

#include "Gate.h"

class OrGate : public Gate {

public:
    OrGate(int x, int y);
    ~OrGate() override;
    QList<QPoint> orGatePixels;

    void draw(QImage &image) override;

    GateType getType() const override;
};

#endif // ORGATE_H
