#include <iostream>

using namespace std;
int ileIteracji, ileSkladnikow;
int main()
{
    cin >> ileIteracji;
    for(int i = 0; i < ileIteracji; i++)
    {
        int suma = 0;
        int skladnik = 0;
        cin >> ileSkladnikow;
        for(int j =0; j < ileSkladnikow; j++)
        {
            cin >> skladnik;
            suma = suma + skladnik;
        }
        cout << suma << endl;
    }
}
