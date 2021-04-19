#include <iostream>

using namespace std;
int ileIteracji,grubasy,ciastkaWPudelku,zjedzoneCiastka=0;
int sekundy=86400;
int ileZjeCiastek(int czasJedzenia, int sekundy);
int ileTrzebaPudelek(int zjedzone, int pojemnoscPudelka);
void glutton();
int main()
{
    glutton();
}
int ileZjeCiastek(int czasJedzenia, int sekundy)
{
    return sekundy/czasJedzenia;
}
int ileTrzebaPudelek(int zjedzone, int pojemnoscPudelka)
{
    int pudelka=0;
    pudelka = zjedzone/pojemnoscPudelka;
    if(zjedzone%pojemnoscPudelka > 0)
        pudelka++;
    return pudelka;
}
void glutton()
{
    cin >> ileIteracji;
    for(int i=0; i<ileIteracji;i++)
    {
        cin >>grubasy>>ciastkaWPudelku;
        int czasJedzenia[grubasy];
        for(int j=0;j<grubasy;j++)
        {
            cin>>czasJedzenia[j];
            zjedzoneCiastka+=ileZjeCiastek(czasJedzenia[j], sekundy);
        }
        cout << ileTrzebaPudelek(zjedzoneCiastka, ciastkaWPudelku)<<endl;
        zjedzoneCiastka = 0;
    }
}
