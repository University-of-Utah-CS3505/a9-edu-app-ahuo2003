#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Canvas &canvas, Model &model, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->show();
    //ui->testStart->

    // Default window size of 1280x720 (non-resizable)
    this->setFixedSize(1280, 720);

    // Draw the canvas
    initCanvas();

    QPixmap pixmap(":/title.png");
    QIcon ButtonIcon(pixmap);
    ui->testStart->setIcon(ButtonIcon);
    ui->testStart->setIconSize(pixmap.rect().size());

    connect(ui->circuitCanvas, &Canvas::mouseEventSignal, &model, &Model::mouseEvent);
    connect(&model, &Model::invalidate, ui->circuitCanvas, &Canvas::redrawCanvas);

    connect(ui->submitTrail, &QPushButton::clicked, &model, &Model::checkWinningCondition);
    connect(&model, &Model::wonLevel, this, &MainWindow::on_submitTrial_clicked);

    connect(ui->notDemo, &QPushButton::clicked, this, &MainWindow::on_orNot_clicked);
    connect(ui->levelOne, &QPushButton::clicked, this, &MainWindow::levelOne_clicked);
    connect(ui->levelTwo, &QPushButton::clicked, this, &MainWindow::levelTwo_clicked);
    connect(ui->levelThree, &QPushButton::clicked, this, &MainWindow::levelThree_clicked);
    connect(ui->levelFour, &QPushButton::clicked, this, &MainWindow::levelFour_clicked);
    connect(ui->levelFive, &QPushButton::clicked, this, &MainWindow::levelFive_clicked);
    connect(ui->finalTest, &QPushButton::clicked, this, &MainWindow::finalTest_clicked);
    connect(this, &MainWindow::setAndLevel, &model, &Model::setAndLevel);
    //connect(&model, &Model::checkWinningCondition; )
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initCanvas() {
    QImage canvas(32, 32, QImage::Format_ARGB32);
    canvas.fill(Qt::transparent);
    ui->circuitCanvas->redrawCanvas(canvas);
}

void MainWindow::on_testStart_clicked()
{
    ui->levelOne->hide();
    ui->levelTwo->hide();
    ui->levelThree->hide();
    ui->levelFour->hide();
    ui->levelFive->hide();
    ui->orDemo->hide();
    ui->notDemo->hide();
    ui->finalTest->hide();
    ui->testStart->hide();

}


void MainWindow::on_andDemo_clicked()
{
    ui->widget->hide();
    emit setAndLevel(1);
}

void MainWindow::on_submitTrial_clicked()
{
    //emit requestWinningCondition();
    ui->orDemo->show();
    ui->widget->show();
}

void MainWindow::on_orDemo_clicked()
{
    ui->notDemo->show();
    ui->widget->hide();
    emit setAndLevel(2);
}

void MainWindow::on_orNot_clicked()
{
    ui->levelOne->show();
    ui->widget->hide();
    emit setAndLevel(3);
}


void MainWindow::levelOne_clicked()
{
    ui->levelTwo->show();
    ui->widget->hide();
    emit setAndLevel(4);
}
void MainWindow::levelTwo_clicked()
{
    ui->levelThree->show();
    ui->widget->hide();
    emit setAndLevel(5);
}
void MainWindow::levelThree_clicked()
{
    ui->levelFour->show();
    ui->widget->hide();
    emit setAndLevel(6);
}

void MainWindow::levelFour_clicked()
{
    ui->levelFive->show();
    ui->widget->hide();
    emit setAndLevel(7);
}

void MainWindow::levelFive_clicked()
{
    ui->finalTest->show();
    ui->widget->hide();
    emit setAndLevel(8);
}

void MainWindow::finalTest_clicked()
{
    ui->widget->hide();
    emit setAndLevel(9);
}
