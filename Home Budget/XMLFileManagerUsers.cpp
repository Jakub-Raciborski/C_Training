#include "XMLFileManagerUsers.h"

User XMLFileManagerUsers::getActiveUser() {
    return activeUser;
}
bool XMLFileManagerUsers::checkUserAlreadyExist(string login) {
    XMLFile.ResetPos();
    while(true) {
        if(XMLFile.FindElem()) {
            XMLFile.IntoElem();
            XMLFile.FindElem("Login");
            if(login == XMLFile.GetData())
                return true;
            else {
                XMLFile.OutOfElem();
                continue;
            }
        } else
            return false;
    }
}
void XMLFileManagerUsers::saveUserData(User newUser) {
    string newUserLogin = newUser.getLogin();
    if(checkUserAlreadyExist(newUserLogin)) {
        cout<<"User "<<newUserLogin<<" already exist\n";
        system("pause");
    } else {
        XMLFile.ResetPos();
        XMLFile.AddElem(newUserLogin);
        XMLFile.IntoElem();
        XMLFile.AddElem("Name", newUser.getName());
        XMLFile.AddElem("Surname", newUser.getSurname());
        XMLFile.AddElem("Login", newUserLogin);
        XMLFile.AddElem("Password", newUser.getPassword());
        if(XMLFile.Save(FILE_PATH))
            cout<<"User account created succesfully.\n";
        else
            cout<<"Something went wrong. Try again.\n";
        system("pause");
    }
}
bool XMLFileManagerUsers::checkUserPassword(string password) {
    string passwordToCompare=" ";
    for(int i=3; i>=1; i--) {
        cout<<"Write password:\n";
        passwordToCompare = InputStream::loadLine();
        if(password == passwordToCompare) {
            cout<<"Correct password.\n";
            system("pause");
            return true;
        } else {
            cout<<"Incorrect password. "<<i-1;
            if(i>2)
                cout<<" attempts left.\n";
            else
                cout<<" attempt left.\n";
        }
    }
    system("pause");
    return false;
}
bool XMLFileManagerUsers::logIn() {
    XMLFile.ResetPos();
    string login="", name="", surname="", password="";
    cout<<"Write login:\n";
    login = InputStream::loadLine();
    if(XMLFile.FindElem(login) && login != "") {
        XMLFile.IntoElem();
        XMLFile.FindElem("Password");
        password = XMLFile.GetData();
        if(checkUserPassword(password)) {
            XMLFile.ResetMainPos();
            XMLFile.FindElem("Name");
            name = XMLFile.GetData();
            XMLFile.FindElem("Surname");
            surname = XMLFile.GetData();
            User loggedUser(name,surname,login,password);
            activeUser = loggedUser;
            return true;
        } else
            return false;
    } else {
        cout<<"User "<<login<<" does not exist.\n";
        system("pause");
        return false;
    }
}
