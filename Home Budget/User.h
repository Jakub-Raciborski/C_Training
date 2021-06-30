#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    string name;
    string surname;
    string login;
    string password;
public:
    User();
    void setName(string name);
    void setSurname(string surname);
    void setLogin(string login);
    void setPassword(string password);
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

};

#endif // USER_H
