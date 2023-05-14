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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}
short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
    short Total=0;

    for(short i=1; i<=Month-1; i++)
    {
        Total += NumberOfDaysInAMonth(Year, i);
    }

    return Total + Day;
}
struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate AddDaysToDate(stDate &Date, short Days)
{
    short MonthDays = 0;
    short RemainingDays = NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day) + Days;
    Date.Month = 1;

    while(true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

        if(RemainingDays > MonthDays)
        {
            Date.Month++;
            RemainingDays -= MonthDays; 
            
            if(Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

stDate GetDate(stDate& Date)
{
    system("cls");
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");

    return Date;
}

int main()
{
    
    stDate Date;

    GetDate(Date);
    short Days = GetPositiveNumber("\nHow many day you want to add to date: ");

    cout << "Date: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    AddDaysToDate(Date, Days);
    cout << "Date: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    
    system("pause>0");
}