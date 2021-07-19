#include "HomeBudget.h"

void HomeBudget::displayMainMenu() {
    userManager.processingDecisionFromMainMenu();
}
void HomeBudget::startProgram() {
    while(true) {
        displayMainMenu();
        loggedUser = userManager.getActiveUser();
        while(loggedUser.isActive()) {
            system("cls");
            displayUserMenu();
            processingDecisionFromUserMenu();
        }
    }
}
void HomeBudget::displayUserMenu() {
    cout<<"1. Add Revenue.\n2. Add Expense.\n3. Show Last Month's Balance Sheet.\n4. Show Current Month's Balance Sheet.\n";
    cout<<"5. Choose period for Balance Sheet.\n6. Change Password.\n7. Log Out.\n9. Close Program.\n";
}
void HomeBudget::logOut() {
    userManager.logOut();
    loggedUser.deactivate();
}
void HomeBudget::processingDecisionFromUserMenu() {
    const char USER_DECISION = InputStream::loadOneCharacter();
    switch(USER_DECISION) {
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
