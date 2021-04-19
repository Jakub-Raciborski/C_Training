#include <iostream>

using namespace std;
void CzyIscDoSklepu();
int main()
{
    CzyIscDoSklepu();
}

void CzyIscDoSklepu()
{
    int liczba_iteracji, waga_paczka, ilosc_kotow, max_udzwig;
    cin >> liczba_iteracji;
    for(int i = 0;i < liczba_iteracji;i++)
    {
        cin>>ilosc_kotow>>max_udzwig>>waga_paczka;
        if(ilosc_kotow*waga_paczka > max_udzwig)
            cout << "no" << endl;
        else
            cout << "yes" <<endl;
    }
}
