#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Canvas.h"
#include <Model.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(Canvas &canvas, Model &model, QWidget *parent = nullptr);
  ~MainWindow();

signals:
  /**
   * @brief setAndLevel TODO
   * @param levelSelect TODO
   */
  void setAndLevel(int levelSelect);
  void redraw();
  void requestWinningCondition();

public slots:
  /**
   * @brief on_testStart_clicked TODO
   */
  void on_testStart_clicked();

  /**
   * @brief on_andDemo_clicked TODO
   */
  void on_andDemo_clicked();

  /**
   * @brief on_orDemo_clicked TODO
   */
  void on_orDemo_clicked();

  /**
   * @brief on_orNot_clicked TODO
   */
  void on_orNot_clicked();

  /**
   * @brief on_submitTrial_clicked TODO
   */
  void on_submitTrial_clicked();

  /**
   * @brief levelOne_clicked TODO
   */
  void levelOne_clicked();

  /**
   * @brief levelTwo_clicked TODO
   */
  void levelTwo_clicked();

  /**
   * @brief levelThree_clicked TODO
   */
  void levelThree_clicked();

  /**
   * @brief levelFour_clicked TODO
   */
  void levelFour_clicked();

  /**
   * @brief levelFive_clicked TODO
   */
  void levelFive_clicked();

  /**
   * @brief finalTest_clicked TODO
   */
  void finalTest_clicked();

private:
  Ui::MainWindow *ui;

  /**
   * @brief initCanvas set the drawing canvas.
   */
  void initCanvas();

  /**
   * @brief initPreviews set the preview animation playback frame.
   */
  void initPreviews();
};
#endif // MAINWINDOW_H
