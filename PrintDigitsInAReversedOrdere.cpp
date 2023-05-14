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
int RevesedNumber(int Number)
{
    int mod, digit=0;
    for(;Number!=0;)
    {
        mod = Number%10;
        digit = digit*10 + mod;
        Number /=10;
    }
    return digit;
}
void PrintDigitInaRevesedOrder(int Number)
{
    cout << "The Number After Revesed is:: " << RevesedNumber(Number);
}

int main()
{
    PrintDigitInaRevesedOrder(ReadPositiveNumber("Enter a positive number:: "));
}

