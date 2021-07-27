#include "CashFlow.h"

void CashFlow::setDescription(string description) {
    this->description = description;
}
void CashFlow::setDate(Date date) {
    this->date = date;
}
void CashFlow::setAmount(float amount) {
    this->amount = amount;
}
float CashFlow::getAmount() {
    return amount;
}
string CashFlow::getDescriptiont() {
    return description;
}
Date CashFlow::getDate() {
    return date;
}
int CashFlow::getDateSignature() {
    return date.getDateSignature();
}
int CashFlow::getMonth(){
    return date.getMonth();
}
int CashFlow::getYear(){
    return date.getYear();
}
