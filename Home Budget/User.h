#ifndef USER_H
#define USER_H

#include "InputStream.h"

using namespace std;

class User{
    string name;
    string surname;
    string login;
    string password;
public:
    User(){};
    void setName();
    void setSurname();
    void setLogin();
    void setPassword();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

    void setAllAttributes();
};

#endif // USER_H
