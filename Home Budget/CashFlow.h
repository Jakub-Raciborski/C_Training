#ifndef CASHFLOW_H
#define CASHFLOW_H

#include "Date.h"

using namespace std;

class CashFlow{
    string description;
    Date date;
    float amount;

public:
    CashFlow(){};
    CashFlow(float amount, Date date, string description){
        this->amount = amount;
        this->date = date;
        this->description = description;
    }
    void setDescription(string description);
    void setDate(Date date);
    void setAmount(float amount);
    string getDescriptiont();
    Date getDate();
    float getAmount();

    int getDateSignature();
    int getYear();
    int getMonth();
};

#endif // CASHFLOW_H
