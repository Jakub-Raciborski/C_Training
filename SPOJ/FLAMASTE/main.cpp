#include <iostream>
#include <sstream>

using namespace std;
int ile=0;
string wyraz;
string uproszeczenie(string wyraz);
string intToString(int doKonwersji);
int main()
{
    cin >> ile;
    for(int i =0; i<ile; i++)
    {
        cin >> wyraz;
        cout << uproszeczenie(wyraz)<<endl;
    }
}
string intToString(int doKonwersji)
{
    ostringstream konwertowana;
    konwertowana << doKonwersji;
    return konwertowana.str();
}

string uproszeczenie(string wyraz)
{
    string uproszczony="";
    int licznik=0;
    int dlugosc=wyraz.size();
    char obecnieSprawdzanaLitera=wyraz[0];
    if(dlugosc>1)
    {
        for(int i=0; i<=dlugosc;i++)
        {
            if(i==dlugosc)
            {
                switch(licznik)
                {
                    case 1:  {uproszczony += obecnieSprawdzanaLitera; break;}
                    case 2:  {uproszczony = uproszczony + obecnieSprawdzanaLitera + obecnieSprawdzanaLitera;break;}
                    default: {uproszczony = uproszczony + obecnieSprawdzanaLitera + intToString(licznik);}
                }
            }
            else if(obecnieSprawdzanaLitera!=wyraz[i] && licznik>2)
            {
                uproszczony = uproszczony + obecnieSprawdzanaLitera + intToString(licznik);
                obecnieSprawdzanaLitera = wyraz[i];
                licznik = 1;
            }
            else if(obecnieSprawdzanaLitera != wyraz[i] && licznik==2)
            {
                uproszczony = uproszczony + obecnieSprawdzanaLitera + obecnieSprawdzanaLitera;
                obecnieSprawdzanaLitera = wyraz[i];
                licznik = 1;
            }
            else if(obecnieSprawdzanaLitera!=wyraz[i] && licznik<2)
            {
                uproszczony += obecnieSprawdzanaLitera;
                obecnieSprawdzanaLitera = wyraz[i];
            }
            else if(obecnieSprawdzanaLitera == wyraz[i])
                licznik++;
        }
    }
    else
        uproszczony = wyraz[0];
    return uproszczony;
}
