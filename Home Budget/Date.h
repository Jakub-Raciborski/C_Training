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
    bool isMonthWith31days();
    bool isMonthWith30days();
    bool isLeapYear();
    bool isFebruary();
public:
    Date():year(0), month(0), day(0){}
    int getDateSignature();
    int getMonth();
    int getYear();
    void setDateToToday();
    bool checkIfDateIsLater();
    void setDateNotToToday();
};

#endif // DATE_H
