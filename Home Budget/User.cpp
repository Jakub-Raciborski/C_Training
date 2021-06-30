#include "User.h"

void User::setName(string name){
    this->name = name;
}
void User::setSurname(string surname){
    this->surname = surname;
}
void User::setLogin(string login){
    this->login = login;
}
void User::setPassword(string password){
    this->password = password;
}
string User::getName(){
    return name;
}
string User::getSurname(){
    return surname;
}
string User::getLogin(){
    return login;
}
string User::getPassword(){
    return password;
}
