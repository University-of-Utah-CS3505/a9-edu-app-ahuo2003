#ifndef GATE_H
#define GATE_H

#include "Cable.h"
#include <QColor>
#include <QImage>
#include <QList>
#include <QPainter>
#include <QPoint>

enum class GateType { AND, OR, NOT, INPUT, OUTPUT };

/**
 * @brief The Gate class the interface class for five different gate
 * which is input, output, AND, NOT and OR gates.
 */
class Gate {
public:
  Gate(int x = 0, int y = 0);
  virtual ~Gate();

  /**
   * @brief setPos set the position(x,y) of the gate onto the canvas.
   * @param x x-coordinate.
   * @param y y-coordinate.
   */
  void setPos(int x, int y);

  /**
   * @brief setTruthValue set the output of the gate based on the input(true or false).
   * @param val true or false output
   */
  void setTruthValue(bool val);

  /**
   * @brief setCableColor set the color of the color based on the truth value.
   * @param color red(false) or green(true) color for cables.
   */
  void setCableColor(const QColor &color);

  /**
   * @brief getPos get the position of the gate.
   * @return the position of the gate.
   */
  QPoint getPos() const;

  /**
   * @brief getTruthValue get the truth value of the output of the gate.
   * @return true of false depends on the output.
   */
  bool getTruthValue() const;

  /**
   * @brief getCableColor get the color of the cables for other operations.
   * @return the color of the current cable from the gate.
   */
  QColor getCableColor() const;

  /**
   * @brief getCable get the cable for extending or deleting the current cable.
   * @return the position of the cable.
   */
  Cable *getCable();

  /**
   * @brief getType interface getType for gates.
   * @return the gate type.
   */
  virtual GateType
  getType() const = 0; // Pure virtual, no need implementation in Gate.cpp

  /**
   * @brief draw interface draw method for gates.
   * @param image the canvas to draw onto.
   */
  virtual void
  draw(QImage &image) = 0; // Pure virtual, no need implementation in Gate.cpp

  /**
   * @brief computeTruthValue computes the truth value of the gate
   * @return the truth value, as either a true/false bool
   */
  virtual bool computeTruthValue() const = 0;

  /**
   * @brief isConnected checks to see if the gate is connected
   * @return the connection status, as either a true/false bool
   */
  virtual bool isConnected() const = 0;

  /**
   * @brief addInputGate adds an input gate
   * @param gate a pointer to the added gate
   */
  void addInputGate(Gate* gate);

  /**
   * @brief removeInputGate removes input gate
   * @param input a pointer to the removed gate
   */
  void removeInputGate(Gate* input);

  /**
   * @brief getInputGates returns a list of input gates
   * @return a QList of input gates
   */
  const QList<Gate*>& getInputGates();

  /**
   * @brief setInputGates sets a list of input gates
   * @param input a QList of input gates
   */
  void setInputGates(QList<Gate*>& input);


protected:
  int pos_x;
  int pos_y;
  bool truth;
  QColor cableColor;
  QPainter painter;
  GateType type;
  Cable output;
  QList<Gate*> inputGates;
};

#endif // GATE_H
