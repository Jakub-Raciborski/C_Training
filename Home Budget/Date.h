#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

using namespace std;

class Date
{
    int day;
    int month;
    int year;
    int dateSignature;

    void createSignature();
    void convertStringToDate();
    void setDateToToday();
    string convertMonthIntToTwoCharString();
    string convertDayIntToTwoCharString();
public:
    Date()
    {
        setDateToToday();
        createSignature();
    };
    Date(string userInput) {};
    int getDateSignature();

    bool checkIfDateIsLater();
};

#endif // DATE_H
