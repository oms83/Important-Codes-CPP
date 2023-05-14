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
int RevesedDigit(int Number)
{
    int Remainder=0, Number2=0;
    while(Number>0)
    {
        Remainder = Number % 10;
        Number2 = Number2*10 + Remainder;
        Number /= 10;
    }
    return Number2;
}

void PrintDigits(int Number)
{
    int Remainder=0, Number2=0;
    while(Number>0)
    {
        Remainder = Number%10;
        Number /= 10;
        cout << Remainder << endl;
    }
}

int main()
{
    PrintDigits(RevesedDigit(ReadPositiveNumber("Enter a positive number:: ")));
}
