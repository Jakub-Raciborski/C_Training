#include "XMLFileManagerCashFlow.h"

void XMLFileManagerCashFlow::logInUser(User userToLogIn) {
    loggedUser = userToLogIn.getLogin();
    XMLFile.ResetPos();
    if(XMLFile.FindElem(loggedUser))
        XMLFile.IntoElem();
    else {
        XMLFile.AddElem(loggedUser);
        XMLFile.IntoElem();
        XMLFile.Save(FILE_PATH);
    }
}
float XMLFileManagerCashFlow::askUserAboutAmount() {
    float amount = 0;
    while(amount == 0) {
        system("cls");
        cout<<"Enter the amount: \n";
        string user_input = InputStream::loadLine();
        user_input = StringMethods::changeCommaToDot(user_input);
        amount = VariableModification::convertStringToFloat(user_input);
        if(amount == 0) {
            cout<<"You did not enter a number or number is equal to 0. Try again.\n";
            system("pause");
        }
    }
    return amount;
}
Date XMLFileManagerCashFlow::askUserAboutDate() {
    system("cls");
    Date date;
    char userAnswer = 'k';
    while(!(userAnswer=='y' || userAnswer=='n' )) {
        cout<<"Do you want use today's date? (y/n)\n";
        userAnswer = InputStream::loadOneCharacter();
    }
    if(userAnswer=='y') {
        date.setDateToToday();
        return date;
    } else {
        date.setDateNotToToday();
        return date;
    }
}
string XMLFileManagerCashFlow::askUserAboutDescriptionOfCashFlow() {
    string userDescription;
    system("cls");
    cout<<"Enter the description of new money transfer: \n";
    userDescription = InputStream::loadLine();
    return userDescription;
}
void XMLFileManagerCashFlow::saveCashFlowInFile(CashFlow cashFlow) {
    string signature = VariableModification::convertIntToString(cashFlow.getDateSignature());
    string entryName = "Entry" + signature;
    string amount = VariableModification::convertFloatToString(cashFlow.getAmount());
    XMLFile.AddElem(entryName);
    XMLFile.IntoElem();
    XMLFile.AddElem("Amount",amount);
    XMLFile.AddElem("Date", signature);
    XMLFile.AddElem("Description", cashFlow.getDescriptiont());
    XMLFile.Save(FILE_PATH);
    XMLFile.OutOfElem();
}
void XMLFileManagerCashFlow::addCashFlow() {
    float amount= askUserAboutAmount();
    Date date = askUserAboutDate();
    string description = askUserAboutDescriptionOfCashFlow();
    CashFlow cashFlow(amount, date, description);
    saveCashFlowInFile(cashFlow);
}
void XMLFileManagerCashFlow::logOutUser() {
    XMLFile.ResetPos();
    loggedUser = "";
}
float XMLFileManagerCashFlow::loadAmountFromCurrentlySelectedXMLFileEntry() {
    XMLFile.IntoElem();
    XMLFile.FindElem("Amount");
    float amount = VariableModification::convertStringToFloat(XMLFile.GetData());
    XMLFile.OutOfElem();
    return amount;
}
float XMLFileManagerCashFlow::countSumOfCashFlowsOfSelectedPeriod(const int FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE, const int LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE) {
    int checkingSignature = FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE;
    Date checkingDate(FIRST_DAY_OF_SELECTED_PERIOD_SIGNATURE);
    float sumOfCashFlow = 0;
    XMLFile.ResetMainPos();

    while(checkingSignature <= LAST_DAY_OF_SELECTED_PERIOD_SIGNATURE) {
        string entryName = "Entry" + VariableModification::convertIntToString(checkingSignature);
        if(XMLFile.FindElem(entryName))
            sumOfCashFlow += loadAmountFromCurrentlySelectedXMLFileEntry();
        else {
            checkingDate.moveDateToNextDay();
            checkingSignature = checkingDate.getDateSignature();
            XMLFile.ResetMainPos();
        }
    }
    return sumOfCashFlow;
}
