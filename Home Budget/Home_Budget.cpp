#include "Date.h"
#include "HomeBudget.h"
#include "XMLFileManager.h"
#include "StringMethods.h"

using namespace std;

int main()
{
    /*HomeBudget *homeBudget = new HomeBudget();
    homeBudget->displayMainMenu();
    Date currentDate;
    cout<<currentDate.getDateSignature();
    delete homeBudget;*/
    XMLFileManager newFile("C:\\HomeBudget\\Plik.XML");
    const char* abc = "C:\\HomeBudget\\Plik.XML";
    cout<<StringMethods::countDoubleBackslahesInString(abc);
}
