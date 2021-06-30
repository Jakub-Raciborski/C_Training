#include "Date.h"
#include "VariableModification.h"

int Date::getDateSignature(){
    return dateSignature;
}
void Date::setDateToToday(){
    time_t t = time(0);
    tm* now = localtime(&t);
    this->day = now->tm_mday;
    this->month = now->tm_mon + 1;
    this->year = now->tm_year + 1900;
}
string Date::convertMonthIntToTwoCharString(){
    string monthAsString = "";
    if(this->month > 9)
        monthAsString = VariableModification::convertIntToString(this->month);
    else{
        monthAsString = '0' + VariableModification::convertIntToString(this->month);
    }
    return monthAsString;
}
string Date::convertDayIntToTwoCharString(){
    string dayAsString = "";
    if(this->day > 9)
        dayAsString = VariableModification::convertIntToString(this->day);
    else
        dayAsString = '0' + VariableModification::convertIntToString(this->day);
    return dayAsString;
}
void Date::createSignature(){
    string year = VariableModification::convertIntToString(this->year);
    string month = convertMonthIntToTwoCharString();
    string day = convertDayIntToTwoCharString();
    string signature = year + month + day;
    this->dateSignature = VariableModification::convertStringToInt(signature);
}
