#include "Level.h"
#include "AndGate.h"
#include "InGate.h"
#include "OutGate.h"
#include "OrGate.h"
#include "NotGate.h"

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
        Gate* andGate = new AndGate(15, 10);
        gates.append(andGate);
        Gate* input1 = new InGate(5,5);
        gates.append(input1);
        Gate* input2 = new InGate(5,15);
        gates.append(input2);
        Gate* out = new OutGate(30,10);
        gates.append(out);
    }
}
