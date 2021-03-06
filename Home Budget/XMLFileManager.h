#ifndef XMLFILEMANAGER_H
#define XMLFILEMANAGER_H

#include <io.h>
#include <unistd.h>
#include "Markup.h"
#include "StringMethods.h"
#include "User.h"
#include "InputStream.h"

using namespace std;

class XMLFileManager {
protected:
    CMarkup XMLFile;
    const char* FILE_PATH;

    bool checkFolderExist(const char* FOLDER_PATH);
    bool createNewFolder(const char* FOLDER_PATH);
    void addNewFolderIfIsMissing(const string FOLDER_PATH);
    void createAllNecessaryFolders();

public:
    XMLFileManager(const char* PATH)
        :FILE_PATH(PATH) {};

};
#endif // XMLFILEMANAGER_H
