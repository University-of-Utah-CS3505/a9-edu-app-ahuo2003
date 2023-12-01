#ifndef GATE_H
#define GATE_H

#include <QColor>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QList>

enum class GateType {AND, OR, NOT, INPUT, OUTPUT};

class Gate {
public:
    Gate(int x = 0, int y = 0, bool initialState = false);
    virtual ~Gate();

    //Setters
    void setPos(int x, int y);
    void setTruthValue(bool val);
    void setCableColor(const QColor &color);

    // Getters
    void getPos(int &x, int &y) const;
    bool getTruthValue() const;
    QColor getCableColor() const;

    virtual GateType getType() const = 0; //To be implemented in child classes

    virtual void draw(QImage &image);
protected:
  int pos_x;
  int pos_y;
  bool truth;
  QColor cableColor;
  QPainter painter;
};

#endif // GATE_H
