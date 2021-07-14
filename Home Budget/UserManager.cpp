#include "UserManager.h"

void UserManager::processingDecisionFromMainMenu() {
    while(activeUser == NULL) {
        displayMainMenu();
        char userDecision = InputStream::loadOneCharacter();
        switch (userDecision) {
        case '1':
            //LogIn();
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
