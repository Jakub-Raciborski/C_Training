#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "UserManager.h"
#include "InputStream.h"
#include "XMLFileManagerCashFlow.h"

using namespace std;

class HomeBudget{
    UserManager userManager;
    User loggedUser;
    XMLFileManagerCashFlow Revenue;
    XMLFileManagerCashFlow Expense;

    void displayMainMenu();
    void displayUserMenu();
    void processingDecisionFromUserMenu();
    void logOut();
    void loadDataFromLoggedUser();
    int getDateSignatureOfFirstDayOfPreviousMonth();
    int getDateSignatureOfLastDayOfPreviousMonth();
    int getDateSignatureOfLastDayOfCurrentMonth();
    int getDateSignatureOfFirstDayOfCurrentMonth();
    int getDateSignatureOfSelectedDay();
    void displayFinancialBalanceSheetFromLastMonth();
    void displayFinancialBalanceSheetFromCurrentMonth();
    void displayFinancialBalanceSheetFromSelectedPeriodOfTime();
    float countFinancialBalanceSheetOfSelectedPeriod(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE);

public:
    HomeBudget()
    :Revenue("C:\\HomeBudget\\Revenue.XML"), Expense("C:\\HomeBudget\\Expense.XML"){};

    void startProgram();
};
#endif // HOMEBUDGET_H
