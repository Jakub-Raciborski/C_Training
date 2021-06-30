#include "VariableModification.h"
#include <sstream>

int VariableModification::convertStringToInt(string wordToConvert){
    int number = atoi(wordToConvert.c_str());
    return number;
}
string VariableModification::convertIntToString(int numberToConvert){
    ostringstream ss;
    ss << numberToConvert;
    return ss.str();
}
