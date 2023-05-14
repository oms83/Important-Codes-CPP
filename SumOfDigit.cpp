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
void PrintTheSumOfDigits(int Number)
{
    int sum=0, mod;
    while(Number>0)
    {
        sum += Number%10;
        Number /=10;
    }
    cout << "Ths summtion of digits number is :: " << sum;
}
int main()
{
    PrintTheSumOfDigits(ReadPositiveNumber("Enter a positive number :: "));
}

