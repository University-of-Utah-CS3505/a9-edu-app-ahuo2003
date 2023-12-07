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
    Gate* andGate1;

    Gate* notGate2;
    Gate* input31;
    Gate* input32;
    Gate* input33;
    Gate* out31;
    Gate* andGate2;
    Gate* andGate3;

    Gate* notGate4;
    Gate* notGate5;
    Gate* notGate6;
    Gate* input41;
    Gate* input42;
    Gate* input43;
    Gate* input44;
    Gate* out41;
    Gate* orGate1;
    Gate* andGate4;
    Gate* andGate5;

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
        notGate1 = new NotGate(7, 1);
        gates.append(notGate1);
        input21 = new InGate(1,1);
        gates.append(input21);
        input22 = new InGate(1,5);
        gates.append(input22);
        out21 = new OutGate(25, 3);
        gates.append(out21);
        andGate1 = new AndGate(15, 3);
        gates.append(andGate1);
        break;

    case 5:
        notGate2 = new NotGate(6, 1);
        gates.append(notGate2);
        input31 = new InGate(1,1);
        gates.append(input31);
        input32 = new InGate(1,5);
        gates.append(input32);
        input33 = new InGate(1,9);
        gates.append(input33);
        out31 = new OutGate(30, 5);
        gates.append(out31);
        andGate2 = new AndGate(12, 3);
        gates.append(andGate2);
        andGate3 = new AndGate(22, 5);
        gates.append(andGate3);
        break;
    case 6:
        notGate4 = new NotGate(6, 1);
        gates.append(notGate4);
        notGate5 = new NotGate(6, 9);
        gates.append(notGate5);
        notGate6 = new NotGate(24, 7);
        gates.append(notGate6);
        input41 = new InGate(1,1);
        gates.append(input41);
        input42 = new InGate(1,5);
        gates.append(input42);
        input43 = new InGate(1,9);
        gates.append(input43);
        input44 = new InGate(1,13);
        gates.append(input44);
        out41 = new OutGate(31, 7);
        gates.append(out41);
        andGate4 = new AndGate(12, 3);
        gates.append(andGate4);
        andGate5 = new AndGate(18, 7);
        gates.append(andGate5);
        orGate1 = new OrGate(12, 11);
        gates.append(orGate1);
        break;
    }
}

