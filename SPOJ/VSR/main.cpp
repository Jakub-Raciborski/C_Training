#include <iostream>

using namespace std;
int t=0;
int V1,V2;
int main()
{
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >>V1>>V2;
        cout << 2*V1*V2/(V1+V2) << endl;
    }
}
