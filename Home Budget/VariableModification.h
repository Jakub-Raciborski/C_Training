#ifndef VARIABLEMODIFICATION_H
#define VARIABLEMODIFICATION_H

#include <iostream>
#include "StringMethods.h"

using namespace std;

class VariableModification{
public:
    static int convertStringToInt(string wordToConvert);
    static string convertIntToString(int numberToConvert);
    static float convertStringToFloat(string wordToConvert);
    static string convertFloatToString(float numberToConvert);
};

#endif // VARIABLEMODIFICATION_H
