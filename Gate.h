#ifndef GATE_H
#define GATE_H
#include "Cable.h"
#include <QColor>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QList>

enum class GateType {AND, OR, NOT, INPUT, OUTPUT};

class Gate {
public:
    Gate(int x = 0, int y = 0);
    virtual ~Gate();

    //Setters
    void setPos(int x, int y);
    void setTruthValue(bool val);
    void setCableColor(const QColor &color);

    // Getters
    QPoint getPos() const;
    bool getTruthValue() const;
    QColor getCableColor() const;
    Cable* getCable();

    virtual GateType getType() const = 0; //Pure virtual, no need implementation in Gate.cpp

    virtual void draw(QImage &image) = 0; //Pure virtual, no need implementation in Gate.cpp
protected:
    int pos_x;
    int pos_y;
    bool truth;
    QColor cableColor;
    QPainter painter;
    GateType type;
    Cable output;
};

#endif // GATE_H
