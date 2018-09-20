#ifndef TIMECONVERTER_H
#define TIMECONVERTER_H

#include "qstring.h"

class TimeConverter
{
public:
    TimeConverter();
    QString secondsToString(int seconds);
};

#endif // TIMECONVERTER_H
