#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "UserManager.h"

using namespace std;

class HomeBudget{
    UserManager userManager;
public:
    HomeBudget(){};
    void displayMainMenu();
};
#endif // HOMEBUDGET_H
