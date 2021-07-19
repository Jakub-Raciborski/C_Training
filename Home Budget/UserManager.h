#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "InputStream.h"
#include "XMLFileManagerUsers.h"

using namespace std;

class UserManager{
    vector<User> users;
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


};
#endif // USERMANAGER_H
