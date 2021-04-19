#include <iostream>

using namespace std;
string reverseString(string word);
string stringToReverse;
void PALIND2();
int ileIteracji=0;
int main()
{
    PALIND2();
}
string reverseString(string word)
{
    string reverseWord="";
    int length = word.size();
    for(int i=(length-1);i>=0;i--)
    {
        reverseWord+=word[i];
    }

    return reverseWord;
}
void PALIND2()
{
    cin>>ileIteracji;
    for(int i=0;i<ileIteracji;i++)
    {
        cin>>stringToReverse;
        if(stringToReverse==reverseString(stringToReverse))
            cout<<"tak"<<endl;
        else
            cout<<"nie"<<endl;
    }
}
