#include <iostream>

using namespace std;
int ObliczanieMiejsc();
int main()
{
    cout << ObliczanieMiejsc();
}

int ObliczanieMiejsc()
{
    int wynik = 0;
    string daneWejsciowe;
    int skladoweLiczby[5];
    int licznikSkladnikow = 0;
    int szukane_Liczby[4];
    int obecna_Szukana_Liczba = 0;

    getline(cin,daneWejsciowe);
    int dlugoscString = daneWejsciowe.length();
    for(int i = 0; i <= dlugoscString; i++)
    {
        if(daneWejsciowe[i] == 32 || i == dlugoscString)
        {
            switch(licznikSkladnikow)
            {
                case 1: {szukane_Liczby[obecna_Szukana_Liczba] = skladoweLiczby[0]; break;}
                case 2: {szukane_Liczby[obecna_Szukana_Liczba] = skladoweLiczby[0]*10 + skladoweLiczby[1]; break;}
                case 3: {szukane_Liczby[obecna_Szukana_Liczba] = skladoweLiczby[0]*100 + skladoweLiczby[1]*10 + skladoweLiczby[2]; break;}
                case 4: {szukane_Liczby[obecna_Szukana_Liczba] = skladoweLiczby[0]*1000 + skladoweLiczby[1]*100 + skladoweLiczby[2]*10 +skladoweLiczby[3]; break;}
                case 5: {szukane_Liczby[obecna_Szukana_Liczba] = skladoweLiczby[0]*10000 + skladoweLiczby[1]*1000 + skladoweLiczby[2]*100 +skladoweLiczby[3]*10 + skladoweLiczby[4]; break;}
            }
            licznikSkladnikow = 0;
            obecna_Szukana_Liczba++;
        }
        else
        {
            skladoweLiczby[licznikSkladnikow] = daneWejsciowe[i] - 48;
            licznikSkladnikow++;
        }
    }

    return szukane_Liczby[0] * szukane_Liczby[1] + szukane_Liczby[2] * szukane_Liczby[3];
}
