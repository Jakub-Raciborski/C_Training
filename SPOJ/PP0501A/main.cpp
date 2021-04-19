#include <iostream>
#include <vector>

using namespace std;

int nwd(int a, int b);
int checkWhichNumberIsSmaller(int number1, int number2);
bool checkThatNumberIsCompletelyDivisible(const int DIVIDEND, const int DIVIDER);
vector<int> findAllDividers(int numberToDivide);
vector<int> findAllCommonNumbers(vector<int> numbersBank1, vector<int> numbersBank2);


int main() {
    int amountOfTests = 0;
    cin >> amountOfTests;
    for(int i=0; i<amountOfTests; i++) {
        int number1, number2;
        cin>>number1>>number2;
        cout<<nwd(number1, number2)<<endl;
    }
}
int checkWhichNumberIsSmaller(int number1, int number2) {
    if(number1 < number2)
        return number1;
    else
        return number2;
}
bool checkThatNumberIsCompletelyDivisible(const int DIVIDEND, const int DIVIDER) {
    if(DIVIDEND%DIVIDER == 0)
        return true;
    else
        return false;
}
vector<int> findAllDividers(int numberToDivide) {
    vector<int> dividers;
    while(numberToDivide > 1) {
        for(int i=2; i <= numberToDivide; i++) {
            if(checkThatNumberIsCompletelyDivisible(numberToDivide, i)) {
                dividers.push_back(i);
                numberToDivide /= i;
                break;
            }
        }
    }
    return dividers;
}
vector<int> findAllCommonNumbers(vector<int> numbersBank1, vector<int> numbersBank2) {
    vector<int> commonNumbers;
    int amountOfNumbersInBank1 = numbersBank1.size();
    for(int i=0; i < amountOfNumbersInBank1; i++) {
        vector<int>::iterator itr = numbersBank2.begin();
        vector<int>::iterator lastNumberInBank2 = numbersBank2.end();
        for(itr; itr != lastNumberInBank2; itr++) {
            if(numbersBank1[i]==*itr) {
                commonNumbers.push_back(*itr);
                numbersBank2.erase(itr);
                break;
            }
        }
    }
    return commonNumbers;
}
int nwd(int a, int b) {
    if(a==b)
        return a;
    else if(a==0)
        return b;
    else if(b==0)
        return a;
    else {
        vector<int> dividersOfNumberA, dividersOfNumberB, commonDividers;
        dividersOfNumberA = findAllDividers(a);
        dividersOfNumberB = findAllDividers(b);
        commonDividers = findAllCommonNumbers(dividersOfNumberA, dividersOfNumberB);
        int biggestCommonDivider = 1;
        const int AMOUNT_OF_COMMON_DIVIDERS = commonDividers.size();
        for(int i=0; i<AMOUNT_OF_COMMON_DIVIDERS; i++){
            biggestCommonDivider *= commonDividers[i];
        }
        return biggestCommonDivider;
    }
}
