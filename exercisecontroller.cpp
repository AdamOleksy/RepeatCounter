#include "exercisecontroller.h"
#include <iostream>

void ExerciseController::setPlanedNumberOfReps(int number){
    planedNumOfReps = number;
}

void ExerciseController::addReps(int number){
    if(numberOfRepetitions < planedNumOfReps)
        numberOfRepetitions += number;
}

int ExerciseController::getProgres(){
    if(numberOfRepetitions/planedNumOfReps >= 1){
        isItDone = true;
        return 100;
    }
    return (numberOfRepetitions*100/planedNumOfReps);
}

void ExerciseController::addSecound(){
    secoundsFromStart++;
}

int ExerciseController::getTotalTime(){
    return secoundsFromStart;
}

void ExerciseController::setIntervalBegin(){
    timeIntervalBegin = secoundsFromStart;
}

int ExerciseController::getIntervalTime(){
    return secoundsFromStart - timeIntervalBegin;
}

bool ExerciseController::checkIfExerciseIsDone(){
    return isItDone;
}

void ExerciseController::addIntervalToMemory(int reps){
    memoryIntervals.push_back(reps);
}

void ExerciseController::popLastInterval(){
    undoReps(memoryIntervals.back());
    memoryIntervals.pop_back();
}

int ExerciseController::checkLastInterval(){
    return memoryIntervals.back();
}

void ExerciseController::undoReps(int number){
    numberOfRepetitions-=number;
}
