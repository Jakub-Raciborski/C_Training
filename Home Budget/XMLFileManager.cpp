#include "XMLFileManager.h"

bool XMLFileManager::checkFolderExist(const char* FOLDER_PATH) {
    const int FILE_EXIST = access(FOLDER_PATH, F_OK);
    if(FILE_EXIST == 0)
        return true;
    else
        return false;
}
bool XMLFileManager::createNewFolder(const char* FOLDER_PATH) {
    const int FILE_CREATED = mkdir(FOLDER_PATH);
    if(FILE_CREATED == 0)
        return true;
    else
        return false;
}
void XMLFileManager::addNewFolderIfIsMissing(const string FOLDER_PATH) {
    const char* FOLDER_TO_CHECK = FOLDER_PATH.c_str();
    if(!checkFolderExist(FOLDER_TO_CHECK))
        createNewFolder(FOLDER_TO_CHECK);
}
void XMLFileManager::createAllNecessaryFolders() {
    const string FILE_PATH(this->FILE_PATH);
    const int AMOUNT_OF_BACKSLASHES = StringMethods::countDoubleBackslahesInString(FILE_PATH);
    const int PATH_LENGTH = FILE_PATH.length();
    int backshlashesFound = 0;
    string checkingPath = "";
    for(int i=0; i<PATH_LENGTH; i++) {
        if(FILE_PATH[i] == '\\') {
            backshlashesFound++;
            if(backshlashesFound>1) {
                addNewFolderIfIsMissing(checkingPath);
                if(backshlashesFound == AMOUNT_OF_BACKSLASHES)
                    break;
            }
            checkingPath += FILE_PATH[i];
        } else
            checkingPath += FILE_PATH[i];
    }
}
