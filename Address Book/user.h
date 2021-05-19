#include <iostream>

using namespace std;

class User{
public:
    string name;
    int ID;

    User();
    User(int, string, string);
    ~User();

    string getPassword();
    void changePassword();
    void saveDataInUserFile();
private:
    string password;
};
