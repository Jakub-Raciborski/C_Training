#include "StringMethods.h"

int StringMethods::countDoubleBackslahesInString(const string WORD_TO_CHECK) {
    const int LENGTH_OF_WORD = WORD_TO_CHECK.length();
    int backslashesCounter = 0;


    for(int i=0; i<LENGTH_OF_WORD; i++) {
        if(WORD_TO_CHECK[i] == '\\')
            backslashesCounter++;
    }

    return backslashesCounter;
}
bool StringMethods::isNumber(string wordToCheck) {
    const int WORD_LENGTH = wordToCheck.length();
    for(int i=0; i<WORD_LENGTH; i++) {
        if(!isdigit(wordToCheck[i]))
            return false;
    }
    return true;
}
bool StringMethods::isFloatNumber(string wordToCheck) {
    const int WORD_LENGTH = wordToCheck.length();
    bool dotFound = false;
    for(int i=0; i<WORD_LENGTH; i++) {
        if(!isdigit(wordToCheck[i]) && !dotFound && i>0 && wordToCheck[i] == '.')
            dotFound = true;
        else if(!isdigit(wordToCheck[i]) && !dotFound && wordToCheck[i] != '.')
            return false;
        else if(!isdigit(wordToCheck[i]) && dotFound && wordToCheck[i] == '.')
            return false;
    }
    return true;
}
string StringMethods::changeCommaToDot(string wordToChange){
    const int WORD_LENGTH = wordToChange.length();
    string newWord = "";
    for(int i=0; i<WORD_LENGTH; i++){
        if(wordToChange[i]==',')
            newWord += '.';
        else
            newWord += wordToChange[i];
    }
    return newWord;
}
