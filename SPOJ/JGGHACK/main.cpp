#include <iostream>

using namespace std;

void JGGHACK();
void decodeGGPassword(string password);
int returnValue(char letter, char letterArray[]);
int returnValueX16(char letter, char letterArray[]);
int main()
{
    JGGHACK();
}
int returnValue(char letter, char letterArray[])
{
    for(int i=0; i<16; i++)
    {
        if(letter==letterArray[i])
            return i;
    }
    return 0;
}
int returnValueX16(char letter, char letterArray[])
{
    for(int i=0; i<16; i++)
    {
        if(letter==letterArray[i])
            return i*16;
    }
    return 0;
}
void decodeGGPassword(string password)
{
    char letterArray[16]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
    int length = password.size();
    int j=0;
    string decryptedPassword = "";
    for(int i=0; i<length; i+=2)
    {
        char a = returnValue(password[i], letterArray)+ returnValueX16(password[i+1], letterArray);
        decryptedPassword += a;
        j++;
    }
    cout<<decryptedPassword<<endl;
}
void JGGHACK()
{
    string password ="";
    while(cin>>password)
    {
        decodeGGPassword(password);
    }
}
