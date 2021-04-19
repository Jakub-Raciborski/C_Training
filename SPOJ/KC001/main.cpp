#include <iostream>

using namespace std;
int sumowanieTrzechLiczb();
int main()
{
    cout << sumowanieTrzechLiczb();
}

int sumowanieTrzechLiczb()
{
    int wynik = 0;
    int liczby[3];
    for(int i = 0; i<3; i++)
    {
        cin >> liczby[i];
        wynik += liczby[i];
    }

    return wynik;
}
