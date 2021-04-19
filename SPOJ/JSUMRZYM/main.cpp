#include <iostream>
#include <map>

using namespace std;

void initializationRomanNumerals(map<int,string> &romanNumerals);
void addTwoRomanNumerals();
void loadTwoRomanNumbersFromInput(string &number1, string &number2);
int convertRomanToArabicNumber(const string &ROMAN_NUMERAL);
string convertArabicToRomanNumber(int arabicNumber, map<int,string> &ROMAN_NUMERALS);
int roundToDivisor(const int NUMBER_TO_ROUND, const int DIVISOR);

int main() {
    addTwoRomanNumerals();
}

void initializationRomanNumerals(map<int,string> &romanNumerals) {
    romanNumerals[0]="";
    romanNumerals[1]="I";
    romanNumerals[2]="II";
    romanNumerals[3]="III";
    romanNumerals[4]="IV";
    romanNumerals[5]="V";
    romanNumerals[6]="VI";
    romanNumerals[7]="VII";
    romanNumerals[8]="VIII";
    romanNumerals[9]="IX";
    romanNumerals[10]="X";
    romanNumerals[20]="XX";
    romanNumerals[30]="XXX";
    romanNumerals[40]="XL";
    romanNumerals[50]="L";
    romanNumerals[60]="LX";
    romanNumerals[70]="LXX";
    romanNumerals[80]="LXXX";
    romanNumerals[90]="XC";
    romanNumerals[100]="C";
    romanNumerals[200]="CC";
    romanNumerals[300]="CCC";
    romanNumerals[400]="CD";
    romanNumerals[500]="D";
    romanNumerals[600]="DC";
    romanNumerals[700]="DCC";
    romanNumerals[800]="DCCC";
    romanNumerals[900]="CM";
    romanNumerals[1000]="M";
    romanNumerals[2000]="MM";
}
int convertRomanToArabicNumber(const string &ROMAN_NUMERAL) {
    const int AMOUNT_OF_LETTERS = ROMAN_NUMERAL.length();
    int result = 0;
    for(int i=0; i<AMOUNT_OF_LETTERS; i++) {
        if(ROMAN_NUMERAL[i]=='I' && ROMAN_NUMERAL[i+1]=='V') {
            i++;
            result += 4;
        } else if(ROMAN_NUMERAL[i]=='I' && ROMAN_NUMERAL[i+1]=='X') {
            i++;
            result +=9;
        } else if(ROMAN_NUMERAL[i]=='I')
            result += 1;
        else if(ROMAN_NUMERAL[i]=='V')
            result += 5;
        else if(ROMAN_NUMERAL[i]=='X' && ROMAN_NUMERAL[i+1]=='L') {
            i++;
            result += 40;
        } else if(ROMAN_NUMERAL[i]=='X'&&ROMAN_NUMERAL[i+1]=='C') {
            i++;
            result += 90;
        } else if(ROMAN_NUMERAL[i]=='X')
            result += 10;
        else if(ROMAN_NUMERAL[i]=='L')
            result += 50;
        else if(ROMAN_NUMERAL[i]=='C'&&ROMAN_NUMERAL[i+1]=='D') {
            i++;
            result += 400;
        } else if(ROMAN_NUMERAL[i]=='D')
            result += 500;
        else if(ROMAN_NUMERAL[i]=='C'&&ROMAN_NUMERAL[i+1]=='M') {
            i++;
            result += 900;
        } else if(ROMAN_NUMERAL[i]=='C')
            result += 100;
        else if(ROMAN_NUMERAL[i]=='M')
            result += 1000;
    }
    return result;
}
void loadTwoRomanNumbersFromInput(string &number1, string &number2) {
    string inputLine;
    getline(cin,inputLine);
    const int AMOUNT_OF_LETTERS = inputLine.length();
    if(!AMOUNT_OF_LETTERS==0) {
        bool spaceIsFound = false;
        for(int i=0; i<AMOUNT_OF_LETTERS; i++) {
            if(!spaceIsFound && inputLine[i]!=' ') {
                number1 +=inputLine[i];
            } else if(spaceIsFound)
                number2 +=inputLine[i];
            else if(inputLine[i]==' ')
                spaceIsFound = true;
        }
    }
}
int roundToDivisor(const int NUMBER_TO_ROUND, const int DIVISOR) {
        int result = NUMBER_TO_ROUND/DIVISOR;
        result *=DIVISOR;
        return result;
}
string convertArabicToRomanNumber(int arabicNumber, map<int,string> &ROMAN_NUMERALS) {
    string romanNumber = "";
    if(arabicNumber>=1000) {
        const int THOUSANDS = roundToDivisor(arabicNumber, 1000);
        romanNumber += ROMAN_NUMERALS[THOUSANDS];
        arabicNumber -= THOUSANDS;
    }
    if(arabicNumber>=100) {
        const int HUNDREDS = roundToDivisor(arabicNumber, 100);
        romanNumber += ROMAN_NUMERALS[HUNDREDS];
        arabicNumber -= HUNDREDS;
    }
    if(arabicNumber>=10) {
        const int DOZENS = roundToDivisor(arabicNumber, 10);
        romanNumber += ROMAN_NUMERALS[DOZENS];
        arabicNumber -= DOZENS;
    }
    romanNumber += ROMAN_NUMERALS[arabicNumber];
    return romanNumber;
}
void addTwoRomanNumerals() {
    map<int,string> romanNumerals;
    initializationRomanNumerals(romanNumerals);
    while(true) {
        string romanNumber1, romanNumber2;
        loadTwoRomanNumbersFromInput(romanNumber1,romanNumber2);
        if(romanNumber1.length()==0)
            break;
        const int RESULT_OF_ADDING = convertRomanToArabicNumber(romanNumber1)+convertRomanToArabicNumber(romanNumber2);
        cout<<convertArabicToRomanNumber(RESULT_OF_ADDING, romanNumerals)<<endl;
    }
}
