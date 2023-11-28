#ifndef OUTGATE_H
#define OUTGATE_H
#include "Gate.h"


class OutGate : public Gate
{
public:
    OutGate(int pos_x, int pos_y);
    void virtual draw();
};

#endif // OUTGATE_H
