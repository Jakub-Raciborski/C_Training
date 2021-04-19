#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void loadDataFromInput(vector<string> &dataContainer);
void displayAllWords(const vector<string> WORDS);

int main() {
    vector<string> words;
    loadDataFromInput(words);
    sort(words.begin(),words.end());
    displayAllWords(words);
}
void loadDataFromInput(vector<string> &dataContainer) {
    string word;
    while(getline(cin,word)) {
        if(word.size()==0)
            break;
        dataContainer.push_back(word);
    }
}
void displayAllWords(const vector<string> WORDS)
{
    const int AMOUNT_OF_WORDS = WORDS.size();
    for(int i=0; i<AMOUNT_OF_WORDS; i++)
    {
        cout<<WORDS[i]<<endl;
    }
}
