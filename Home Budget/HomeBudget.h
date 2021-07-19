#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "UserManager.h"
#include "InputStream.h"

using namespace std;

class HomeBudget{
    UserManager userManager;
    User loggedUser;

    void displayMainMenu();
    void displayUserMenu();
    void processingDecisionFromUserMenu();
    void logOut();

public:
    HomeBudget(){};

    void startProgram();
};
#endif // HOMEBUDGET_H
