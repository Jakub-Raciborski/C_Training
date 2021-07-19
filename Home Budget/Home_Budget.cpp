#include "Date.h"
#include "HomeBudget.h"
#include "XMLFileManager.h"
#include "StringMethods.h"

using namespace std;

int main()
{
    HomeBudget homeBudget;
    homeBudget.startProgram();
    Date currentDate;
    cout<<currentDate.getDateSignature();
}
