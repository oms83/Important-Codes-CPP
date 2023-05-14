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

short GetNumberOfDaysInMonth(short Year, short Month)
{
    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1] ;
}

short GetNumberOfHoursInMonth(short Year, short Month)
{
    return GetNumberOfDaysInMonth(Year, Month) * 24;
}

int GetNumberOfMinutesInMonth(short Year, short Month)
{
    return GetNumberOfHoursInMonth(Year, Month) * 60;

}

int GetNumberOfSecondsInMonth(short Year, short Month)
{
    return GetNumberOfMinutesInMonth(Year, Month) * 60;
}

void PrintResults(short Year, short Month)
{
    cout << "Number of days    in year [" << Year << "] is : " << GetNumberOfDaysInMonth(Year, Month) << endl;
    cout << "Number of hours   in year [" << Year << "] is : " << GetNumberOfHoursInMonth(Year, Month) << endl;
    cout << "Number of minutes in year [" << Year << "] is : " << GetNumberOfMinutesInMonth(Year, Month) << endl;
    cout << "Number of seconds in year [" << Year << "] is : " << GetNumberOfSecondsInMonth(Year, Month) << endl;
}

int main()
{
    system("cls");
    short Year = GetPositiveNumber("Enter any year: ");
    short Month = GetPositiveNumber("Enter any month: ");
    PrintResults(Year, Month);
    system("pause>0");
}