#ifndef XMLFILEMANAGERUSERS_H
#define XMLFILEMANAGERUSERS_H

#include "XMLFileManager.h"

using namespace std;

class  XMLFileManagerUsers :public XMLFileManager {
    bool checkUserAlreadyExist(string login);
    bool checkUserPassword(string password);

public:
    XMLFileManagerUsers(const char* PATH)
        :XMLFileManager(PATH) {
        createAllNecessaryFolders();
        XMLFile.Load(FILE_PATH);
    };

    void saveUserData(User newUser);
    User logIn();

};
#endif // XMLFILEMANAGERUSERS_H
