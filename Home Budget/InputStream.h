#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

#include <iostream>
#include <conio.h>

using namespace std;

class InputStream{
public:
    static string loadLine();
    static char loadOneCharacter();
};

#endif // INPUTSTREAM_H
