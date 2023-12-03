#include "Gate.h"

Gate::Gate(int x, int y) : pos_x(x), pos_y(y) {}


void Gate::setPos(int pos_x, int pos_y){
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void Gate::setTruthValue(bool val){
    this->truth = val;
}
void Gate::setCableColor(const QColor &color){
    this->cableColor = color;
}

QPoint Gate::getPos() const{
    QPoint pos(this->pos_x, this->pos_y);
    return pos;
}

bool Gate::getTruthValue() const{
    return this->truth;
}

QColor Gate::getCableColor() const{
    return this->cableColor;
}
