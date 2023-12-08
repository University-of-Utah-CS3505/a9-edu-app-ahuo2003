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
  void checkConnections();
  void checkDualInput(Gate* inGate, Gate* andOrGate, const QPoint& input1Pos, const QPoint& input2Pos);
  void checkSingleInput(Gate* inGate, Gate* notOutGate, const QPoint& inputPos);
  void refreshTruthValues();


  friend class Model; 
};

#endif // LEVEL_H
