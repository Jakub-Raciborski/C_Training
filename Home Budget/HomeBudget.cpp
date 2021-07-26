#include "HomeBudget.h"

void HomeBudget::displayMainMenu() {
    userManager.processingDecisionFromMainMenu();
}
void HomeBudget::startProgram() {
    while(true) {
        displayMainMenu();
        loadDataFromLoggedUser();
        while(loggedUser.isActive()) {
            system("cls");
            displayUserMenu();
            processingDecisionFromUserMenu();
        }
    }
}
void HomeBudget::loadDataFromLoggedUser(){
    loggedUser = userManager.getActiveUser();
    Revenue.logInUser(loggedUser);
    Expense.logInUser(loggedUser);
}
void HomeBudget::displayUserMenu() {
    cout<<"1. Add Revenue.\n2. Add Expense.\n3. Show Current Month's Balance Sheet.\n4. Show Last Month's Balance Sheet.\n";
    cout<<"5. Choose period for Balance Sheet.\n6. Change Password.\n7. Log Out.\n9. Close Program.\n";
}
void HomeBudget::logOut() {
    userManager.logOut();
    loggedUser.deactivate();
    Revenue.logOutUser();
    Expense.logOutUser();
}
void HomeBudget::processingDecisionFromUserMenu() {
    const char USER_DECISION = InputStream::loadOneCharacter();
    switch(USER_DECISION) {
    case '1':{
        Revenue.addCashFlow();
        break;
    }
    case '2':{
        Expense.addCashFlow();
        break;
    }
    case '3':{
        displayFinancialBalanceSheetFromCurrentMonth();
        break;
    }
    case '4':{
        displayFinancialBalanceSheetFromLastMonth();
        break;
    }
    case '7': {
        logOut();
        break;
    }
    case '9':
        exit(0);
    default:
        cout << endl << "Wrong character. Try again." << endl << endl;
        system("pause");
    }
}
int HomeBudget::getDateSignatureFromFirstDayOfPreviousMonth(){
    Date date;
    date.setDateToTheFirstDayOfPreviousMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureFromLastDayOfPreviousMonth(){
    Date date;
    date.setDateToTheLastDayOfPreviousMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureFromLastDayOfCurrentMonth(){
    Date date;
    date.setDateToTheLastDayOfCurrentMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureFromFirstDayOfCurrentMonth(){
    Date date;
    date.setDateToTheFirstDayOfCurrentMonth();
    return date.getDateSignature();
}
float HomeBudget::countFinancialBalanceSheetOfSelectedPeriod(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE){
    float sumOfRevenues=0, sumOfExpenses=0, finalAmount=0;
    sumOfRevenues = Revenue.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
    sumOfExpenses = Expense.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
    finalAmount = sumOfRevenues - sumOfExpenses;
    return finalAmount;
}
void HomeBudget::displayFinancialBalanceSheetFromLastMonth(){
    int firstDayOfPreviousMonthSignature = getDateSignatureFromFirstDayOfPreviousMonth();
    int lastDayOfPreviousMonthSignature = getDateSignatureFromLastDayOfPreviousMonth();
    const float BALANCE_SHEET_AMOUNT = countFinancialBalanceSheetOfSelectedPeriod(firstDayOfPreviousMonthSignature, lastDayOfPreviousMonthSignature);

    system("cls");
    cout<<"Your money balance sheet for the previous month is "<<BALANCE_SHEET_AMOUNT<<endl;
    system("pause");
}
void HomeBudget::displayFinancialBalanceSheetFromCurrentMonth(){
    int firstDayOfCurrentMonthSignature = getDateSignatureFromFirstDayOfCurrentMonth();
    int lastDayOfCurrentMonthSignature = getDateSignatureFromLastDayOfCurrentMonth();
    const float BALANCE_SHEET_AMOUNT = countFinancialBalanceSheetOfSelectedPeriod(firstDayOfCurrentMonthSignature, lastDayOfCurrentMonthSignature);

    system("cls");
    cout<<"Your money balance sheet for the current month is "<<BALANCE_SHEET_AMOUNT<<endl;
    system("pause");
}
