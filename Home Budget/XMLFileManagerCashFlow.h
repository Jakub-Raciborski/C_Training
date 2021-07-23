#ifndef XMLFILEMANAGERCASHFLOW_H
#define XMLFILEMANAGERCASHFLOW_H

#include "XMLFileManager.h"
#include "CashFlow.h"
#include "Date.h"
#include "VariableModification.h"


using namespace std;

class XMLFileManagerCashFlow: public XMLFileManager {
    float askUserAboutAmount();
    Date askUserAboutDate();
    string askUserAboutDescriptionOfCashFlow();
    void saveCashFlowInFile(CashFlow cashFlow);
    string loggedUser;

public:
    XMLFileManagerCashFlow(const char* PATH)
        :XMLFileManager(PATH) {
        XMLFile.Load(FILE_PATH);
    };

    void logInUser(User userToLogIn);
    void logOutUser();
    void addCashFlow();
};
#endif // XMLFILEMANAGERCASHFLOW_H
