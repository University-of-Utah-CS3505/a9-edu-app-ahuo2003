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

    // Declare the variables outside the switch
    Gate* andGate;
    Gate* input1;
    Gate* input2;
    Gate* out;

    Gate* orGate;
    Gate* input01;
    Gate* input02;
    Gate* out01;

    Gate* notGate;
    Gate* input11;
    Gate* input12;
    Gate* out11;

    Gate* notGate1;
    Gate* input21;
    Gate* input22;
    Gate* out21;

    switch (levelNumber) {
    case 1:
        andGate = new AndGate(15, 10);
        gates.append(andGate);
        input1 = new InGate(5,5);
        gates.append(input1);
        input2 = new InGate(5,15);
        gates.append(input2);
        out = new OutGate(30,10);
        gates.append(out);
        break;

    case 2:
        orGate = new OrGate(15, 10);
        gates.append(orGate);
        input01 = new InGate(5,5);
        gates.append(input01);
        input02 = new InGate(5,15);
        gates.append(input02);
        out01 = new OutGate(30,10);
        gates.append(out01);
        break;

    case 3:
        notGate = new NotGate(15, 10);
        gates.append(notGate);
        input11 = new InGate(5,5);
        gates.append(input11);
        input12 = new InGate(5,15);
        gates.append(input12);
        out11 = new OutGate(30,10);
        gates.append(out11);
        break;

    case 4:
        notGate1 = new NotGate(20, 10);
        gates.append(notGate1);
        input21 = new InGate(0,0);
        gates.append(input21);
        input22 = new InGate(5,15);
        gates.append(input22);
        out21 = new OutGate(25,25);
        gates.append(out21);
        break;
    }
}

