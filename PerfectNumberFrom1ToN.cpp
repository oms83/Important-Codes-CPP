#include<iostream>
#include<string>
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
bool isPerfectNumber(int Number)
{
    int sum=0;
    for(int i=1; i<Number; i++)
    {
        if(Number%i==0)
            sum+=i;
    }
    return sum == Number;
}
void PrintPerfectNumber(int Number)
{
    for(int i=0; i<Number; i++)
    {
        if(isPerfectNumber(i))
            cout << i << " is a perfect Number " << endl;
        else 
            continue;
    }
}

int main()
{
    PrintPerfectNumber(ReadPositiveNumber("Enter a positive number:: "));
}


