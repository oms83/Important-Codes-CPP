#include<iostream>
#include<string>
using namespace std;

short GetPositiveNumber(string Message)
{
    short Number;
    do
    {
        cout << Message;
        cin >> Number;

    }while(Number<0);

    return Number;
}
bool IsLeapYear(short Year)
{ 
    return (Year%400==0) || (Year%100!=0 && Year%4==0);
}
int main()
{
    system("cls");
    short Year = GetPositiveNumber("Enter any year: ");
    IsLeapYear(Year)==true ? cout << "Yes: is leap year " : cout << "No: is not leap year"; 
    system("pause>0");
}