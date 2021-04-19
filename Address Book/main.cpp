#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

struct Person {
    string surname;
    string name;
    string email;
    string address;
    string phoneNumber;
};

void loadPersonDataFromFileToAddressBook(vector<Person> &vectorToFill);
Person createNewPerson(string surname, string name, string email, string address, string phoneNumber);
void savePersonDataInAddressBookFile(Person personToAdd);
void addNewPersonToAddressBook(vector<Person> &addressBook);
void displayPersonData(const Person PERSON);
void searchPersonByName(const vector<Person> &ADDRESS_BOOK);
void searchPersonBySurname(const vector<Person> &ADDRESS_BOOK);
void displayAllPersons(const vector<Person> &ADDRESS_BOOK);
void askUserForDecision(vector<Person> &addressBook);
void displayMenu();

int main() {
    vector<Person> addressBook;
    loadPersonDataFromFileToAddressBook(addressBook);
    displayMenu();
    askUserForDecision(addressBook);
}
Person createNewPerson(string surname,string name, string email, string address, string phoneNumber) {
    Person newPerson;
    newPerson.surname = surname;
    newPerson.name = name;
    newPerson.email = email;
    newPerson.address = address;
    newPerson.phoneNumber = phoneNumber;
    return newPerson;
}
void loadPersonDataFromFileToAddressBook(vector<Person> &vectorToFill) {
    fstream addressBookFile;
    addressBookFile.open("addressBook.txt",ios::in);
    if(addressBookFile.good()) {
        ifstream in("addressBook.txt");
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        string surname, buffor, name, email, address, number;
        while(cin>>surname) {
            if(surname=="\n")
                break;
            getline(cin, buffor);
            getline(cin, name);
            getline(cin, email);
            getline(cin, address);
            getline(cin, number);
            vectorToFill.push_back(createNewPerson(surname,name, email, address, number));
        }
        cin.rdbuf(cinbuf); // reset to standard input again
        in.close();
    }
    addressBookFile.close();
}
void savePersonDataInAddressBookFile(Person personToAdd) {
    fstream addressBookFile;
    addressBookFile.open("addressBook.txt",ios::out|ios::app);
    addressBookFile<<personToAdd.surname<<"\n"<<personToAdd.name<<"\n"<<personToAdd.email<<"\n"<<
                   personToAdd.address<<"\n"<<personToAdd.phoneNumber<<endl;
    addressBookFile.close();
}
void addNewPersonToAddressBook(vector<Person> &addressBook) {
    system("cls");
    string surname, email, address, number, name;
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
    Person newPerson = createNewPerson(surname,name,email,address,number);
    addressBook.push_back(newPerson);
    savePersonDataInAddressBookFile(newPerson);
}
void displayPersonData(const Person PERSON) {
    cout<<PERSON.name<<" "<<PERSON.surname<<endl;
    cout<<PERSON.address<<"\n"<<PERSON.email<<"\n"<<PERSON.phoneNumber<<endl;
}
void searchPersonByName(const vector<Person> &ADDRESS_BOOK) {
    system("cls");
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
    cin.ignore();
    system("pause");
    system("cls");
}
void searchPersonBySurname(const vector<Person> &ADDRESS_BOOK) {
    system("cls");
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
    cin.ignore();
    system("pause");
    system("cls");
}
void displayAllPersons(const vector<Person> &ADDRESS_BOOK) {
    system("cls");
    const int AMOUNT_OF_PERSONS = ADDRESS_BOOK.size();
    for(int i=0; i<AMOUNT_OF_PERSONS; i++) {
        displayPersonData(ADDRESS_BOOK[i]);
    }
    system("pause");
    system("cls");
}
void displayMenu() {
    cout<<"Write number to choose:\n1. Add new person to the address book.\n2. Search the address book by name.\n";
    cout<<"3. Search the address book by surname.\n4. Display all persons from the address book. \n5. Close the program.\n";
}
void askUserForDecision(vector<Person> &addressBook) {
    bool programIsRunning = true;
    while(programIsRunning) {
        const char USER_DECISION = getch();
        switch ( USER_DECISION ) {
        case '1': {
            addNewPersonToAddressBook(addressBook);
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
            displayMenu();
            break;
        }
        case '5': {
            programIsRunning = false;
            break;
        }
        }
    }
}
