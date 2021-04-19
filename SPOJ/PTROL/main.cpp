#include <iostream>

using namespace std;
int ileIteracji=0;
void przesunElementyWLewo();
int main()
{
    cin >> ileIteracji;
    for(int i=0;i<ileIteracji;i++)
    {
        przesunElementyWLewo();
    }
}
void przesunElementyWLewo()
{
    int ileElementow=0;
    cin>>ileElementow;
    int *tablica;
    tablica = new int[ileElementow];
    for(int i=0;i<ileElementow;i++)
    {
        cin>>tablica[i];
    }
    for(int j=1;j<ileElementow;j++)
    {
        cout<<tablica[j]<<" ";
    }
    cout<<tablica[0]<<endl;
}
