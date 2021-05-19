#include <fstream>
#include "addressBook.h"

using namespace std;


void replaceFile(string oldFileName, string newFileName){
    const char *OLD_FILE_NAME = oldFileName.c_str();
    const char *NEW_FILE_NAME = newFileName.c_str();
    if(remove(OLD_FILE_NAME)==0)
        rename(NEW_FILE_NAME,OLD_FILE_NAME);
}
void displayLoginMenu() {
    cout<<"Write number to choose:\n1. Log in\n2. Create new account\n3. Exit\n";
}
int checkAvailableUserID() {
    int userCounter = 1;
    string newLine;
    fstream usersFile;
    usersFile.open("Users.txt",ios::in);
    if(usersFile.good()) {
        ifstream in("Users.txt");
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        while(getline(cin, newLine)) {
            userCounter++;
        }
        cin.rdbuf(cinbuf);
        in.close();
    }
    usersFile.close();
    return userCounter;
}
User findAccountInFile(const string ACCOUNT_NAME) {
    fstream file;
    file.open("Users.txt");
    User emptyUser(0,"","");
    string textLine = "";
    while(getline(file,textLine)){
        string userData[3] = {"","",""};
        const int AMOUNT_OF_LETTERS = textLine.size();
        int userDataCounter = 0;
        for(int i=0; i<AMOUNT_OF_LETTERS; i++ ) {
            if(textLine[i] != '|')
                userData[userDataCounter] += textLine[i];
            else
                userDataCounter++;
        }
        if(userData[1] == ACCOUNT_NAME) {
            User foundUser(atoi(userData[0].c_str()),userData[1], userData[2]);
            return foundUser;
        }
    }
    return emptyUser;
}
User logIn() {
    const User EMPTY_USER(0,"","");
    fstream userFile;
    userFile.open("Users.txt");
    if(userFile.good()) {
        string accountName, consolePassword;
        cout<<"Enter account name:\n";
        getline(cin, accountName);
        User user = findAccountInFile(accountName);
        if(user.ID > 0) {
            int loginCounter = 3;
            while(loginCounter>0) {
                cout<<"Enter the password:\n";
                getline(cin, consolePassword);
                if(consolePassword == user.getPassword()) {
                    cout<<"Successful login\n";
                    system("pause");
                    return user;
                } else {
                    loginCounter--;
                    cout<<loginCounter<<" login attempts remaining.\n";
                }
            }
        } else
            cout<<"User "<<accountName<<" does not exist.\n";
    } else
        cout<<"No users in the database\n";
    userFile.close();
    system("pause");
    return EMPTY_USER;
}
void displayMenu() {
    cout<<"Write number to choose:\n1. Add new person to the address book.\n2. Search the address book by name.\n";
    cout<<"3. Search the address book by surname.\n4. Display all persons from the address book.\n5. Delete Person\n";
    cout<<"6. Edit Person\n7. Change password.\n8. Log out.\n9. Close the program.\n";
}
