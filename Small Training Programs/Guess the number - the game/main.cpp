#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <time.h>

using namespace std;
int main() {
    while(true) {
        int guess, unknownNumber, attemptsCounter;
        bool winner = false;
        cout<<"Witaj. Zgadnij liczbe z zakresu 1..100:" << endl;
        srand(time(NULL));
        unknownNumber = rand()%100;
            winner = false;
        attemptsCounter = 0;
        do {
            attemptsCounter++;
            cout << "Podaj liczbe: " <<endl;
            cin >> guess;
            if(guess > unknownNumber && guess < 101)
                cout << "Liczba jest zbyt duza!" <<endl;
            else if(guess < unknownNumber && guess >= 1)
                cout << "Liczba jest zbyt niska!" <<endl;
            else if(guess == unknownNumber) {
                cout << "Wygrales!!! Zgadles za "<< attemptsCounter <<" razem." <<endl;
                winner = true;
            } else {
                cout << "Wprowadzono nieprawidlowa wartosc! Wprowadz liczbe z zakresu o 1 do 100.\n";
            }
        } while(!winner);
    }
    return 0;
}
