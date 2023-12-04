#ifndef LEVEL_H
#define LEVEL_H

#include "Gate.h"

class Level {
public:
  Level();
  ~Level();

private:
  QList<Gate *> gates;
  void addGate(Gate *gate, int x, int y);
  void renderLevel(QImage &image);
  void loadLevelData(int levelNumber);

  friend class Model;
};

#endif // LEVEL_H
