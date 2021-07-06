#include "User.h"

void User::setName() {
    cout<<"Write user name\n";
    this->name = InputStream::loadLine();
}
void User::setSurname() {
    cout<<"Write user surname\n";
    this->surname = InputStream::loadLine();
}
void User::setLogin() {
    cout<<"Write user login\n";
    this->login = InputStream::loadLine();
}
void User::setPassword() {
    while(true) {
        cout<<"Write new password\n";
        string password = InputStream::loadLine();
        cout<<"Confirm password\n";
        string confirmPassword = InputStream::loadLine();
        if(password == confirmPassword) {
            this->password = password;
            break;
        }
        else{
            cout<<"Passwords are not identical. Try again.\n";
            system("pause");
            system("cls");
        }
    }
}
string User::getName() {
    return name;
}
string User::getSurname() {
    return surname;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}
void User::setAllAttributes(){
    setName();
    setSurname();
    setLogin();
    setPassword();
}
