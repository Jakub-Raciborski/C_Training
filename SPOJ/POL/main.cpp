#include <iostream>

using namespace std;
void polowaString();
int main()
{
    polowaString();
}
void polowaString()
{
    int liczba_iteracji, dlugosc, polowaDlugosci;
    string wers;
    cin >> liczba_iteracji;
    for(int i =0; i <= liczba_iteracji; i++)
    {
        getline(cin, wers);
        polowaDlugosci = wers.length()/2;
        for(int j= 0; j <= polowaDlugosci-1; j++)
        {
            cout << wers[j];
            if(j==polowaDlugosci-1)
                cout << endl;
        }
    }
}
