#include<iostream>
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
    return (Year%400==0) || ( (Year%4 == 0) && (Year%100 != 0) ) ? true : false; 
}

short NumberOfDaysInAMonth(short Year, short Month)
{   
    if(Month<0 || Month>12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1];
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate AddDaysToDate(short Year, short Month, short Day, short Days)
{
    stDate Date;
    Date.Year = Year;
    Date.Month = Month;
    Date.Day = Day;

    Date.Year += Days/365;
    Date.Month += (Days%365)/30;
    Date.Day  += (Days%365)%30;

    short MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

    if( Date.Day > MonthDays)
    {
        Date.Day = Date.Day % MonthDays;
        Date.Month += 1;

        if(Date.Month>12)
        {
            Date.Month = 1;
            Date.Year += 1;
            Date.Day = Date.Day % MonthDays;
        }
    }

    if(Date.Month>12)
    {
        Date.Year += 1;
        Date.Month = 1;
    }
    
    return Date;
}



int main()
{
    system("cls");
    
    short Year = GetPositiveNumber("Please Enter a Year: "); 
    short Month = GetPositiveNumber("Please Enter a Month: "); 
    short Day = GetPositiveNumber("Please Enter a Day: ");
    short Days = GetPositiveNumber("How many days to add: ");



    stDate Date = AddDaysToDate(Year, Month, Day, Days);
    cout << "Date after add [" << Days << "] days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    system("pause>0");
}