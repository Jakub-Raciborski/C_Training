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
    cout<<"1. Add Revenue.\n2. Add Expense.\n3. Show Last Month's Balance Sheet.\n4. Show Current Month's Balance Sheet.\n";
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
