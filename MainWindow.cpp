#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Model &model, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Set window size to 1280x720 (non-resizable)
  this->setFixedSize(1280, 720);

  // Show the canvas
  ui->widget->show();

  // Load title icon
  QPixmap pixmap(":/title.png");
  QIcon buttonIcon(pixmap);
  ui->testStart->setIcon(buttonIcon);
  ui->testStart->setIconSize(pixmap.rect().size());

  // Hide warning message by default
  ui->warningMessage->hide();

  // Connect signals and slots
  connect(ui->circuitCanvas, &Canvas::mouseEventSignal, &model,
          &Model::mouseEvent);
  connect(&model, &Model::invalidate, ui->circuitCanvas, &Canvas::redrawCanvas);
  connect(ui->submitTrail, &QPushButton::clicked, &model,
          &Model::checkWinningCondition);
  connect(&model, &Model::wonLevel, this, &MainWindow::on_submitTrial_clicked);
  connect(&model, &Model::levelLost, this, &MainWindow::warningDisplay);
  connect(ui->notDemo, &QPushButton::clicked, this,
          &MainWindow::on_orNot_clicked);
  connect(ui->levelOne, &QPushButton::clicked, this,
          &MainWindow::levelOne_clicked);
  connect(ui->levelTwo, &QPushButton::clicked, this,
          &MainWindow::levelTwo_clicked);
  connect(ui->levelThree, &QPushButton::clicked, this,
          &MainWindow::levelThree_clicked);
  connect(ui->levelFour, &QPushButton::clicked, this,
          &MainWindow::levelFour_clicked);
  connect(ui->levelFive, &QPushButton::clicked, this,
          &MainWindow::levelFive_clicked);
  connect(ui->finalTest, &QPushButton::clicked, this,
          &MainWindow::finalTest_clicked);
  connect(this, &MainWindow::setAndLevel, &model, &Model::setAndLevel);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::warningDisplay() {
  // Show warning message
  ui->warningMessage->show();
}

void MainWindow::on_warningMessage_clicked() {
  // Hide warning message on user click
  ui->warningMessage->hide();
}

void MainWindow::initCanvas() {
  // Initialize canvas with a transparent image
  QImage canvas(32, 32, QImage::Format_ARGB32);
  canvas.fill(Qt::transparent);
  ui->circuitCanvas->redrawCanvas(canvas);
}

void MainWindow::on_testStart_clicked() {
  // Hide level buttons and start button
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

void MainWindow::on_andDemo_clicked() {
  // Hide the main widget, show 'orDemo' widget, and set the level to 1
  ui->widget->hide();
  ui->orDemo->show();
  ui->expectedResult->setText("Expected Result: True/Green");
  emit setAndLevel(1);
}

void MainWindow::on_submitTrial_clicked() {
  // Show the main widget and create 10 bouncing boxes with random properties
  ui->widget->show();
  for (int i = 0; i < 10; i++) {
    float x_pos = (std::rand() % 1200) + 10;
    float y_pos = (std::rand() % 60) + 15;
    float r_rand = (std::rand() % 5) + 1;
    ui->trackerWidget->createBouncingBox(x_pos, y_pos, 4.0f, 4.0f, 1.0f, 0.3f,
                                         r_rand);
  }
}

void MainWindow::on_orDemo_clicked() {
  // Show 'notDemo' widget, hide the main widget, and set the level to 2
  ui->notDemo->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: True/Green");
  emit setAndLevel(2);
}

void MainWindow::on_orNot_clicked() {
  // Show 'levelOne' widget, hide the main widget, and set the level to 3
  ui->levelOne->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: True/Green");
  emit setAndLevel(3);
}

void MainWindow::levelOne_clicked() {
  // Show 'levelTwo' widget, hide the main widget, and set the level to 4
  ui->levelTwo->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: True/Green");
  emit setAndLevel(4);
}

void MainWindow::levelTwo_clicked() {
  // Show 'levelThree' widget, hide the main widget, and set the level to 5
  ui->levelThree->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: False/Red");
  emit setAndLevel(5);
}

void MainWindow::levelThree_clicked() {
  // Show 'levelFour' widget, hide the main widget, and set the level to 6
  ui->levelFour->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: False/Red");
  emit setAndLevel(6);
}

void MainWindow::levelFour_clicked() {
  // Show 'levelFive' widget, hide the main widget, and set the level to 7
  ui->levelFive->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: False/Red");
  emit setAndLevel(7);
}

void MainWindow::levelFive_clicked() {
  // Show 'finalTest' widget, hide the main widget, and set the level to 8
  ui->finalTest->show();
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: False/Red");
  emit setAndLevel(8);
}

void MainWindow::finalTest_clicked() {
  // Hide the main widget and set the level to 9
  ui->widget->hide();
  ui->expectedResult->setText("Expected Result: False/Red");
  emit setAndLevel(9);
}
