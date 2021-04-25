#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <cstdio>

using namespace std;

struct Person {
    int id = 0;
    string surname, name, email, address, phoneNumber;
};
struct User {
    string userName, password;
    int id;
};


void loadPersonDataFromFileToAddressBook(vector<Person> &vectorToFill, const int USER_ID);
Person createNewPerson(int ID, string name, string surname, string phoneNumber, string email, string address);
int returnNumberOfFirstFreeLineInTXTFile(const string FILE_NAME);
void savePersonDataInAddressBookFile(Person personToAdd, const int USER_ID);
void addNewPersonToAddressBook(vector<Person> &addressBook, const int USER_ID, const int PERSON_ID);
void displayPersonData(const Person PERSON);
void searchPersonByName(const vector<Person> &ADDRESS_BOOK);
void searchPersonBySurname(const vector<Person> &ADDRESS_BOOK);
void displayAllPersons(const vector<Person> &ADDRESS_BOOK);
void askUserForDecision(vector<Person> &addressBook, int &currentUserID, int &highestPersonID);
void deletePersonFromBook(vector<Person> &addressBook);
int askUserAboutPerson(const vector<Person> &ADDRESS_BOOK);
bool askUserIfIsSure();
void clearConsole();
void prepareConsoleForNextTask();
int checkFirstNumberInString(string textLine);
void replaceFile(string oldFileName, string newFileName);
string createNewPersonDataText(const int USER_ID, Person person);
void replacePersonInAddressBookFile(const int PERSON_TO_CHANGE_ID, string NEW_PERSON_DATA);
void editPersonData(vector<Person> &addressBook, const int PERSON_ID);
void findPersonToEdit(vector<Person> &addressBook, const int USER_ID);
void displayMenu();
void displayLoginMenu();
void createNewAccount();
int checkAvailableUserID();
void saveDataInUserFile(const User USER_TO_ADD);
void changePassword(const int USER_ID);
string createUserDataWithNewPassword(string  userData);
User logIn();
User findAccountInFile(const string ACCOUNT_NAME);
void addressBook();

int main() {
    addressBook();
}
Person createNewPerson(int ID, string surname, string name, string email, string address, string phoneNumber) {
    Person newPerson;
    newPerson.surname = surname;
    newPerson.name = name;
    newPerson.email = email;
    newPerson.address = address;
    newPerson.phoneNumber = phoneNumber;
    newPerson.id = ID;
    return newPerson;
}
int returnNumberOfFirstFreeLineInTXTFile(const string FILE_NAME){
    fstream fileToCheck;
    fileToCheck.open(FILE_NAME);
    string oneTextLine;
    int lineCounter=0;
    if(fileToCheck.good()) {
        do {
            getline(fileToCheck, oneTextLine);
            lineCounter++;
        } while(oneTextLine != "");
        return lineCounter;
    }
    else
        return 1;
}
void loadPersonDataFromFileToAddressBook(vector<Person> &vectorToFill, const int USER_ID) {
    string newLine;
    fstream addressBookFile;
    addressBookFile.open("addressBook.txt");
    int userIDAssignedToPersonInAddressBook = 0;
    if(addressBookFile.good()) {
        while(getline(addressBookFile, newLine)){
            bool userAndAddressIDAreEqual = false;
            const int LENGTH_OF_TEXT = newLine.size();
            int letterNumber = 0, personDataPart = 0;
            string personData[7];
            for(letterNumber; letterNumber<LENGTH_OF_TEXT; letterNumber++) {
                if(personDataPart == 2 && !userAndAddressIDAreEqual) {
                    userIDAssignedToPersonInAddressBook = atoi(personData[1].c_str());
                    if(USER_ID == userIDAssignedToPersonInAddressBook)
                        userAndAddressIDAreEqual = true;
                    else
                        break;
                }
                if(newLine[letterNumber]!='|')
                    personData[personDataPart] += newLine[letterNumber];
                else
                    personDataPart++;
            }
            if(userIDAssignedToPersonInAddressBook == USER_ID)
                vectorToFill.push_back(createNewPerson(atoi(personData[0].c_str()), personData[2], personData[3], personData[4], personData[5], personData[6]));
        }
    }
    addressBookFile.close();
}
void savePersonDataInAddressBookFile(Person personToAdd, const int USER_ID) {
    fstream addressBookFile;
    addressBookFile.open("addressBook.txt",ios::out|ios::app);
    addressBookFile<<personToAdd.id<<"|"<<USER_ID<<"|"<<personToAdd.surname<<"|"<<personToAdd.name<<"|"<<
                   personToAdd.email<<"|"<<personToAdd.address<<"|"<<personToAdd.phoneNumber<<endl;
    addressBookFile.close();
}
void addNewPersonToAddressBook(vector<Person> &addressBook, const int USER_ID, const int PERSON_ID) {
    string surname, email, address, number, name;
    system("cls");
    cout<<"Enter surname:\n";
    getline(cin, surname);
    cout<<"Enter name:\n";
    getline(cin, name);
    cout<<"Enter email:\n";
    getline(cin, email);
    cout<<"Enter address:\n";
    getline(cin, address);
    cout<<"Enter phone number:\n";
    getline(cin, number);
    system("cls");
    Person newPerson = createNewPerson(PERSON_ID, surname, name, email, address, number);
    addressBook.push_back(newPerson);
    savePersonDataInAddressBookFile(newPerson, USER_ID);
}
void displayPersonData(const Person PERSON) {
    cout<<PERSON.id<<". "<<PERSON.name<<" "<<PERSON.surname<<"| ";
    cout<<PERSON.address<<"| "<<PERSON.email<<"| "<<PERSON.phoneNumber<<endl;
}
void clearConsole() {
    system("pause");
    system("cls");
}
void prepareConsoleForNextTask() {
    cin.ignore();
    system("pause");
    system("cls");
}
void searchPersonByName(const vector<Person> &ADDRESS_BOOK) {
    bool atLeastOnePersonFound = false;
    string nameToFind;
    cout<<"Enter the name:\n";
    cin>>nameToFind;
    const int NUMBER_OF_PERSONS_IN_ADDRESS_BOOK = ADDRESS_BOOK.size();
    for(int i=0; i<NUMBER_OF_PERSONS_IN_ADDRESS_BOOK; i++) {
        if(nameToFind==ADDRESS_BOOK[i].name) {
            displayPersonData(ADDRESS_BOOK[i]);
            atLeastOnePersonFound = true;
        }
    }
    if(!atLeastOnePersonFound)
        cout<<"No search results.\n";
    prepareConsoleForNextTask();
}
void searchPersonBySurname(const vector<Person> &ADDRESS_BOOK) {
    bool atLeastOnePersonFound = false;
    string surnameToFind;
    cout<<"Enter the surname:\n";
    cin>>surnameToFind;
    int NUMBER_OF_PERSONS_IN_ADDRESS_BOOK = ADDRESS_BOOK.size();
    for(int i=0; i<NUMBER_OF_PERSONS_IN_ADDRESS_BOOK; i++) {
        if(surnameToFind==ADDRESS_BOOK[i].surname) {
            displayPersonData(ADDRESS_BOOK[i]);
            atLeastOnePersonFound = true;
        }
    }
    if(!atLeastOnePersonFound)
        cout<<"No search results.\n";
    prepareConsoleForNextTask();
}
void displayAllPersons(const vector<Person> &ADDRESS_BOOK) {
    system("cls");
    const int AMOUNT_OF_PERSONS = ADDRESS_BOOK.size();
    for(int i=0; i<AMOUNT_OF_PERSONS; i++) {
        displayPersonData(ADDRESS_BOOK[i]);
    }
}
void displayMenu() {
    cout<<"Write number to choose:\n1. Add new person to the address book.\n2. Search the address book by name.\n";
    cout<<"3. Search the address book by surname.\n4. Display all persons from the address book.\n5. Delete Person\n";
    cout<<"6. Edit Person\n7. Change password.\n8. Log out.\n9. Close the program.\n";
}
int askUserAboutPerson(const vector<Person> &ADDRESS_BOOK) {
    while(true) {
        displayAllPersons(ADDRESS_BOOK);
        cout<<"Choose person by writing ID: \n";
        string userAnswer;
        cin>>userAnswer;
        const int CHOOSED_PERSON_ID =atoi(userAnswer.c_str());
        const int AMOUNT_OF_PERSONS_IN_ADDRESSBOOK = ADDRESS_BOOK.size();
        const int HIGHEST_ID_IN_BOOK = ADDRESS_BOOK[AMOUNT_OF_PERSONS_IN_ADDRESSBOOK-1].id;
        if(HIGHEST_ID_IN_BOOK == 0)
            return 0;
        if(CHOOSED_PERSON_ID>0 && CHOOSED_PERSON_ID<=HIGHEST_ID_IN_BOOK) {
            return CHOOSED_PERSON_ID;
        } else {
            cout<<"ID number is wrong. Person does not exist.\n";
            clearConsole();
        }
    }
}
bool askUserIfIsSure() {
    cout<<"To confirm press 'y'\n";
    const char USER_DECISION = getch();
    cout<<USER_DECISION<<endl;
    if(USER_DECISION == 'y')
        return true;
    else
        return false;
}
int checkFirstNumberInString(string textLine){
    const int LENGTH_OF_TEXT = textLine.size();
    string firstNumber = "";
    for(int i=0; i<LENGTH_OF_TEXT; i++){
        if(textLine[i] != '|')
            firstNumber += textLine[i];
        else
            break;
    }
    return atoi(firstNumber.c_str());
}
void replaceFile(string oldFileName, string newFileName){
    const char *OLD_FILE_NAME = oldFileName.c_str();
    const char *NEW_FILE_NAME = newFileName.c_str();
    if(remove(OLD_FILE_NAME)==0)
        rename(NEW_FILE_NAME,OLD_FILE_NAME);
}
void replacePersonInAddressBookFile(const int PERSON_TO_CHANGE_ID, string NEW_PERSON_DATA) {
    fstream newAddressBookFile, oldAddressBookFile;
    oldAddressBookFile.open("addressBook.txt",ios::in);
    newAddressBookFile.open("addressBook_TEMP.txt",ios::out);
    string textLine = "";
    int currentUserID = 0;
    while(getline(oldAddressBookFile,textLine)){
        currentUserID = checkFirstNumberInString(textLine);
        if(currentUserID == PERSON_TO_CHANGE_ID)
            newAddressBookFile<<NEW_PERSON_DATA<<endl;
        else
            newAddressBookFile<<textLine<<endl;
    }
    oldAddressBookFile.close();
    newAddressBookFile.close();
    replaceFile("addressBook.txt","addressBook_TEMP.txt");
}
void deletePersonFromBook(vector<Person> &addressBook) {
    if(addressBook.size() != 0) {
        const int PERSON_ID_TO_DELETE = askUserAboutPerson(addressBook);
        vector<Person>::iterator itr = addressBook.begin();
        vector<Person>::iterator lastPerson = addressBook.end();
        bool personFound = false;
        for(itr; itr!=lastPerson; itr++) {
            Person checkingPerson = *itr;
            if(checkingPerson.id == PERSON_ID_TO_DELETE) {
                cout<<"You choose to delete:\n";
                displayPersonData(checkingPerson);
                personFound = true;
                bool userConfirmation = false;
                userConfirmation = askUserIfIsSure();
                if(userConfirmation) {
                    addressBook.erase(itr);
                    string placeholderPerson = to_string(checkingPerson.id) + "|0|Deleted Person";
                    replacePersonInAddressBookFile(checkingPerson.id,placeholderPerson);
                    break;
                }
            }
        }
        if(!personFound)
            cout<<"The selected person has already been deleted.\n";
    } else
        cout<<"Address book is empty\n";
    prepareConsoleForNextTask();
}
string createNewPersonDataText(const int USER_ID, Person person){
    string newPersonData = to_string(person.id)+"|"+to_string(USER_ID)+"|"+person.surname+"|"+person.name+"|"+
    person.email+"|"+person.address+"|"+person.phoneNumber;
    return newPersonData;
}
void editPersonData(vector<Person> &addressBook, const int PERSON_ID) {
    bool editModeIsActive = true;
    while(editModeIsActive) {
        cout<<"Choose what do you want to edit.\n1. Name: "<<addressBook[PERSON_ID].name<<"\n2. Surname: "<<addressBook[PERSON_ID].surname<<
            "\n3. Phone number: "<<addressBook[PERSON_ID].phoneNumber<<"\n4. Email: "<<addressBook[PERSON_ID].email<<
            "\n5. Address: "<<addressBook[PERSON_ID].address<<"\n6. Exit\n";
        const char USER_DECISION = getch();
        system("cls");
        switch ( USER_DECISION ) {
        case '1': {
            cout<<"Write new name:\n";
            cin>>addressBook[PERSON_ID].name;
            break;
        }
        case '2': {
            cout<<"Write new surname:\n";
            cin>>addressBook[PERSON_ID].surname;
            break;
        }
        case '3': {
            cout<<"Write new phone number:\n";
            cin>>addressBook[PERSON_ID].phoneNumber;
            break;
        }
        case '4': {
            cout<<"Write new email:\n";
            cin>>addressBook[PERSON_ID].email;
            break;
        }
        case '5': {
            do {
                system("cls");
                cout<<"Write new address:\n";
                getline(cin,addressBook[PERSON_ID].address);
            } while(addressBook[PERSON_ID].address=="");
            break;
        }
        case '6': {
            editModeIsActive=false;
        }
        }
    }
}
void findPersonToEdit(vector<Person> &addressBook, const int USER_ID) {
    const int AMOUNT_OF_PERSONS_IN_BOOK = addressBook.size();
    if(AMOUNT_OF_PERSONS_IN_BOOK!=0) {
        const int ID_OF_CHOOSED_PERSON = askUserAboutPerson(addressBook);
        int personNumber = -1;
        for(int i=0; i<AMOUNT_OF_PERSONS_IN_BOOK; i++) {
            if(addressBook[i].id == ID_OF_CHOOSED_PERSON) {
                personNumber = i;
                break;
            }
        }
        if(personNumber>=0) {
            editPersonData(addressBook, personNumber);
            string newPersonData = createNewPersonDataText(USER_ID, addressBook[personNumber]);
            replacePersonInAddressBookFile(ID_OF_CHOOSED_PERSON,newPersonData);
        } else
            cout<<"ID number is wrong. Person does not exist.\n";
    } else
        cout<<"Address book is empty\n";
    prepareConsoleForNextTask();
}
string createUserDataWithNewPassword(string  userData) {
    const int LENGTH_OF_LINE = userData.size();
    int verticalBarCounter = 0;
    string newPassword = "wrong!!!", newUserData = "";
    for(int i=0; i<LENGTH_OF_LINE; i++) {
        if(verticalBarCounter == 2 )
            break;
        else if(userData[i] == '|')
            verticalBarCounter++;
        newUserData += userData[i];
    }
    cout<<"Write new password:\n";
    getline(cin, newPassword);
    newUserData +=newPassword;
    return newUserData;
}
void changePassword(const int USER_ID) {
    fstream oldUsersFile, newUsersFile;
    oldUsersFile.open("Users.txt",ios::in);
    newUsersFile.open("Users_temp.txt",ios::out);
    int userCounter = 0;
    string userData = "";
    while(getline(oldUsersFile,userData)) {
        userCounter++;
        if(userCounter == USER_ID)
            newUsersFile<<createUserDataWithNewPassword(userData)<<endl;
        else
            newUsersFile<<userData<<endl;
    }
    oldUsersFile.close();
    newUsersFile.close();;
    replaceFile("Users.txt","Users_temp.txt");
}
void askUserForDecision(vector<Person> &addressBook, int &currentUserID, int &highestPersonID) {
    while(currentUserID>0) {
        const char USER_DECISION = getch();
        system("cls");
        displayMenu();
        switch ( USER_DECISION ) {
        case '1': {
            addNewPersonToAddressBook(addressBook, currentUserID, highestPersonID);
            highestPersonID++;
            displayMenu();
            break;
        }
        case '2': {
            searchPersonByName(addressBook);
            displayMenu();
            break;
        }
        case '3': {
            searchPersonBySurname(addressBook);
            displayMenu();
            break;
        }
        case '4': {
            displayAllPersons(addressBook);
            clearConsole();
            displayMenu();
            break;
        }
        case '5': {
            deletePersonFromBook(addressBook);
            displayMenu();
            break;
        }
        case '6': {
            findPersonToEdit(addressBook, currentUserID);
            displayMenu();
            break;
        }
        case '7':{
            changePassword(currentUserID);
            clearConsole();
            displayMenu();
            break;
        }
        case '8': {
            currentUserID = 0;
            addressBook.clear();
            break;
        }
        case '9':
            exit(0);
        }
    }
}
void displayLoginMenu() {
    cout<<"Write number to choose:\n1. Log in\n2. Create new account\n3. Exit\n";
}

int checkAvailableUserID() {
    int userCounter = 1;
    string newLine;
    fstream usersFile;
    usersFile.open("Users.txt",ios::in);
    if(usersFile.good()) {
        ifstream in("Users.txt");
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        while(getline(cin, newLine)) {
            userCounter++;
        }
        cin.rdbuf(cinbuf);
        in.close();
    }
    usersFile.close();
    return userCounter;
}
void saveDataInUserFile(const User USER_TO_ADD) {
    fstream userFile;
    userFile.open("Users.txt",ios::out|ios::app);
    userFile<<USER_TO_ADD.id<<"|"<<USER_TO_ADD.userName<<"|"<<USER_TO_ADD.password<<endl;
    userFile.close();
}
void createNewAccount() {
    string name, password;
    cout<<"Enter name:\n";
    getline(cin, name);
    cout<<"Enter password\n";
    getline(cin, password);
    const int ID = checkAvailableUserID();
    const User NEW_USER = {name, password, ID};
    saveDataInUserFile(NEW_USER);
}
User findAccountInFile(const string ACCOUNT_NAME) {
    fstream file;
    file.open("Users.txt");
    User foundUser = {"","",0};
    string textLine = "";
    do {
        string userData[3] = {"","",""};
        getline(file,textLine);
        const int AMOUNT_OF_LETTERS = textLine.size();
        int userDataCounter = 0;
        for(int i=0; i<AMOUNT_OF_LETTERS; i++ ) {
            if(textLine[i] != '|')
                userData[userDataCounter] += textLine[i];
            else
                userDataCounter++;
        }
        if(userData[1] == ACCOUNT_NAME) {
            foundUser = {userData[1], userData[2], atoi(userData[0].c_str())};
            return foundUser;
        }
    } while(textLine != "");
    return foundUser;
}
User logIn() {
    const User EMPTY_USER = {"","",0};
    fstream userFile;
    userFile.open("Users.txt");
    if(userFile.good()) {
        string accountName, consolePassword;
        cout<<"Enter account name:\n";
        getline(cin, accountName);
        User user = findAccountInFile(accountName);
        if(user.id > 0) {
            int loginCounter = 3;
            while(loginCounter>0) {
                cout<<"Enter the password:\n";
                getline(cin, consolePassword);
                if(consolePassword == user.password) {
                    cout<<"Successful login\n";
                    system("pause");
                    return user;
                } else {
                    loginCounter--;
                    cout<<loginCounter<<" login attempts remaining.\n";
                }
            }
        } else
            cout<<"User "<<accountName<<" does not exist.\n";
    } else
        cout<<"No users in the database\n";
    userFile.close();
    system("pause");
    return EMPTY_USER;
}
void addressBook() {
    vector<Person> addressBook;
    int highestFreePersonID = returnNumberOfFirstFreeLineInTXTFile("addressBook.txt");
    while(true) {
        User loggedUser = {"","",0};
        while(loggedUser.id == 0) {
            system("cls");
            displayLoginMenu();
            const int USER_DECISION = getch();
            switch(USER_DECISION) {
            case '1': {
                loggedUser = logIn();
                break;
            }
            case '2': {
                createNewAccount();
                break;
            }
            case '3': {
                exit(0);
            }
            }
        }
        system("cls");
        while(loggedUser.id > 0) {
            loadPersonDataFromFileToAddressBook(addressBook, loggedUser.id);
            displayMenu();
            askUserForDecision(addressBook, loggedUser.id, highestFreePersonID);
        }
    }
}
