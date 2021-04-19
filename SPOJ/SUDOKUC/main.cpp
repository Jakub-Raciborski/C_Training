#include <iostream>
#include <fstream>

using namespace std;

void SUDOKUC();
int iterations=0;
bool checkSudokuHorrizontally(int arr[9][9], int length);
bool checkSudokuVertically(int arr[9][9], int length);
bool checkSudokuSquare3x3(int arr[9][9], int firstElement, int secondElement);
bool checkSudokuElementsRepeatsHorizontally(int arr[9][9], int length);
bool checkSudokuElementsRepeatsVertically(int arr[9][9], int length);
bool isSudokuOk(int arr[9][9]);
int main()
{
    ifstream in("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    SUDOKUC();
}
bool checkSudokuHorrizontally(int arr[9][9], int length)
{
    int sum=0;
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(arr[i][j]>0)
                sum += arr[i][j];
            else
                return false;
        }
        if(sum!=45)
            return false;
        sum=0;
    }
    return true;
}
bool checkSudokuVertically(int arr[9][9], int length)
{
    int sum=0;
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(arr[j][i]>0)
                sum += arr[j][i];
            else
                return false;
        }
        if(sum!=45)
            return false;
        sum=0;
    }
    return true;
}
bool checkSudokuSquare3x3(int arr[9][9], int firstElement, int secondElement)
{
    int sum=0;
    for(int i=firstElement; i<=firstElement+2; i++)
    {
        for(int j=secondElement; j<=secondElement+2; j++)
        {
            if(arr[j][i]>0)
            {
                sum += arr[j][i];
            }
            else
                return false;
        }
    }
    if(sum==45)
        return true;
    else
        return false;
}

bool checkSudokuElementsRepeatsVertically(int arr[9][9], int length)
{
    int digit =0;
    for(int i=0; i<length; i++)
    {
        int nextDigit=1;
        for(int j=0; j<length; j++)
        {
            digit=arr[j][i];
            for(int k=nextDigit; k<length; k++)
            {
                if(digit==arr[k][i])
                    return false;
            }
            nextDigit++;
        }
    }
    return true;
}
bool checkSudokuElementsRepeatsHorizontally(int arr[9][9], int length)
{
    int digit =0;
    for(int i=0; i<length; i++)
    {
        int nextDigit=1;
        for(int j=0; j<length; j++)
        {
            digit=arr[i][j];
            for(int k=nextDigit; k<length; k++)
            {
                if(digit==arr[i][k])
                    return false;
            }
            nextDigit++;
        }
    }
    return true;
}
bool isSudokuOk(int arr[9][9])
{
    if(!checkSudokuElementsRepeatsVertically(arr, 9))
        return false;
    if(!checkSudokuElementsRepeatsHorizontally(arr, 9))
        return false;
    if(!checkSudokuHorrizontally(arr,9))
        return false;
    if(!checkSudokuVertically(arr,9))
        return false;
    if(!checkSudokuSquare3x3(arr,0,0))
        return false;
    if(!checkSudokuSquare3x3(arr,0,3))
        return false;
    if(!checkSudokuSquare3x3(arr,0,6))
        return false;
    if(!checkSudokuSquare3x3(arr,3,0))
        return false;
    if(!checkSudokuSquare3x3(arr,3,3))
        return false;
    if(!checkSudokuSquare3x3(arr,3,6))
        return false;
    if(!checkSudokuSquare3x3(arr,6,0))
        return false;
    if(!checkSudokuSquare3x3(arr,6,3))
        return false;
    if(!checkSudokuSquare3x3(arr,6,6))
        return false;
    return true;
}
void SUDOKUC()
{
    cin>>iterations;

    for(int k=0; k<iterations; k++)
    {
        int sudokuArray[9][9];
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cin>>sudokuArray[i][j];
        if(isSudokuOk(sudokuArray))
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
}
