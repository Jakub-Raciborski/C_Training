#include <iostream>

using namespace std;
void ObliczPole();
int main()
{
    ObliczPole();
}

void ObliczPole()
{
    int liczba_Iteracji = 0;
    cin >> liczba_Iteracji;
    for(int i = 0; i < liczba_Iteracji; i++)
    {
        int kroki = 0;
        cin >> kroki;
        cout <<(kroki * kroki) << endl;
    }
}
