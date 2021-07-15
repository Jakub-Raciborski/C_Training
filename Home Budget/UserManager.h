#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "InputStream.h"
#include "XMLFileManagerUsers.h"

using namespace std;

class UserManager{
    vector<User> users;
    User activeUser;
    bool userIsLogIn;
    XMLFileManagerUsers XMLUser;

    void displayMainMenu();
    void registerNewUser();
    User loadUserDataFromInput();
    void logIn();
public:
    UserManager()
    : XMLUser("C:\\HomeBudget\\Users.XML"),userIsLogIn(false){};
    User getActiveUser();

    void processingDecisionFromMainMenu();


};
#endif // USERMANAGER_H
