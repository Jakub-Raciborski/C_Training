#include "InputStream.h"

string InputStream::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}
