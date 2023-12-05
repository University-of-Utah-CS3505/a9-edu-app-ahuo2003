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

    // Initialize canvas.
    //initPreviews();

    // Draw the canvas
    initCanvas();

    QPixmap pixmap(":/title.png");
    QIcon ButtonIcon(pixmap);
    ui->testStart->setIcon(ButtonIcon);
    ui->testStart->setIconSize(pixmap.rect().size());

    // Canvas-to-Tools connection
    //connect(ui->drawingCanvas, &Canvas::mouseEventSignal, &model, &SpriteModel::useTool);
    //connect(&model, &SpriteModel::updateFrame, ui->drawingCanvas, &Canvas::redrawCanvas);
    //connect(&model, &SpriteModel::updateScaleFactor, ui->drawingCanvas, &Canvas::updateCanvasScaleFactor);
    connect(ui->circuitCanvas, &Canvas::mouseEventSignal, &model, &Model::mouseEvent);
    connect(&model, &Model::invalidate, ui->circuitCanvas, &Canvas::redrawCanvas);
    connect(ui->submitTrail, &QPushButton::clicked, this, &MainWindow::on_submitTrial_clicked);
    connect(ui->notDemo, &QPushButton::clicked, this, &MainWindow::on_orNot_clicked);
    connect(ui->levelOne, &QPushButton::clicked, this, &MainWindow::levelOne_clicked);
    connect(ui->levelTwo, &QPushButton::clicked, this, &MainWindow::levelTwo_clicked);
    connect(ui->levelThree, &QPushButton::clicked, this, &MainWindow::levelThree_clicked);
    connect(ui->levelFour, &QPushButton::clicked, this, &MainWindow::levelFour_clicked);
    connect(ui->levelFive, &QPushButton::clicked, this, &MainWindow::levelFive_clicked);
    connect(ui->finalTest, &QPushButton::clicked, this, &MainWindow::finalTest_clicked);

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

void MainWindow::initPreviews() {
    //animationPrev.fill(Qt::white);
    //blackColorPreview.fill(Qt::black);
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
    /*ui->levelOne->hide();
    ui->levelTwo->hide();
    ui->levelThree->hide();
    ui->levelFour->hide();
    ui->levelFive->hide();
    ui->orDemo->hide();
    ui->notDemo->hide();
    ui->finalTest->hide();*/
    ui->widget->hide();
}

void MainWindow::on_submitTrial_clicked()
{
    ui->orDemo->show();
    ui->widget->show();
}

void MainWindow::on_orDemo_clicked()
{
    ui->notDemo->show();
    ui->widget->hide();

}

void MainWindow::on_orNot_clicked()
{
    ui->levelOne->show();
    ui->widget->hide();
}


void MainWindow::levelOne_clicked()
{
    ui->levelTwo->show();
    ui->widget->hide();
}
void MainWindow::levelTwo_clicked()
{
    ui->levelThree->show();
    ui->widget->hide();
}
void MainWindow::levelThree_clicked()
{
    ui->levelFour->show();
    ui->widget->hide();
}

void MainWindow::levelFour_clicked()
{
    ui->levelFive->show();
    ui->widget->hide();
}

void MainWindow::levelFive_clicked()
{
    ui->finalTest->show();
    ui->widget->hide();
}

void MainWindow::finalTest_clicked()
{
    ui->widget->hide();
}
