#ifndef EXERCISECONTROLLER_H
#define EXERCISECONTROLLER_H

#include "qstring.h"
#include <vector>

class ExerciseController
{
public:
    ExerciseController():numberOfRepetitions(0), secoundsFromStart(0),
                            timeIntervalBegin(0), isItDone(false){}
    void setPlanedNumberOfReps(int number);
    int getTotalNumberOfReps() {return planedNumOfReps;}
    void addReps(int number);
    int getProgres();
    void startCountingSecounds();
    void addSecound();
    int getTotalTime();
    void setIntervalBegin();
    int getIntervalTime();
    bool checkIfExerciseIsDone();
    void addIntervalToMemory(int reps);
    void popLastInterval();
    int checkLastInterval();
    void undoReps(int number);

private:
    int planedNumOfReps;
    int numberOfRepetitions;
    int secoundsFromStart;
    int timeIntervalBegin;
    bool isItDone;
    std::vector<int> memoryIntervals;
};

#endif // EXERCISECONTROLLER_H
