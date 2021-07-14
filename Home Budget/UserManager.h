#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "InputStream.h"
#include "XMLFileManager.h"

using namespace std;

class UserManager{
    vector<User> users;
    User *activeUser;
    XMLFileManager XMLUser;

    void displayMainMenu();
    void registerNewUser();
    User loadUserDataFromInput();
public:
    UserManager()
    : activeUser(NULL), XMLUser("C:\\HomeBudget\\Plik.XML"){};
    void processingDecisionFromMainMenu();


};
#endif // USERMANAGER_H
