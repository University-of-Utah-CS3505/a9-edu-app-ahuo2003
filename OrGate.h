#ifndef ORGATE_H
#define ORGATE_H
#include "Gate.h"

class OrGate : public Gate
{
public:
    OrGate(int pos_x, int pos_y);
    void virtual draw();
};

#endif // ORGATE_H
