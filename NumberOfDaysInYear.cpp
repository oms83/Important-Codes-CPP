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

short GetNumberOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short GetNumberOfHoursInYear(short Year)
{
    return GetNumberOfDaysInYear(Year) * 24;
}

int GetNumberOfMinutesInYear(short Year)
{
    return GetNumberOfHoursInYear(Year) * 60;

}

int GetNumberOfSecondsInYear(short Year)
{
    return GetNumberOfMinutesInYear(Year) * 60;
}

void PrintResults(short Year)
{
    cout << "Number of days    in year [" << Year << "] is : " << GetNumberOfDaysInYear(Year) << endl;
    cout << "Number of hours   in year [" << Year << "] is : " << GetNumberOfHoursInYear(Year) << endl;
    cout << "Number of minutes in year [" << Year << "] is : " << GetNumberOfMinutesInYear(Year) << endl;
    cout << "Number of seconds in year [" << Year << "] is : " << GetNumberOfSecondsInYear(Year) << endl;
}

int main()
{
    system("cls");
    short Year = GetPositiveNumber("Enter any year: ");
    PrintResults(Year);
    system("pause>0");
}