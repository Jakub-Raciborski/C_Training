#include <iostream>
#include <math.h>

using namespace std;

void lusterko();
unsigned long long int longExponentiation(unsigned long long int base, unsigned long long int exponent);
int checkBinaryLength(unsigned long long int number);
void decimalToBinary(unsigned long long int number, int *matrix, int length);
void reverseIntMatrix(int *matrixToReverse, int length);
unsigned long long int binaryToDecimal(int matrix[], int length, int firstElement=0);
void reverseDecimalByReverseBinaryRepresentation(unsigned long long int number);

int main()
{
    lusterko();
}

unsigned long long int longExponentiation(unsigned long long int base, unsigned long long int exponent)
{
    if(exponent==0)
        return 1;
    else if(base==0)
        return 0;
    else
    {
        return base * longExponentiation(base, --exponent);
    }
}


int checkBinaryLength(unsigned long long int number)
{
    if(number>0)
        return 1 + checkBinaryLength((number/2));
    else
        return 0;
}

void decimalToBinary(unsigned long long int number, int *matrix, int length)
{
    int element = length-1;
    do
    {
        matrix[element--]=number%2;
        number /= 2;
    }
    while(number>0);
}
void reverseIntMatrix(int *matrixToReverse, int length)
{
    int *bufforMatrix = new int[length];
    int reverseI = length-1;
    for(int i=0; i<length; i++)
    {
        bufforMatrix[i] = matrixToReverse[reverseI--];
    }
    for(int i=0; i<length; i++)
    {
        matrixToReverse[i]=bufforMatrix[i];
    }
    delete [] bufforMatrix;
}
unsigned long long int binaryToDecimal(int matrix[], int length, int firstElement)
{
    int exponent = length -1;
    if(exponent>=0)
        return longExponentiation(2,exponent)*matrix[firstElement++] + binaryToDecimal(matrix, exponent,firstElement);
    else
        return 0;
}
void reverseDecimalByReverseBinaryRepresentation(unsigned long long int number)
{
    if (number == 0)
        cout<<'0'<<endl;
    else
    {
        int binaryLength = checkBinaryLength(number);
        int *binaryRepresentation = new int[binaryLength];
        decimalToBinary(number, binaryRepresentation, binaryLength);
        reverseIntMatrix(binaryRepresentation, binaryLength);
        cout<<binaryToDecimal(binaryRepresentation,binaryLength)<<endl;
        delete [] binaryRepresentation;
    }
}
void lusterko()
{
    unsigned long long int number = 0;
    while(cin>>number)
    {
        reverseDecimalByReverseBinaryRepresentation(number);
    }
}
