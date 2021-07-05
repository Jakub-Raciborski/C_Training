#ifndef CASHFLOW_H
#define CASHFLOW_H

#include "Date.h"

using namespace std;

class CashFlow{
    string comment;
    Date date;
    float amount;
    bool isExpense;

public:
    CashFlow(){};
    void setComment(string comment);
    void setDate(Date date);
    void setAmount(float amount);
    void setIsExpense(bool isExpense);
    string getComment();
    Date getDate();
    float getAmount;
    bool checkIsExpense();


};

#endif // CASHFLOW_H
