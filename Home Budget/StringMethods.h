#ifndef STRINGMETHODS_H
#define STRINGMETHODS_H

#include <iostream>

using namespace std;

class StringMethods{
public:
    static int countDoubleBackslahesInString(const string WORD_TO_CHECK);
    static bool isNumber(string wordToCheck);
    static bool isFloatNumber(string wordToCheck);
    static string changeCommaToDot(string wordToChange);
};

#endif // STRINGMETHODS_H
