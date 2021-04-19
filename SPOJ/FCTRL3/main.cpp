#include <iostream>

using namespace std;

int factorial(int number);
int countDecimals(int number);
int countUnits(int number);

int main() {
    int cycles = 0;
    cin>>cycles;
    for(int i=0; i<cycles; i++) {
        int number = 0;
        cin>>number;
        if(number <= 9) {
            const int DECIMAL_PART = factorial(number)%100;
            cout<<countDecimals(DECIMAL_PART)<<" "<<countUnits(DECIMAL_PART)<<endl;
        } else
            cout<<"0 0\n";
    }
}

int factorial(int number) {
    if(number>1) {
        return number * factorial(number-1);
    } else
        return 1;
}
int countDecimals(int number) {
    return (number/10);
}
int countUnits(int number) {
    return (number%10);
}
