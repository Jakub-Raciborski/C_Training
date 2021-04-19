#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void changeSentenceToSeparateWords(const string SENTENCE, vector<string> &bankOfWords);
bool getLineAndLoadToVector(vector<string> &bankOfWords);
void deleteRepetitiveWords(vector<string> &bankOfWords, vector<string> &bankOfRepetitiveWords);
void wroteAllWords(const vector<string> &BANK_OF_WORDS);

int main() {
    vector<string> correctSongText;
    vector<string> rememberedWordsfromSongText;
    while(getLineAndLoadToVector(correctSongText)) {
        getLineAndLoadToVector(rememberedWordsfromSongText);
        deleteRepetitiveWords(correctSongText, rememberedWordsfromSongText);
        cout<<correctSongText.size()<<endl;
        sort(correctSongText.begin(), correctSongText.end());
        wroteAllWords(correctSongText);
        correctSongText.clear();
        rememberedWordsfromSongText.clear();
    }
}

void changeSentenceToSeparateWords(const string SENTENCE, vector<string> &bankOfWords) {
    const int SENTENCE_LENGTH = SENTENCE.length();
    string word = "";
    for(int i=0; i<SENTENCE_LENGTH; i++) {
        if(SENTENCE[i]!= ' ')
            word += SENTENCE[i];
        else {
            bankOfWords.push_back(word);
            word = "";
        }
    }
    bankOfWords.push_back(word);
}
bool getLineAndLoadToVector(vector<string> &bankOfWords) {
    string textLine;
    getline(cin, textLine);
    if(textLine.size() != 0) {
        changeSentenceToSeparateWords(textLine, bankOfWords);
        return true;
    } else
        return false;
}
void deleteRepetitiveWords(vector<string> &bankOfWords, vector<string> &bankOfRepetitiveWords) {
    vector<string>::iterator word = bankOfWords.begin();
    vector<string>::iterator lastWord = bankOfWords.end();
    vector<string>::iterator repetitiveWord = bankOfRepetitiveWords.begin();
    vector<string>::iterator lastRepetitiveWord = bankOfRepetitiveWords.end();

    for(repetitiveWord; repetitiveWord != lastRepetitiveWord; repetitiveWord++) {
        for(word; word != lastWord; word++) {
            if(*word == *repetitiveWord) {
                bankOfWords.erase(word);
                break;
            }
        }
    }
}
void wroteAllWords(const vector<string> &BANK_OF_WORDS) {
    const int AMOUNT_OF_WORDS = BANK_OF_WORDS.size();
    for(int i=0; i<AMOUNT_OF_WORDS; i++)
        cout<<BANK_OF_WORDS[i]<<endl;
}
