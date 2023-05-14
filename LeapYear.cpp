#include<iostream>
using namespace std;

short ReadAPositiveNumber()
{
    short Number;
    do
    {
        cout << "Enter Year: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}
bool IsLeapYear(short Year)
{
    return (Year%400==0) || ( (Year%4 == 0) && (Year%100 != 0) ) ? true : false; 
}
int main()
{
    short Year = ReadAPositiveNumber();
    if(IsLeapYear(Year))
        cout << Year << " is leap year \n";
    else
        cout << Year << " is not leap year \n";
}