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
void PrintAllDigitsFrequency(int Number)
{
    for(int i=0; i<10; i++)
    {
        short DigitFrequency = 0;
        DigitFrequency = CountDigitFrequency(i, Number);

        if(DigitFrequency>0)
            cout << "Digit:: " << i << "Digit Frequency:: " << DigitFrequency << endl;    
    }
}

int main()
{
    PrintAllDigitsFrequency(ReadPositiveNumber(("Enter a positive number :: ")));
}