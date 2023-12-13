#ifndef LEVEL_H
#define LEVEL_H

#include "Gate.h"

class Level {
public:
  /**
  * @brief Level Constructor for the level class
  */
  Level();
  ~Level();

private:
  QList<Gate*> gates;
  QMap<Gate*, QList<Gate*>> connections;
  bool currOutput;
  bool winCondition;

  /**
   * @brief addGate adds a gate to the level.
   * @param gate a logic gate.
   * @param x horizontal position of the gate.
   * @param y vertical position of the gate.
   */
  void addGate(Gate *gate, int x, int y);

  /**
   * @brief renderLevel renders the level into the QImage.
   * @param image the image where the level will be rendered into.
   */
  void renderLevel(QImage &image);

  /**
   * @brief loadLevelData loads the data of the level based on its identifier.
   * @param levelNumber the level identifier.
   */
  void loadLevelData(int levelNumber);

  /**
   * @brief connectGates connects 2 gates given a cable.
   * @param output where the gate's cable originates from.
   * @param input where another gate's cable connects.
   */
  void connectGates(Gate* output, Gate* input);

  /**
   * @brief disconnectGates disconnects an input slot from a gate.
   * @param gate a logic gate.
   * @param input the input slot from the gate.
   */
  void disconnectGates(Gate* gate, Gate* input);

  /**
   * @brief checkConnections checks the connections in the level.
   */
  void checkConnections();

  /**
   * @brief updateGateConnections updates the connections of the gate given.
   * @param gate a logic gate.
   * @param connectedInputs its input slots (2 for AND/OR, 1 for NOT/OUT gates).
   */
  void updateGateConnections(Gate* gate, QList<Gate*>& connectedInputs);

  /**
   * @brief checkAndAddInput checks the input, and adds it if possible.
   * @param inGate the gate that is attempting to connect into another gate.
   * @param gate the gate that is receiving a connection.
   * @param inputPos the position of the input slot of the gate.
   * @param connectedInputs list of the connected slots of the gate.
   */
  void checkAndAddInput(Gate* inGate, Gate* gate, const QPoint& inputPos, QList<Gate*>& connectedInputs);

  /**
   * @brief refreshTruthValues refreshes the output signal of all gates from its inputs.
   */
  void refreshTruthValues();


  friend class Model; 
};

#endif // LEVEL_H
