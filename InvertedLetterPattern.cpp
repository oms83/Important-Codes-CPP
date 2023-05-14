#include<iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number=0; 
    do
    {
        cout << Message;
        cin >> Number;
    }while(Number<0);
    return Number;
}
void PrintInvertedPattern(int Number)
{
    for(int i=Number; i>0; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout << char(64+i) << char(32);
        }
        cout << endl;
    }
}

int main()
{
    PrintInvertedPattern(ReadPositiveNumber("Enter a positive number:: "));
}
