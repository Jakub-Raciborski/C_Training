#include "CashFlow.h"

void CashFlow::setComment(string comment)
{
    this->comment = comment;
}
void CashFlow::setDate(Date date)
{
    this->date = date;
}
void CashFlow::setAmount(float amount){
    this->amount = amount;
}
void CashFlow::setIsExpense(bool isExpense){
    this->isExpense = isExpense;
}
