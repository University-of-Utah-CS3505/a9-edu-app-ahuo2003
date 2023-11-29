#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Canvas &canvas, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_testStart_clicked();

    void on_andDemo_clicked();

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
