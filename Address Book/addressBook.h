#include "user.h"

using namespace std;

void replaceFile(string oldFileName, string newFileName);
void displayLoginMenu();
void displayMenu();
int checkAvailableUserID();
User findAccountInFile(const string ACCOUNT_NAME);
User logIn();
