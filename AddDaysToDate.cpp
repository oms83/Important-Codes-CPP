#include<iostream>
using namespace std;
/*




    أبجوبته غير دقيقة متل 
    AddDayToDate.cpp





*/
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) 
{ 
    
    short TotalDays = 0; 
    for (int i = 1; i <= Month - 1; i++)     
    { 
        TotalDays += NumberOfDaysInAMonth(Year, i);     
    }     
    
    TotalDays += Day; 

    return TotalDays; 
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

    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

    short MonthDays = 0; 
    Date.Month = 1;
    while(true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);
        if(MonthDays < RemainingDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if(Date.Month>12)
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