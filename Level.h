#ifndef LEVEL_H
#define LEVEL_H

#include "Gate.h"

class Level {
public:
  Level();
  ~Level();

private:
  QList<Gate*> gates;
  QMap<Gate*, QList<Gate*>> connections;
  bool currOutput;
  bool winCondition;

  /**
   * @brief addGate TODO
   * @param gate TODO
   * @param x TODO
   * @param y TODO
   */
  void addGate(Gate *gate, int x, int y);

  /**
   * @brief renderLevel TODO
   * @param image TODO
   */
  void renderLevel(QImage &image);

  /**
   * @brief loadLevelData TODO
   * @param levelNumber TODO
   */
  void loadLevelData(int levelNumber);

  void connectGates(Gate* output, Gate* input);
  void disconnectGates(Gate* gate, Gate* input);
  void checkConnections();
  void updateGateConnections(Gate* gate, QList<Gate*>& connectedInputs);
  void checkAndAddInput(Gate* inGate, Gate* gate, const QPoint& inputPos, QList<Gate*>& connectedInputs);
  void refreshTruthValues();


  friend class Model; 
};

#endif // LEVEL_H
