#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include "VariableModification.h"
#include "InputStream.h"

using namespace std;

class Date
{
    int day;
    int month;
    int year;
    int dateSignature;

    void createSignature();
    void convertStringToDate();
    string convertMonthIntToTwoCharString();
    string convertDayIntToTwoCharString();
    int askAboutYear();
    int askAboutMonth();
    int askAboutDay();
    bool isMonthCorrect(string month);
    bool isDayCorrect(string day);
    bool isDayCorrect(const int DAY_TO_CHECK);
    bool isMonthWith31days();
    bool isMonthWith30days();
    bool isLeapYear();
    bool isFebruary();
    int getLastDayOfCurrentMonth();
    void setDateAccordingToSignature();

public:
    Date():year(0), month(0), day(0){}
    Date(int signature)
    :dateSignature(signature){
        setDateAccordingToSignature();
    }
    int getDateSignature();
    int getMonth();
    int getYear();
    void setDateByUserDecision();
    bool checkIfDateIsLater();
    void setDateToToday();
    void setDateToTheFirstDayOfPreviousMonth();
    void setDateToTheLastDayOfPreviousMonth();
    void moveDateToNextDay();
    void moveDateToPreviousDay();
    void setDateToTheFirstDayOfCurrentMonth();
    void setDateToTheLastDayOfCurrentMonth();
    string getDateNotation();
};

#endif // DATE_H
