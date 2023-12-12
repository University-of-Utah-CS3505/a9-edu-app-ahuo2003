#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Model.h>
#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Model &model, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    /**
   * @brief setAndLevel
   * Emits the signal to set the level to the specified value.
   * @param levelSelect The selected level.
   */
    void setAndLevel(int levelSelect);

    /**
   * @brief redraw
   * Emits the signal to request a redraw of the canvas.
   */
    void redraw();

    /**
   * @brief requestWinningCondition
   * Emits the signal to request the winning condition.
   */
    void requestWinningCondition();

public slots:
    /**
   * @brief on_testStart_clicked
   * Slot for handling the test start button click event.
   */
    void on_testStart_clicked();

    /**
   * @brief on_warningMessage_clicked
   * Slot for handling the warning message click event.
   */
    void on_warningMessage_clicked();

    /**
   * @brief on_andDemo_clicked
   * Slot for handling the 'andDemo' button click event.
   */
    void on_andDemo_clicked();

    /**
   * @brief on_orDemo_clicked
   * Slot for handling the 'orDemo' button click event.
   */
    void on_orDemo_clicked();

    /**
   * @brief on_orNot_clicked
   * Slot for handling the 'orNot' button click event.
   */
    void on_orNot_clicked();

    /**
   * @brief on_submitTrial_clicked
   * Slot for handling the submit trial button click event.
   */
    void on_submitTrial_clicked();

    /**
   * @brief on_backButton_clicked_clicked
   * Slot for handling the back button click event.
   */
    void on_backButton_clicked();

    /**
   * @brief warningDisplay
   * Slot for displaying a warning.
   */
    void warningDisplay();

    /**
   * @brief levelOne_clicked
   * Slot for handling the level one button click event.
   */
    void levelOne_clicked();

    /**
   * @brief levelTwo_clicked
   * Slot for handling the level two button click event.
   */
    void levelTwo_clicked();

    /**
   * @brief levelThree_clicked
   * Slot for handling the level three button click event.
   */
    void levelThree_clicked();

    /**
   * @brief levelFour_clicked
   * Slot for handling the level four button click event.
   */
    void levelFour_clicked();

    /**
   * @brief levelFive_clicked
   * Slot for handling the level five button click event.
   */
    void levelFive_clicked();

    /**
   * @brief finalTest_clicked
   * Slot for handling the final test button click event.
   */
    void finalTest_clicked();

private:
    Ui::MainWindow *ui;

    /**
   * @brief initCanvas
   * Initializes the drawing canvas.
   */
    void initCanvas();

    /**
   * @brief initPreviews
   * Initializes the preview animation playback frame.
   */
    void initPreviews();
};
#endif // MAINWINDOW_H
