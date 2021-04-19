#include <iostream>

using namespace std;
int ileIteracji=0;
void odwrocTablice();
int main()
{
    cin>>ileIteracji;
    for(int i=0; i<ileIteracji;i++)
    {
        odwrocTablice();
    }
}
void odwrocTablice()
{
    int ileIteracji;
    cin>>ileIteracji;
    int *tablica;
    tablica = new int[ileIteracji];
    for(int i=0; i<ileIteracji;i++)
    {
        cin>>tablica[i];
    }
    for(int j=ileIteracji-1;j>=0;j--)
    {
        cout<<tablica[j]<<" ";
    }
    cout<<endl;
}
