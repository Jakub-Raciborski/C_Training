#include <iostream>

using namespace std;
string tekstDoZaszyfrowania;
string szyfruj(string tekst);
char przesunLitereO3WPrawo(char litera);
int main()
{
   do
    {
        tekstDoZaszyfrowania="";
        getline(cin,tekstDoZaszyfrowania);
        cout<<szyfruj(tekstDoZaszyfrowania)<<endl;
    }while(tekstDoZaszyfrowania!="");
}
char przesunLitereO3WPrawo(char litera)
{
    string alfabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<26;i++)
    {
        if(litera==alfabet[i] && i<=22)
        {
            return alfabet[i+3];
        }
        else if(litera==alfabet[i] && i>22)
        {
            return alfabet[(25-i-2)*(-1)];
        }
    }
}
string szyfruj(string tekst)
{
    string szyfr ="";
    int liczbaZnakowTekstu = tekst.size();
    for(int i=0; i<liczbaZnakowTekstu;i++)
    {
        if(tekst[i]==' ')
            szyfr += ' ';
        else
        {
            szyfr += przesunLitereO3WPrawo(tekst[i]);
        }
    }
    return szyfr;
}
