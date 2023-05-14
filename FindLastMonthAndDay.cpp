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

short NumberOfDaysInAMonth(short Year, short Month)
{
    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1] ;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLastDayInTheMonth(stDate Date1)
{
    return Date1.Day == NumberOfDaysInAMonth(Date1.Year, Date1.Month);
}
bool IsLastDayInTheYear(stDate Date1)
{
    return Date1.Month==12;
}
stDate GetDate(stDate& Date)
{
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");

    return Date;
}
int main()
{
    system("cls");
    
    stDate Date1;
    GetDate(Date1);

    if(IsLastDayInTheMonth(Date1))
        cout << "Yes: It Is The Last Day In The Month\n";
    else 
        cout << "No: It Is Not The Last Day Int The Month\n";



    if(IsLastDayInTheYear(Date1))
        cout << "Yes: It Is The Last Month In The Year\n";
    else 
        cout << "No: It Is Not The Last Month Int The Year\n";
        
    system("pause>0");
}