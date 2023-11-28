#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"

class NotGate : public Gate
{
public:
    NotGate(int pos_x, int pos_y);
    void virtual draw();
};

#endif // NOTGATE_H
