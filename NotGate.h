#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"

class NotGate : public Gate {

public:
    NotGate(int x, int y);
    ~NotGate() override;
    QList<QPoint> notGatePixels;

    void draw(QImage &image) override;

    GateType getType() const override;
};

#endif // NOTGATE_H
