#include<iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number=0; 
    do
    {
        cout << Message;
        cin >> Number;
    }while(Number<=0);
    return Number;
}
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Remainder=0, FreCount=0;
    while(Number>0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if(Remainder == DigitToCheck)
            FreCount++; 
    }
    return FreCount;
}

int main()
{
    // FoundFrequencyOfDigits(ReadPositiveNumber("Enter a positive number :: "));
}


