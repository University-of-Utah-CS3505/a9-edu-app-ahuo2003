#ifndef GATE_H
#define GATE_H

#include <QColor>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QList>

class Gate {
protected:
  /**
   * @brief getPosition
   * @param pos_x
   * @param pos_y
   */
  void virtual getPosition(int pos_x, int pos_y);

  /**
   * @brief draw
   * @param image
   */
  void virtual draw(QImage &image);

  int pos_x;
  int pos_y;
  bool truth;
  QColor cableColor;
  QPainter painter;
};

#endif // GATE_H
