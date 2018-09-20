#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exercisecontroller.h"
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    exerciseController(new ExerciseController()),
    timeConverter(new TimeConverter())
{
    ui->setupUi(this);
    disableRepsButtons();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(secondPassed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitButton_clicked()
{
    try
    {
        exerciseController->setPlanedNumberOfReps( std::atoi(ui->numOfRepetition->toPlainText().toStdString().c_str()) );
    }
    catch (std::invalid_argument)
    {
        ui->yourGoal->setText("Niewlasciwa liczba");
        return;
    }
    ui->submitButton->setEnabled(0);
    ui->numOfRepetition->setEnabled(0);
    ui->yourGoal->setText("Your goal for today: " + ui->numOfRepetition->toPlainText() + " reps");
    enableRepsButtons();
    timer->start(1000);
}

void MainWindow::addReps(int number){
    exerciseController->addReps(number);
    updateProgressBar();
    ui->interval_clock->setText(timeConverter->secondsToString(exerciseController->getIntervalTime()));
    exerciseController->addIntervalToMemory(number);
    exerciseController->setIntervalBegin();
    if(exerciseController->checkIfExerciseIsDone())
        stopExercise();
}

void MainWindow::on_add5Reps_clicked()
{
    addReps(5);
}

void MainWindow::on_add1Rep_clicked()
{
    addReps(1);
}

void MainWindow::on_add2Reps_clicked()
{
    addReps(2);
}

void MainWindow::on_add10Reps_clicked()
{
    addReps(10);
}

void MainWindow::on_add20Reps_clicked()
{
    addReps(20);
}

void MainWindow::enableRepsButtons(){
    ui->add1Rep->setEnabled(1);
    ui->add2Reps->setEnabled(1);
    ui->add5Reps->setEnabled(1);
    ui->add10Reps->setEnabled(1);
    ui->add20Reps->setEnabled(1);
}

void MainWindow::disableRepsButtons(){
    ui->add1Rep->setEnabled(0);
    ui->add2Reps->setEnabled(0);
    ui->add5Reps->setEnabled(0);
    ui->add10Reps->setEnabled(0);
    ui->add20Reps->setEnabled(0);
}

void MainWindow::secondPassed(){
    exerciseController->addSecound();
    ui->totall_time_clock->setText(timeConverter->secondsToString(exerciseController->getTotalTime()));
}

void MainWindow::stopExercise(){
    disableRepsButtons();
    timer->stop();
}

void MainWindow::on_undoButton_clicked()
{
    exerciseController->popLastInterval();
    updateProgressBar();
}

void MainWindow::updateProgressBar(){
    ui->progressBar->setValue(exerciseController->getProgres());
}
