#include <iostream>

using namespace std;
int iterationNumbers =0;
long long int checkingNumber = 0;
bool isPrimeNumber(long long number);
int main()
{
    cin >> iterationNumbers;
    for(int i =0 ;i < iterationNumbers; i++)
    {
        cin >> checkingNumber;
        if(isPrimeNumber(checkingNumber))
            cout << "TAK" <<endl;
        else
            cout << "NIE" <<endl;
    }
}

bool isPrimeNumber(long long number)
{
    int dividers = number/2;
    bool result = true;
    if(number == 2) {result = true;}
    if(number == 1) {result = false;}
    for(int j = 2; j <= dividers; j++)
    {
        if(number % j == 0) {result = false; break;}
    }
    return result;
}
