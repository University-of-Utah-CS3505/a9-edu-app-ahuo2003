#include "TrackerWidget.h"
#include "qpainter.h"

TrackerWidget::TrackerWidget(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this)
{
    //    colors.append(Qt::white);
    //    colors.append(Qt::black);
    colors.append(Qt::red);
    colors.append(Qt::darkRed);
    colors.append(Qt::green);
    colors.append(Qt::darkGreen);
    //    colors.append(Qt::blue);
    //    colors.append(Qt::darkBlue);
    colors.append(Qt::cyan);
    colors.append(Qt::darkCyan);
    //    colors.append(Qt::magenta);
    //    colors.append(Qt::darkMagenta);
    //    colors.append(Qt::yellow);
    //    colors.append(Qt::darkYellow);
    //    colors.append(Qt::gray);
    //    colors.append(Qt::lightGray);
    //    colors.append(Qt::darkGray);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(600.0f, 80.0f);

    b2BodyDef leftWallDef;
    leftWallDef.position.Set(0.0f, 45.0f);

    b2BodyDef rightWallDef;
    rightWallDef.position.Set(1200.0f, 45.0f);

    b2BodyDef roofBodyDef;
    roofBodyDef.position.Set(600.0f, 10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world.CreateBody(&groundBodyDef);
    leftWallBody = world.CreateBody(&leftWallDef);
    rightWallBody = world.CreateBody(&rightWallDef);
    roofBody = world.CreateBody(&roofBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;
    b2PolygonShape leftWallBox;
    b2PolygonShape rightWallBox;
    b2PolygonShape roofBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(620.0f, 4.0f);
    leftWallBox.SetAsBox(2.0f, 45.0f);
    rightWallBox.SetAsBox(2.0f, 45.0f);
    roofBox.SetAsBox(620.0f, 4.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);
    roofBody->CreateFixture(&roofBox, 0.0f);

    connect(&timer, &QTimer::timeout, this, &TrackerWidget::updateWorld);
    timer.start(10);
}

void TrackerWidget::createBouncingBox(float x, float y, float w, float h, float d, float f, float r){
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w, h);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = d;
    fixtureDef.friction = f;
    fixtureDef.restitution = r;
    body->CreateFixture(&fixtureDef);

    bodyList.append(body);
}

void TrackerWidget::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);

    for ( b2Body* b : bodyList)
    {
        b2Vec2 position = b->GetPosition();
        int color = std::rand() % 6;
        painter.setPen(colors.at(color));
        painter.drawRect((int)(position.x), (int)(position.y), 8, 8);
    }

    painter.end();
}

void TrackerWidget::updateWorld() {
    // It is generally best to keep the time step and iterations fixed.
    world.Step(1.0/60.0, 6, 2);
    update();
}
