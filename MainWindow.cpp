#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(Canvas &canvas, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->show();

    // Default window size of 1280x720 (non-resizable)
    this->setFixedSize(1280, 720);

    // Initialize canvas.
    //initPreviews();

    // Draw the canvas
    initCanvas();

    // Canvas-to-Tools connection
    //connect(ui->drawingCanvas, &Canvas::mouseEventSignal, &model, &SpriteModel::useTool);
    //connect(&model, &SpriteModel::updateFrame, ui->drawingCanvas, &Canvas::redrawCanvas);
    //connect(&model, &SpriteModel::updateScaleFactor, ui->drawingCanvas, &Canvas::updateCanvasScaleFactor);

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

