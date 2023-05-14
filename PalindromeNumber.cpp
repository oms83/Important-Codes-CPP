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
int ReversedDigits(int Number)
{
    int Remainder=0, Number2=0;
    while(Number>0)
    {
        Remainder = Number %10;
        Number2 = Number2*10 + Remainder;
        Number/=10;
    }
    return Number2;
}
bool IsItPalindromeNumber(int Number)
{
    return Number == ReversedDigits(Number);
}
void PrintPalindromeNumber(int Number)
{
    if(IsItPalindromeNumber(Number))
        cout << Number << " is a palindrome number" << endl;
    else 
        cout << Number << " is not a palindrome number" << endl;
}

int main()
{
    PrintPalindromeNumber(ReadPositiveNumber("Enter a positive Number:: "));
}

