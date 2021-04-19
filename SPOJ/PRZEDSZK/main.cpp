#include <iostream>

using namespace std;

void NajmniejszyIloraz();
int main()
{
    NajmniejszyIloraz();
}

void NajmniejszyIloraz()
{
    int liczba_iteracji, dzielnik1, dzielnik2;
    cin >> liczba_iteracji;
    for(int i=0 ;i < liczba_iteracji ; i++)
    {
        cin >> dzielnik1 >>dzielnik2;
        if(dzielnik1 == dzielnik2)
            cout << dzielnik1 << endl;
        else if(dzielnik1 > dzielnik2)
        {
            for(int j=2; j<=30; j++)
            {
                if((dzielnik2*j)%dzielnik1 == 0 )
                {
                    cout<< dzielnik2*j << endl;
                    break;
                }
            }
        }
        else if(dzielnik1 < dzielnik2)
        {
            for(int k=2; k<=30; k++)
            {
                if((dzielnik1*k)%dzielnik2 == 0 )
                {
                    cout<< dzielnik1*k << endl;
                    break;
                }
            }
        }

    }
}
