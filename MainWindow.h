#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Model.h>
#include "Canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Canvas &canvas, Model &model, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void setAndLevel(int levelSelect);

public slots:
    void on_testStart_clicked();

    void on_andDemo_clicked();
    void on_orDemo_clicked();
    void on_orNot_clicked();
    void on_submitTrial_clicked();
    void levelOne_clicked();
    void levelTwo_clicked();
    void levelThree_clicked();
    void levelFour_clicked();
    void levelFive_clicked();
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
