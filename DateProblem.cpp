#include<iostream>
#include<string>
#include<ctime>
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

short NumberOfDaysInLeapYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

struct stDate
{
    short Year;
    short Month;
    short Day;
};

short NumberOfDaysInAMonth(short Year, short Month)
{
    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1] ;
}

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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month==Date2.Month ? Date1.Day<Date2.Day : false)) : false);
}

bool IsLastMonthInTheYear(stDate Date1)
{
    return Date1.Month==12;
}

short DayOfWeekOrder(stDate Date)
{
    short y, a, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + 12*a - 2;
    return ( Date.Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}

stDate AddOneDayToDate(stDate &Date)
{
    if(IsLastDayInTheMonth(Date))
    {
        
        if(IsLastMonthInTheYear(Date))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) 
{ 
    int Days = 0; 
    
    while (IsDate1BeforeDate2(Date1, Date2))     
    {         
        Days++; 
        Date1 = AddOneDayToDate(Date1);     
    } 

    return IncludeEndDay ? ++Days : Days; 
    
} 

string DayShortName(short DayOfWeekOrder) 
{ 
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
    return arrDayNames[DayOfWeekOrder]; 

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

short NumberOfDaysFromTheBeginingOfTheYear(stDate Date)
{
    short Total=0;

    for(short i=1; i<=Date.Month-1; i++)
    {
        Total += NumberOfDaysInAMonth(Date.Year, i);
    }

    return Total + Date.Day;
}

void PrintDate(stDate Date)
{
    short DayInWeek = DayOfWeekOrder(Date);
    string DayName = DayShortName(DayInWeek);
    cout << "Today is " << DayName << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
}

bool IsItEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date)==6;
}

bool IsItWeekend(stDate Date)
{
    short DayInWeek = DayOfWeekOrder(Date);
    return (DayInWeek==6) || (DayInWeek==5);
}

bool IsItBusinessDay(stDate Date)
{
    return !IsItWeekend(Date);
}

short DaysUntilEndOfYear(stDate Date)
{
    return NumberOfDaysInLeapYear(Date.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date)+1;
}

short DaysUntilEndOfMonth(stDate Date)
{
    short DaysNumberOfMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    return DaysNumberOfMonth - Date.Day+1;
}

short DaysUntilEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfYear(stDate Date, bool IncludeEndDay = true)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfYearDate, IncludeEndDay);
}

short DaysUntilEndOfMonth(stDate Date, bool IncludeEndDay = true)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfMonthDate, IncludeEndDay);
}

void PrintResult(stDate Date)
{
    system("cls");

    PrintDate(Date);

    cout << "Is it end of week ? \n";
    if(IsItEndOfWeek(Date))
        cout << "Yes is end of week.\n";
    else 
        cout << "No not end of week.\n";
    

    cout << "\nIs it Weekend ? \n";
    if(IsItWeekend(Date))
        cout << "Yes it is weekend.\n";
    else 
        cout << "No is not weekend.\n";


    cout << "\nIs it business day.\n";
    if(IsItBusinessDay(Date)) 
        cout << "Yes it is business day.\n";
    else
        cout << "No is not business day.\n";


    cout << "\nDays until end of week  : " << DaysUntilEndOfWeek(Date);
    cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date, true);
    cout << "\nDays until end of year  : " << DaysUntilEndOfYear(Date, true);

}

int main()
{
    system("cls");

    stDate Date;
    Date = GetDate(Date);
    PrintResult(Date);
}
