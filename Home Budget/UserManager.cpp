#include "UserManager.h"

User UserManager::getActiveUser(){
    return activeUser;
}

void UserManager::processingDecisionFromMainMenu() {
    while(userIsLogIn==false) {
        displayMainMenu();
        char userDecision = InputStream::loadOneCharacter();
        switch (userDecision) {
        case '1':
            logIn();
            break;
        case '2':
            registerNewUser();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Wrong character. Try again." << endl << endl;
            system("pause");
            break;
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
    User loggedUser = XMLUser.logIn();
    if(activeUser.getLogin() == loggedUser.getLogin())
        userIsLogIn = false;
    else{
        activeUser = loggedUser;
        userIsLogIn = true;
    }
}
