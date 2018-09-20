#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "exercisecontroller.h"
#include "qstring.h"
#include <QTimer>
#include "timeconverter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int liczba;
    void addReps(int number);
    void enableRepsButtons();
    void disableRepsButtons();
    void stopExercise();

private slots:
    void on_submitButton_clicked();

    void on_add5Reps_clicked();

    void on_add1Rep_clicked();

    void on_add2Reps_clicked();

    void on_add10Reps_clicked();

    void on_add20Reps_clicked();

    void secondPassed();

    void on_undoButton_clicked();

    void updateProgressBar();

private:
    Ui::MainWindow *ui;
    ExerciseController *exerciseController;
    QTimer *timer;
    TimeConverter *timeConverter;
};

#endif // MAINWINDOW_H
