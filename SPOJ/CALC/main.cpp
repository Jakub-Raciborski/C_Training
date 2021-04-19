#include <iostream>

using namespace std;
int liczba1,liczba2;
char instrukcja;
void dodawanie(int liczba1, int liczba2);
void odejmowanie(int odjemna, int odjemnik);
void mnozenie(int liczba1, int liczba2);
void dzielenie(int dzielna, int dzielnik);
void modulo(int dzielna, int dzielnik);
bool petla=true;
int main()
{
    do
    {
        cin >>instrukcja>>liczba1>>liczba2;
        if(liczba1!=0 && liczba2!=0 && instrukcja!='e')
        {
            switch(instrukcja)
            {
                case '+': dodawanie(liczba1, liczba2); break;
                case '-': odejmowanie(liczba1, liczba2); break;
                case '*': mnozenie(liczba1, liczba2); break;
                case '/': dzielenie(liczba1, liczba2); break;
                case '%': modulo(liczba1, liczba2); break;
            }
            liczba1=0;
            liczba2=0;
            instrukcja='e';
        }
        else
            petla = false;
    }while(petla);
}

void dodawanie(int liczba1, int liczba2)
{
    cout<<liczba1+liczba2<<endl;
}
void odejmowanie(int odjemna, int odjemnik)
{
    cout<<odjemna-odjemnik<<endl;
}
void mnozenie(int liczba1, int liczba2)
{
    cout<<liczba1*liczba2<<endl;
}
void dzielenie(int dzielna, int dzielnik)
{
    cout<<dzielna/dzielnik<<endl;
}
void modulo(int dzielna, int dzielnik)
{
    cout <<dzielna%dzielnik<<endl;
}
