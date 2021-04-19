#include <iostream>
#include <map>

using namespace std;
void initializationHexadecimalToBinaryMap(map<char,string> &HexadecimalToBinary);
void convertHexadecimalToBinary(char hexadecimalToConvert);
void hextobin();
int main() {
    hextobin();
}
void initializationHexadecimalToBinaryMap(map<char,string> &HexadecimalToBinary) {
    HexadecimalToBinary['0']="0000";
    HexadecimalToBinary['1']="0001";
    HexadecimalToBinary['2']="0010";
    HexadecimalToBinary['3']="0011";
    HexadecimalToBinary['4']="0100";
    HexadecimalToBinary['5']="0101";
    HexadecimalToBinary['6']="0110";
    HexadecimalToBinary['7']="0111";
    HexadecimalToBinary['8']="1000";
    HexadecimalToBinary['9']="1001";
    HexadecimalToBinary['A']="1010";
    HexadecimalToBinary['B']="1011";
    HexadecimalToBinary['C']="1100";
    HexadecimalToBinary['D']="1101";
    HexadecimalToBinary['E']="1110";
    HexadecimalToBinary['F']="1111";
}
void convertHexadecimalToBinary(char hexadecimalToConvert) {
    map<char,string> hexadecimalToBinary;
    initializationHexadecimalToBinaryMap(hexadecimalToBinary);
    cout<<hexadecimalToBinary[hexadecimalToConvert]<<endl;
}
void hextobin() {
    string hexadecimalCharacter;
    while(getline(cin,hexadecimalCharacter)) {
        if(hexadecimalCharacter=="")
            break;
        convertHexadecimalToBinary(hexadecimalCharacter[0]);
    }
}
