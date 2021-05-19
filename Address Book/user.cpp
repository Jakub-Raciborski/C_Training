#include <fstream>
#include "addressBook.h"

using namespace std;


void User::saveDataInUserFile() {
    fstream userFile;
    userFile.open("Users.txt",ios::out|ios::app);
    userFile<<ID<<"|"<<name<<"|"<<password<<endl;
    userFile.close();
}
string User::getPassword() {
    return password;
}
void User::changePassword() {
    cout<<"Write new password:\n";
    getline(cin, password);
    fstream oldUsersFile, newUsersFile;
    oldUsersFile.open("Users.txt",ios::in);
    newUsersFile.open("Users_temp.txt",ios::out);
    int userCounter = 0;
    string userData = "";
    while(getline(oldUsersFile,userData)) {
        userCounter++;
        if(userCounter == ID)
            newUsersFile<<ID<<"|"<<name<<"|"<<password<<endl;
        else
            newUsersFile<<userData<<endl;
    }
    oldUsersFile.close();
    newUsersFile.close();;
    replaceFile("Users.txt","Users_temp.txt");
}
User::User() {
    ID = checkAvailableUserID();
    cout<<"Enter name:\n";
    getline(cin, name);
    cout<<"Enter password\n";
    getline(cin, password);
    saveDataInUserFile();
}
User::User (int id, string _name, string _password)
    :ID(id),password(_password),name(_name)
{}
User::~User() {
}
