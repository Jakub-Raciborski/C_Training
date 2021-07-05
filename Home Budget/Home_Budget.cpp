#include <iostream>
#include "Date.h"
#include "HomeBudget.h"

using namespace std;

int main()
{
    HomeBudget *homeBudget = new HomeBudget();
    homeBudget->displayMainMenu();
    Date currentDate;
    cout<<currentDate.getDateSignature();
    delete homeBudget;
}
