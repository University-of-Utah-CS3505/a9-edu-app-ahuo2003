#ifndef LEVEL_H
#define LEVEL_H

#include "Gate.h"

class Level {
public:
  Level();
  ~Level();
  void addGate(Gate *gate, int x, int y);
  void renderLevel(QImage &image);
  void loadLevelData(int levelNumber);

private:
  QList<Gate*> gates;
};

#endif // LEVEL_H
