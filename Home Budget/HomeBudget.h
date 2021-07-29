#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <vector>
#include "UserManager.h"
#include "InputStream.h"
#include "XMLFileManagerCashFlow.h"

using namespace std;

class HomeBudget{
    UserManager userManager;
    User loggedUser;
    XMLFileManagerCashFlow revenue;
    XMLFileManagerCashFlow expense;
    vector<CashFlow> revenues;
    vector<CashFlow> expenses;

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
    float countSumOfExpenses(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE);
    float countSumOfRevenues(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE);
    void displayListOfRevenues(const int FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE, const int LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE);
    void displayListOfExpenses(const int FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE, const int LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE);
    void displayAllDetailsForFinancialBalanceSheetFromSelectedPeriodOfTime(const int FIRST_DAY_SIGNATURE, const int LAST_DAY_SIGNATURE);

public:
    HomeBudget()
    :revenue("C:\\HomeBudget\\Revenue.XML"), expense("C:\\HomeBudget\\Expense.XML"){};

    void startProgram();
};
#endif // HOMEBUDGET_H
