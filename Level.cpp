#include "Level.h"
#include "AndGate.h"
#include "InGate.h"

Level::Level()
{

}

Level::~Level()
{
    qDeleteAll(gates);
    gates.clear();
}

void Level::addGate(Gate* gate, int x, int y)
{
    gate->setPos(x,y);
    gates.append(gate);
}

void Level::renderLevel(QImage &image)
{
    for (Gate* gate: gates) gate->draw(image);
}

void Level::loadLevelData(int levelNumber)
{
    gates.clear();
    switch (levelNumber) {
    case 1:
        Gate* andGate = new InGate(5, 5);
        gates.append(andGate);
    }
}
