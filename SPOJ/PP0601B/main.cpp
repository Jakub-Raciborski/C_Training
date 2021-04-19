#include <iostream>

using namespace std;
void SzukajLiczb();
int main()
{
    SzukajLiczb();
}

void SzukajLiczb()
{
   int liczba_Iteracji;
   cin >> liczba_Iteracji;
   for(int i = 0; i < liczba_Iteracji; i++)
   {
       int n, x, y;
       cin >>n>>x>>y;
       for(int j=1;j<n;j++)
       {
           if((j % x)== 0 && !((j % y)== 0))
              cout << j << " ";
       }
       cout << endl;
   }
}
