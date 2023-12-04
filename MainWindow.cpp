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
    connect(ui->andDemo, &QPushButton::clicked, &model, &Model::setAndLevel);

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
    ui->testStart->hide();
}


void MainWindow::on_andDemo_clicked()
{/*
    ui->levelOne->hide();
    ui->levelTwo->hide();
    ui->levelThree->hide();
    ui->levelFour->hide();
    ui->levelFive->hide();
    ui->orDemo->hide();
    ui->notDemo->hide();
    ui->finalTest->hide();*/
    ui->widget->hide();
}

