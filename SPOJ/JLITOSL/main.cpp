#include <iostream>
#include <map>

using namespace std;

int checkHowManyCycleToDo();
void initializationVerbalNotationOfNumbers(map<unsigned long long int,string> &verbalNotation);
string convertDecimalsAndUnitsToWord(unsigned long long int &number, map<unsigned long long int,string> &verbalNotation);
string convertHundredsToWord(int &number, map<unsigned long long int,string> &verbalNotation);
string convertNumberSmallerThanThousandToWord(int &number, map<unsigned long long int,string> &verbalNotation);
string convertFirstThreePositionOfNumberToWord(unsigned long long int &numberToConvert,const unsigned long long int CONVERSION_LEVEL, map<unsigned long long int,string> &verbalNotation);
void deleteLastSpaces(string &sentence);
unsigned long long int roundToDivisor(const unsigned long long int NUMBER_TO_ROUND, const unsigned long long int DIVISOR);
void convertNumberToWord(const int AMOUNT_OF_NUMBERS_TO_CONVERT);

int main() {
    convertNumberToWord(checkHowManyCycleToDo());
}
int checkHowManyCycleToDo() {
    int cycles=0;
    cin>>cycles;
    return cycles;
}
void initializationVerbalNotationOfNumbers(map<unsigned long long int,string> &verbalNotation) {
    verbalNotation[0]="";
    verbalNotation[1]="jeden ";
    verbalNotation[2]="dwa ";
    verbalNotation[3]="trzy ";
    verbalNotation[4]="cztery ";
    verbalNotation[5]="piec ";
    verbalNotation[6]="szesc ";
    verbalNotation[7]="siedem ";
    verbalNotation[8]="osiem ";
    verbalNotation[9]="dziewiec ";
    verbalNotation[10]="dziesiec ";
    verbalNotation[11]="jedenascie ";
    verbalNotation[12]="dwanascie ";
    verbalNotation[13]="trzynascie ";
    verbalNotation[14]="czternascie ";
    verbalNotation[15]="pietnascie ";
    verbalNotation[16]="szesnascie ";
    verbalNotation[17]="siedemnascie ";
    verbalNotation[18]="osiemnascie ";
    verbalNotation[19]="dziewietnascie ";
    verbalNotation[20]="dwadziescia ";
    verbalNotation[30]="trzydziesci ";
    verbalNotation[40]="czterdziesci ";
    verbalNotation[50]="piecdziesiat ";
    verbalNotation[60]="szescdziesiat ";
    verbalNotation[70]="siedemdziesiat ";
    verbalNotation[80]="osiemdziesiat ";
    verbalNotation[90]="dziewiecdziesiat ";
    verbalNotation[100]="sto ";
    verbalNotation[200]="dwiescie ";
    verbalNotation[300]="trzysta ";
    verbalNotation[400]="czterysta ";
    verbalNotation[500]="piecset ";
    verbalNotation[600]="szescset ";
    verbalNotation[700]="siedemset ";
    verbalNotation[800]="osiemset ";
    verbalNotation[900]="dziewiecset ";
    verbalNotation[1000]="tys. ";
    verbalNotation[1000000]="mln. ";
    verbalNotation[1000000000]="mld. ";
    verbalNotation[1000000000000]="jeden bln. ";
}
unsigned long long int roundToDivisor(const unsigned long long int NUMBER_TO_ROUND, const unsigned long long int DIVISOR) {
    unsigned long long int result = NUMBER_TO_ROUND/DIVISOR;
    result *=DIVISOR;
    return result;
}
void deleteLastSpaces(string &sentence) {
    const int LENGTH = sentence.length();
    if(sentence[LENGTH-1]==' ') {
        string sentenceWithoutSpace ="";
        for(int i=0; i<(LENGTH-1); i++) {
            sentenceWithoutSpace += sentence[i];
        }
        sentence = sentenceWithoutSpace;
    deleteLastSpaces(sentence);
    }
}
string convertDecimalsAndUnitsToWord(int &number, map<unsigned long long int,string> &verbalNotation) {
    int decimalsAndUnits = number%100;
    if (decimalsAndUnits==0)
        return "";
    else if(decimalsAndUnits < 21)
        return verbalNotation[decimalsAndUnits];
    else {
        const int UNITS = decimalsAndUnits%10;
        decimalsAndUnits -= UNITS;
        return (verbalNotation[decimalsAndUnits] + verbalNotation[UNITS]);
    }
}
string convertHundredsToWord(int &number, map<unsigned long long int,string> &verbalNotation) {
    const int hundreds = roundToDivisor(number, 100);
    number -= hundreds;
    return verbalNotation[hundreds];
}
string convertNumberSmallerThanThousandToWord(int &number, map<unsigned long long int,string> &verbalNotation) {
    const string HUNDREDS = convertHundredsToWord(number, verbalNotation);
    const string DECIMAL_AND_UNITS = convertDecimalsAndUnitsToWord(number, verbalNotation);
    return HUNDREDS + DECIMAL_AND_UNITS;
}
string convertFirstThreePositionOfNumberToWord(unsigned long long int &numberToConvert,const unsigned long long int CONVERSION_LEVEL, map<unsigned long long int,string> &verbalNotation) {
    const unsigned long long int CONVERTED_NUMBER = roundToDivisor(numberToConvert,CONVERSION_LEVEL);
    numberToConvert -= CONVERTED_NUMBER;
    int threeFirstNumbersOfConvertedNumber = CONVERTED_NUMBER/CONVERSION_LEVEL;
    string numberInVerbalNotation = convertNumberSmallerThanThousandToWord(threeFirstNumbersOfConvertedNumber,verbalNotation) + verbalNotation[CONVERSION_LEVEL];
    return numberInVerbalNotation;
}
void convertNumberToWord(const int AMOUNT_OF_NUMBERS_TO_CONVERT) {
    map<unsigned long long int,string> verbalNotation;
    initializationVerbalNotationOfNumbers(verbalNotation);
    const unsigned long long int ONE_BILLION = 1000000000, ONE_TRILLION = 1000000000000;
    const unsigned int ONE_THOUSAND = 1000, ONE_MILLION=1000000;

    for(int i=1; i <= AMOUNT_OF_NUMBERS_TO_CONVERT; i++) {
        string numberInVerbalNotation = "";
        unsigned long long int numberToConvert=0;
        cin>>numberToConvert;
        if(numberToConvert == ONE_TRILLION || numberToConvert<21)
            numberInVerbalNotation = verbalNotation[numberToConvert];
        else {
            if(numberToConvert >= ONE_BILLION)
                numberInVerbalNotation += convertFirstThreePositionOfNumberToWord(numberToConvert, ONE_BILLION, verbalNotation);
            if(numberToConvert >= ONE_MILLION)
                numberInVerbalNotation += convertFirstThreePositionOfNumberToWord(numberToConvert, ONE_MILLION, verbalNotation);
            if(numberToConvert >= ONE_THOUSAND)
                numberInVerbalNotation += convertFirstThreePositionOfNumberToWord(numberToConvert, ONE_THOUSAND, verbalNotation);
            int rest = numberToConvert;
            numberInVerbalNotation += convertNumberSmallerThanThousandToWord(rest, verbalNotation);
        }
        deleteLastSpaces(numberInVerbalNotation);
        cout<<numberInVerbalNotation<<endl;
    }
}
