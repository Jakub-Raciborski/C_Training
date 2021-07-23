#include "Date.h"

int Date::getMonth() {
    return month;
}
int Date::getYear() {
    return year;
}
int Date::getDateSignature() {
    createSignature();
    return dateSignature;
}
void Date::setDateToToday() {
    time_t t = time(0);
    tm* now = localtime(&t);
    this->day = now->tm_mday;
    this->month = now->tm_mon + 1;
    this->year = now->tm_year + 1900;
}
string Date::convertMonthIntToTwoCharString() {
    string monthAsString = "";
    if(this->month > 9)
        monthAsString = VariableModification::convertIntToString(this->month);
    else {
        monthAsString = '0' + VariableModification::convertIntToString(this->month);
    }
    return monthAsString;
}
string Date::convertDayIntToTwoCharString() {
    string dayAsString = "";
    if(this->day > 9)
        dayAsString = VariableModification::convertIntToString(this->day);
    else
        dayAsString = '0' + VariableModification::convertIntToString(this->day);
    return dayAsString;
}
void Date::createSignature() {
    string year = VariableModification::convertIntToString(this->year);
    string month = convertMonthIntToTwoCharString();
    string day = convertDayIntToTwoCharString();
    string signature = year + month + day;
    this->dateSignature = VariableModification::convertStringToInt(signature);
}
int Date::askAboutYear() {
    int year = 0;
    while(year == 0) {
        system("cls");
        cout<<"Enter the year: \n";
        string user_answer = InputStream::loadLine();
        year = VariableModification::convertStringToInt(user_answer);
        if(year!=0)
            return year;
        else {
            cout<<"Wrong year. Year has to be number and higher than 0.\n";
            system("pause");
        }
    }
}
bool Date::isMonthCorrect(string month) {
    const int MONTH_TO_CHECK = VariableModification::convertStringToInt(month);
    const int AMOUNT_OF_MONTHS_IN_YEAR = 12;
    if(MONTH_TO_CHECK >0  && MONTH_TO_CHECK <= AMOUNT_OF_MONTHS_IN_YEAR)
        return true;
    else
        return false;
}
int Date::askAboutMonth() {
    int month = 0;
    while(month == 0) {
        system("cls");
        cout<<"Enter the month(number 1-12): \n";
        string user_answer = InputStream::loadLine();
        if(isMonthCorrect(user_answer)) {
            month = VariableModification::convertStringToInt(user_answer);
            return month;
        } else {
            cout<<"Wrong month. Write number from range 1-12.\n";
            system("pause");
        }
    }
}
bool Date::isMonthWith31days() {
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
            month == 10 || month == 12)
        return true;
    else return false;
}
bool Date::isMonthWith30days() {
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return true;
    else
        return false;
}
bool Date::isFebruary() {
    if(month == 2)
        return true;
    else
        return false;
}
bool Date::isLeapYear() {
    if(year % 4 != 0)
        return false;
    else if(year % 4 == 0 && year % 100 == 0 && year % 400 != 0 )
        return false;
    else
        return true;
}
bool Date::isDayCorrect(string day) {
    const int DAY_TO_CHECK = VariableModification::convertStringToInt(day);
    if(DAY_TO_CHECK < 0 )
        return false;
    else {
        if(isMonthWith30days() && DAY_TO_CHECK <= 30)
            return true;
        else if(isMonthWith31days() && DAY_TO_CHECK <=31)
            return true;
        else if(isFebruary() && isLeapYear() && DAY_TO_CHECK <= 29)
            return true;
        else if(isFebruary() && !isLeapYear() && DAY_TO_CHECK <= 28)
            return true;
        else
            return false;
    }
}
int Date::askAboutDay() {
    int day = 0;
    while(day == 0) {
        system("cls");
        cout<<"Enter the day(number 1-31): \n";
        string user_answer = InputStream::loadLine();
        if(isDayCorrect(user_answer)) {
            day = VariableModification::convertStringToInt(user_answer);
            return day;
        } else {
            cout<<"Wrong day. Write number from range 1-31 according to selected month.\n";
            system("pause");
        }
    }
}
void Date::setDateNotToToday() {
    this->year = askAboutYear();
    this->month = askAboutMonth();
    this->day = askAboutDay();
}
