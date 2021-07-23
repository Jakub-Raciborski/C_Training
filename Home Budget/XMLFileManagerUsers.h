#ifndef XMLFILEMANAGERUSERS_H
#define XMLFILEMANAGERUSERS_H

#include "XMLFileManager.h"

using namespace std;

class  XMLFileManagerUsers :public XMLFileManager {
    bool checkUserAlreadyExist(string login);
    bool checkUserPassword(string password);
    User activeUser;

public:
    XMLFileManagerUsers(const char* PATH)
        :XMLFileManager(PATH) {
        createAllNecessaryFolders();
        XMLFile.Load(FILE_PATH);
    };
    User getActiveUser();

    void saveUserData(User newUser);
    bool logIn();

};
#endif // XMLFILEMANAGERUSERS_H
