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
void HomeBudget::loadDataFromLoggedUser() {
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
    case '1': {
        Revenue.addCashFlow();
        break;
    }
    case '2': {
        Expense.addCashFlow();
        break;
    }
    case '3': {
        displayFinancialBalanceSheetFromCurrentMonth();
        break;
    }
    case '4': {
        displayFinancialBalanceSheetFromLastMonth();
        break;
    }
    case '5': {
        displayFinancialBalanceSheetFromSelectedPeriodOfTime();
        break;
    }
    case '6':{
        userManager.changePassword();
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
int HomeBudget::getDateSignatureOfFirstDayOfPreviousMonth() {
    Date date;
    date.setDateToTheFirstDayOfPreviousMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureOfLastDayOfPreviousMonth() {
    Date date;
    date.setDateToTheLastDayOfPreviousMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureOfLastDayOfCurrentMonth() {
    Date date;
    date.setDateToTheLastDayOfCurrentMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureOfFirstDayOfCurrentMonth() {
    Date date;
    date.setDateToTheFirstDayOfCurrentMonth();
    return date.getDateSignature();
}
int HomeBudget::getDateSignatureOfSelectedDay() {
    Date date;
    date.setDateByUserDecision();
    return date.getDateSignature();
}
float HomeBudget::countFinancialBalanceSheetOfSelectedPeriod(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE) {
    float sumOfRevenues=0, sumOfExpenses=0, finalAmount=0;
    sumOfRevenues = Revenue.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
    sumOfExpenses = Expense.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
    finalAmount = sumOfRevenues - sumOfExpenses;
    return finalAmount;
}
void HomeBudget::displayFinancialBalanceSheetFromLastMonth() {
    int firstDayOfPreviousMonthSignature = getDateSignatureOfFirstDayOfPreviousMonth();
    int lastDayOfPreviousMonthSignature = getDateSignatureOfLastDayOfPreviousMonth();
    const float BALANCE_SHEET_AMOUNT = countFinancialBalanceSheetOfSelectedPeriod(firstDayOfPreviousMonthSignature, lastDayOfPreviousMonthSignature);

    system("cls");
    cout<<"Your money balance sheet for the previous month is "<<BALANCE_SHEET_AMOUNT<<endl;
    system("pause");
}
void HomeBudget::displayFinancialBalanceSheetFromCurrentMonth() {
    int firstDayOfCurrentMonthSignature = getDateSignatureOfFirstDayOfCurrentMonth();
    int lastDayOfCurrentMonthSignature = getDateSignatureOfLastDayOfCurrentMonth();
    const float BALANCE_SHEET_AMOUNT = countFinancialBalanceSheetOfSelectedPeriod(firstDayOfCurrentMonthSignature, lastDayOfCurrentMonthSignature);

    system("cls");
    cout<<"Your money balance sheet for the current month is "<<BALANCE_SHEET_AMOUNT<<endl;
    system("pause");
}
void HomeBudget::displayFinancialBalanceSheetFromSelectedPeriodOfTime() {
    int signatureOfBeginningDay = 0, signatureOfEndDay = 0;
    do {
        system("cls");
        cout<<"Write date of beginning of the balance money sheet:\n";
        system("pause");
        system("cls");
        signatureOfBeginningDay = getDateSignatureOfSelectedDay();
        cout<<"Write date of end of the balance money sheet:\n";
        system("pause");
        signatureOfEndDay = getDateSignatureOfSelectedDay();
        if(signatureOfBeginningDay >= signatureOfEndDay) {
            cout<<"Date of beginning is higher than date of end. Write dates again.\n";
            system("pause");
        }
    } while(signatureOfBeginningDay > signatureOfEndDay);
    const float BALANCE_SHEET_AMOUNT = countFinancialBalanceSheetOfSelectedPeriod(signatureOfBeginningDay,signatureOfEndDay);
    cout<<"Your money balance sheet is "<<BALANCE_SHEET_AMOUNT<<endl;
    system("pause");
}
