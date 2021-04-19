#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;
void rollDice();

int main() {
    srand(time(NULL));
    while(true) {
        cout << "Press Enter roll a dice." << endl;
        getchar();
        rollDice();
    }
}
void rollDice() {
    const int RESULT = rand()%6 +1;
    if(RESULT==1)
        cout<<"   \n . \n   \n";
    else if(RESULT==2)
        cout<<"  .\n   \n.  \n";
    else if(RESULT==3)
        cout<<"  .\n . \n.  \n";
    else if(RESULT==4)
        cout<<". .\n   \n. .\n";
    else if(RESULT==5)
        cout<<". .\n . \n. .\n";
    else if(RESULT==6)
        cout<<". .\n. .\n. .\n";
}
