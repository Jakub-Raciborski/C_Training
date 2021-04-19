#include <iostream>

using namespace std;
int ileIteracji;
void sortuj();
int test = 0;
int main()
{
    cin >>ileIteracji;
    for(int i =0; i<ileIteracji; i++)
    {
        sortuj();
    }
}
void sortuj()
{
    int zakresTablicy=0;
    cin>>zakresTablicy;
    int *tablica;
    tablica = new int[zakresTablicy];
    for(int i=0; i<zakresTablicy;i++)
    {
        cin>>tablica[i];
    }
    for(int parzyste=1;parzyste<zakresTablicy;parzyste+=2)
    {
        cout << tablica[parzyste]<<" ";
    }
    for(int nieparzyste=0;nieparzyste<zakresTablicy;nieparzyste+=2)
    {
        cout << tablica[nieparzyste]<<" ";
    }
    cout<<endl;
}
