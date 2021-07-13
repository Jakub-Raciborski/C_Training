#include "StringMethods.h"

int StringMethods::countDoubleBackslahesInString(const string WORD_TO_CHECK){
    const int LENGTH_OF_WORD = WORD_TO_CHECK.length();
    int backslashesCounter = 0;


    for(int i=0; i<LENGTH_OF_WORD; i++){
        if(WORD_TO_CHECK[i] == '\\')
            backslashesCounter++;
    }

    return backslashesCounter;
}
