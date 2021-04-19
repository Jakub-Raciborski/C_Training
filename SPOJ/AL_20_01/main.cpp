#include <iostream>
#include <map>

using namespace std;
void initializationMorseCodeMap(map<char,string> &MorseCode);
void translateSentenceToMorseCode(string sentenceToTranslate);
string changeCharactersToUppercase(string sentenceToUppercase);
void translateInputToMorseCode();

int main()
{
    translateInputToMorseCode();
}
void initializationMorseCodeMap(map<char,string> &MorseCode){
MorseCode['A']=".-/";
MorseCode['B']="-.../";
MorseCode['C']="-.-./";
MorseCode['D']="-../";
MorseCode['E']="./";
MorseCode['F']=".-../";
MorseCode['G']="--./";
MorseCode['H']="..../";
MorseCode['I']="../";
MorseCode['J']=".---/";
MorseCode['K']="-.-/";
MorseCode['L']="..-./";
MorseCode['M']="--/";
MorseCode['N']="-./";
MorseCode['O']="---/";
MorseCode['P']=".--./";
MorseCode['Q']="--.-/";
MorseCode['R']=".-./";
MorseCode['S']=".../";
MorseCode['T']="-/";
MorseCode['U']="..-/";
MorseCode['V']="...-/";
MorseCode['W']=".--/";
MorseCode['X']="-..-/";
MorseCode['Y']="-.--/";
MorseCode['Z']="--../";
MorseCode[' ']="/";
}
string changeCharactersToUppercase(string sentenceToUppercase){
    const int AMOUNT_OF_LETTERS = sentenceToUppercase.size();
    for(int i=0; i<AMOUNT_OF_LETTERS;i++)
        sentenceToUppercase[i]=toupper(sentenceToUppercase[i]);
    return sentenceToUppercase;
}
void translateSentenceToMorseCode(string sentenceToTranslate)
{
    map<char,string> MorseCode;
    initializationMorseCodeMap(MorseCode);
    sentenceToTranslate = changeCharactersToUppercase(sentenceToTranslate);
    const int AMOUNT_OF_LETTERS = sentenceToTranslate.size();
    for(int i=0; i<AMOUNT_OF_LETTERS; i++)
    {
        cout<<MorseCode[sentenceToTranslate[i]];
    }
    cout<<endl;
}
void translateInputToMorseCode(){
    string sentenceToTranslate;
    while(getline(cin,sentenceToTranslate))
    {
        if(sentenceToTranslate=="")
            break;
        translateSentenceToMorseCode(sentenceToTranslate);
    }
}
