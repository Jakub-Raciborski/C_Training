#ifndef USER_H
#define USER_H

#include "InputStream.h"

using namespace std;

class User{
    string name;
    string surname;
    string login;
    string password;
    bool active;
public:
    User():active(false){};
    User(string name, string surname, string login, string password)
    :name(name),surname(surname),login(login), password(password), active(true){};
    void setName();
    void setSurname();
    void setLogin();
    void setPassword();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

    void setAllAttributes();
    bool isActive();
    void deactivate();
};

#endif // USER_H
