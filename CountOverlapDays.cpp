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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month==Date2.Month ? Date1.Day<Date2.Day : false)) : false);
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    short y, a, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + 12*a - 2;
    return ( Date.Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
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

bool IsLastDayInTheMonth(stDate Date1)
{
    return Date1.Day == NumberOfDaysInAMonth(Date1.Year, Date1.Month);
}

bool IsLastMonthInTheYear(stDate Date1)
{
    return Date1.Month==12;
}

bool IsItWeekend(stDate Date)
{
    short DayInWeek = DayOfWeekOrder(Date);
    return (DayInWeek==6) || (DayInWeek==5);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false ) : false;
}

bool Date1AfterDate2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
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

string GetDayByText(stDate Date)
{
    return DayShortName(DayOfWeekOrder(Date));
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

short CalculatePeriodLength(stDate Date1, stDate Date2, bool LastDayIncluding = false) 
{ 
    int Days = 0; 
    
    while (IsDate1BeforeDate2(Date1, Date2))     
    {         

        Days++; 
        Date1 = AddOneDayToDate(Date1);     
    } 

    return LastDayIncluding ? ++Days : Days; 
    
}

short PeriodLength(stDate Date1, stDate Date2, bool LastDayIncluding = false) 
{
    return GetDifferenceInDays(Date1, Date2, LastDayIncluding); 
}

stDate GetDate(stDate& Date)
{
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");
    cout << endl << endl;

    return Date;
}

struct stPeriod
{
    stDate Start;
    stDate End;
};

bool IsDateWithinPeriod(stPeriod Period, stDate Date) 
{ 
    return !( Date1AfterDate2(Date, Period.End) || IsDate1BeforeDate2(Date, Period.Start) ); 
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    if(IsDateWithinPeriod(Period1, Period2.End))
        return GetDifferenceInDays(Period1.Start, Period2.End);

    if(IsDateWithinPeriod(Period1, Period2.Start))
        return GetDifferenceInDays(Period2.Start, Period1.End);
        
    if(IsDateWithinPeriod(Period2, Period1.Start))
        return GetDifferenceInDays(Period1.Start , Period2.End);

    if(IsDateWithinPeriod(Period2, Period1.End))
        return GetDifferenceInDays(Period2.Start, Period1.End);

    if(IsDateWithinPeriod(Period2, Period1.End) && IsDateWithinPeriod(Period2, Period1.Start))
        return GetDifferenceInDays(Period1.Start, Period1.End);

    if(IsDateWithinPeriod(Period1, Period2.End) && IsDateWithinPeriod(Period1, Period2.Start))
        return GetDifferenceInDays(Period2.Start, Period2.End);

    return 0;
}

stDate GetDate()
{
    stDate Date;
    cout << endl; 
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");

    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date: \n";
    Period.Start = GetDate();

    cout << "\nEnter End Date: \n";
    Period.End = GetDate();

    return Period;
}

int main()
{
    system("cls");

    cout << "\nEnter Period 1: ";
    stPeriod Period1 = ReadPeriod();
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Count Days: " << CountOverlapDays(Period1, Period2) << endl;


    system("pause>0");
}