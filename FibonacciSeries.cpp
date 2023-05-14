#include<iostream>
using namespace std;
int ReadAPositiveNumber()
{
    int Number=0;
    do
    {
        cout << "Enter a positive number: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}

void PrintFibonacci(int Number)
{
    int FebNumber=0;
    int Perv1=1, Perv2=0;
    cout << Perv1 << "   ";
    for(short i=2; i<=Number; i++)
    {
        FebNumber = Perv1+Perv2;
        cout << FebNumber << "   ";
        Perv2 = Perv1;
        Perv1 = FebNumber;
    }
}
int main()
{
    PrintFibonacci(ReadAPositiveNumber());
}
// previous سابق متقدم