#include "VariableModification.h"
#include <sstream>

int VariableModification::convertStringToInt(string wordToConvert) {
    if(StringMethods::isNumber(wordToConvert)) {
        int number = atoi(wordToConvert.c_str());
        return number;
    } else
        return 0;
}
string VariableModification::convertIntToString(int numberToConvert) {
    ostringstream ss;
    ss << numberToConvert;
    return ss.str();
}
float VariableModification::convertStringToFloat(string wordToConvert) {
    if(StringMethods::isFloatNumber(wordToConvert)) {
        float number = stof(wordToConvert);
        return number;
    } else
        return 0;
}
string VariableModification::convertFloatToString(float numberToConvert){
    ostringstream ss;
    ss << numberToConvert;
    return ss.str();
}
