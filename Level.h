#ifndef LEVEL_H
#define LEVEL_H

#include "Gate.h"

class Level {
public:
  Level();
  ~Level();

private:
  QList<Gate *> gates;
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

  friend class Model;
};

#endif // LEVEL_H
