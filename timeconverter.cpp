#include "timeconverter.h"

TimeConverter::TimeConverter()
{

}

QString TimeConverter::secondsToString(int seconds)
{
        int ss = (seconds) % 60;
        int mm = (seconds) / 60;
        QString timeDisplay;
        timeDisplay += " ";
        if (mm < 10)
            timeDisplay += "0";
        timeDisplay += QString::number(mm);
        timeDisplay += ":";
        if (ss < 10)
            timeDisplay += "0";
        timeDisplay += QString::number(ss);
        return timeDisplay;
}
