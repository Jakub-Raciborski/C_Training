#include <iostream>

using namespace std;
bool isLongerThan11(long long number);
bool checkPesel(long long pesel);
long long pesel = 0;
int iterarionsNumbers = 0;
int main()
{
    cin >> iterarionsNumbers;
    for(int i =0; i < iterarionsNumbers;i++)
    {
      cin >> pesel;
      if(isLongerThan11(pesel))
            cout << "N" << endl;
      else
      {
          if(checkPesel(pesel))
            cout << "D" << endl;
          else
            cout << "N" << endl;
      }
    }
}

bool isLongerThan11(long long number)
{
    if(number/100000000000 >= 1)
        return true;
    else
        return false;
}
bool checkPesel(long long pesel)
{
    long long divisor = 10000000000;
    int checkArray[11] = {1,3,7,9,1,3,7,9,1,3,1};
    int peselComponents[11];
    int result =0;
    for(int i =0;i<11;i++)
    {
        peselComponents[i] = pesel/divisor;
        result = result + checkArray[i] * peselComponents[i];
        pesel = pesel - peselComponents[i]*divisor;
        divisor = divisor/10;
    }
    if(result % 10 == 0)
        return true;
    else
        return false;
}
