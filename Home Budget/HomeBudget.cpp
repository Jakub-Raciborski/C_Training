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
    revenue.logInUser(loggedUser);
    expense.logInUser(loggedUser);
}
void HomeBudget::displayUserMenu() {
    cout<<"1. Add revenue.\n2. Add expense.\n3. Show Current Month's Balance Sheet.\n4. Show Last Month's Balance Sheet.\n";
    cout<<"5. Choose period for Balance Sheet.\n6. Change Password.\n7. Log Out.\n9. Close Program.\n";
}
void HomeBudget::logOut() {
    userManager.logOut();
    loggedUser.deactivate();
    revenue.logOutUser();
    expense.logOutUser();
}
void HomeBudget::processingDecisionFromUserMenu() {
    const char USER_DECISION = InputStream::loadOneCharacter();
    switch(USER_DECISION) {
    case '1': {
        revenue.addCashFlow();
        break;
    }
    case '2': {
        expense.addCashFlow();
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
float HomeBudget::countSumOfExpenses(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE){
    return expense.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
}
float HomeBudget::countSumOfRevenues(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE){
    return revenue.countSumOfCashFlowsOfSelectedPeriod(FIRST_DAY_SIGNATURE, LAST_DAY_SIGNATURE);
}
void HomeBudget::displayListOfRevenues(const int FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE, const int LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE){
    cout<<"Revenues list:\n";
    revenue.displayAllCashFlowsDetailsFromSelectedPeriod(FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE,LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE);
    cout<<endl;
}
void HomeBudget::displayListOfExpenses(const int FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE, const int LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE){
    cout<<"Expenses list:\n";
    expense.displayAllCashFlowsDetailsFromSelectedPeriod(FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE,LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE);
    cout<<endl;
}
void HomeBudget::displayAllDetailsForFinancialBalanceSheetFromSelectedPeriodOfTime(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE){
    system("cls");

    displayListOfRevenues(FIRST_DAY_SIGNATURE,LAST_DAY_SIGNATURE);
    const float SUM_OF_REVENUES = countSumOfRevenues(FIRST_DAY_SIGNATURE,LAST_DAY_SIGNATURE);
    cout<<"Sum of revenues is "<<VariableModification::convertFloatToString(SUM_OF_REVENUES)<<endl<<endl;

    displayListOfExpenses(FIRST_DAY_SIGNATURE,LAST_DAY_SIGNATURE);
    const float SUM_OF_EXPENSES = countSumOfExpenses(FIRST_DAY_SIGNATURE,LAST_DAY_SIGNATURE);
    cout<<"Sum of expenses is "<<VariableModification::convertFloatToString(SUM_OF_EXPENSES)<<endl<<endl;

    float finaleBalance = SUM_OF_REVENUES - SUM_OF_EXPENSES;
    cout<<"Balance of income and expenses is "<<finaleBalance<<" PLN"<<endl;
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

    displayAllDetailsForFinancialBalanceSheetFromSelectedPeriodOfTime(signatureOfBeginningDay, signatureOfEndDay);
}
void HomeBudget::displayFinancialBalanceSheetFromCurrentMonth() {
    int firstDayOfCurrentMonthSignature = getDateSignatureOfFirstDayOfCurrentMonth();
    int lastDayOfCurrentMonthSignature = getDateSignatureOfLastDayOfCurrentMonth();
    displayAllDetailsForFinancialBalanceSheetFromSelectedPeriodOfTime(firstDayOfCurrentMonthSignature, lastDayOfCurrentMonthSignature);
}
void HomeBudget::displayFinancialBalanceSheetFromLastMonth() {
    int firstDayOfPreviousMonthSignature = getDateSignatureOfFirstDayOfPreviousMonth();
    int lastDayOfPreviousMonthSignature = getDateSignatureOfLastDayOfPreviousMonth();
    displayAllDetailsForFinancialBalanceSheetFromSelectedPeriodOfTime(firstDayOfPreviousMonthSignature, lastDayOfPreviousMonthSignature);
}
