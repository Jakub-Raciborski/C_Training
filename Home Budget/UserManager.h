#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"
#include "InputStream.h"

using namespace std;

class UserManager{
    vector<User> users;
    User *activeUser;

    void displayMainMenu();
    void registerNewUser();
    User loadUserDataFromInput();
    void saveNewUserInXMLFile(User newUser);
public:
    UserManager()
    : activeUser(NULL){};
    void processingDecisionFromMainMenu();


};
#endif // USERMANAGER_H
