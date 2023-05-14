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

stDate DecreaseDateByOneDay(stDate &Date)
{

    if(Date.Day == 1)
    {
        
        if(Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate &Date, short Days)
{
    for (short i = 1; i <= Days; i++)     
    { 
        Date = DecreaseDateByOneDay(Date);
    } 
    return Date;
}

stDate DecreaseDateByOneWeek(stDate &Date)
{
    for(short i=1; i<=7; i++)
    {
        DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeek(stDate &Date, short Weeks)
{
    for(short i=1; i<=Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate &Date)
{
    if(Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXMonths(stDate &Date, short Months)
{
    short MonthDays;
    for(short i=1; i<=Months; i++)
    {
        DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate &Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate &Date, short Years)
{
    short YearDays;
    for(short i=1; i<=Years; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate &Date, short Years)
{
    Date.Year -= Years;  
    return Date;
}

stDate DecreaseDateByOneDecade(stDate &Date)
{
    Date.Year -= 10;  
    return Date; 
}

stDate DecreaseDateByXDecades(stDate &Date, short Decades)
{
    for(short i=1; i<=Decades; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate &Date, short Decades)
{
    Date.Year -= 10*Decades;  
    return Date;
}

stDate DecreaseDateByOneCentury(stDate &Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate& Date)
{
    Date.Year -= 1000;
    return Date;
}

stDate GetDate(stDate& Date)
{
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");
    cout << endl << endl;

    return Date;
}

int main()
{
    system("cls");
    
    stDate Date;
    GetDate(Date);

    cout << "Date After: \n\n";
    
    Date = DecreaseDateByOneDay(Date);
    cout << "01-Decrease one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "02-Decrease 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "03-Decrease one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXWeek(Date, 10);
    cout << "04-Decrease 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "05-Decrease one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "06-Decrease 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "07-Decrease one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "08-Decrease 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "09-Decrease 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "10-Decrease decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "11-Decrease 10 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12-Decrease 10 decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    DecreaseDateByOneCentury(Date);
    cout << "13-Decrease century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    DecreaseDateByOneMillennium(Date);
    cout << "14-Decrease millennuim is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    system("pause>0");
}



