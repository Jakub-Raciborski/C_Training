#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "InputStream.h"
#include "XMLFileManagerUsers.h"

using namespace std;

class UserManager{
    User activeUser;
    XMLFileManagerUsers XMLUser;

    void displayMainMenu();
    void registerNewUser();
    User loadUserDataFromInput();
    void logIn();
public:
    UserManager()
    : XMLUser("C:\\HomeBudget\\Users.XML"){};
    User getActiveUser();

    void processingDecisionFromMainMenu();
    void logOut();
    void changePassword();


};
#endif // USERMANAGER_H
