#ifndef OUTGATE_H
#define OUTGATE_H

#include "Gate.h"

class OutGate : public Gate {

public:
    OutGate(int x, int y);
    ~OutGate() override;
    QList<QPoint> outGatePixels;

    void draw(QImage &image) override;

    GateType getType() const override;
};

#endif // OUTGATE_H
