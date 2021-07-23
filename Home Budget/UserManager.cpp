#include "UserManager.h"

User UserManager::getActiveUser(){
    return activeUser;
}

void UserManager::processingDecisionFromMainMenu() {
    while(!activeUser.isActive()) {
        displayMainMenu();
        char userDecision = InputStream::loadOneCharacter();
        switch (userDecision) {
        case '1':{
            logIn();
            break;
        }
        case '2':{
            registerNewUser();
            break;
        }
        case '9':
            exit(0);
        default:{
            cout << endl << "Wrong character. Try again." << endl << endl;
            system("pause");
        }
        }
    }
}
void UserManager::displayMainMenu() {
    system("cls");
    cout<<"1. Log In\n2. Add new user\n9. Exit\n";
}
void UserManager::registerNewUser(){
    User newUser = loadUserDataFromInput();
    users.push_back(newUser);
    XMLUser.saveUserData(newUser);
}
User UserManager::loadUserDataFromInput(){
    User newUser;
    newUser.setAllAttributes();
    return newUser;
}
void UserManager::logIn(){
    if(XMLUser.logIn())
        activeUser = XMLUser.getActiveUser();
}
void UserManager::logOut(){
    activeUser.deactivate();
}
