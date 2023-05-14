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

stDate AddDaysToDate(stDate &Date, int Days)
{
    int RemainingDays = NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day) + Days;
    int MonthDays = 0;
    Date.Month =  1;
    while(true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

        if(MonthDays<RemainingDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
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

stDate AddXDaysToDate(stDate &Date, short Days)
{
    return AddDaysToDate(Date, Days);
}

stDate AddOneWeekToDate(stDate &Date)
{
    return AddDaysToDate(Date, 7);
}

stDate AddXWeeksToDate(stDate &Date, short Weeks)
{
    return AddDaysToDate(Date, 7*Weeks);
}

stDate AddOneMonthToDate(stDate &Date)
{
    if(Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
    if(Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate AddXMonthToDate(stDate &Date, short Months)
{
    short MonthDays;
    for(short i=1; i<=Months; i++)
    {
        AddOneMonthToDate(Date);
    }
    return Date;
}

stDate AddOneYearToDate(stDate &Date)
{
    Date.Year++;
    return Date;
}

stDate AddXYearsToDate(stDate &Date, short Years)
{
    short YearDays;
    for(short i=1; i<=Years; i++)
    {
        AddOneYearToDate(Date);
    }
    return Date;
}

stDate AddXYearsFasterToDate(stDate &Date, short Years)
{
    Date.Year += Years;  
    return Date;
}

stDate AddOneDecadeToDate(stDate &Date)
{
    Date.Year += 10;  
    return Date; 
}

stDate AddXDecadesToDate(stDate &Date, short Decades)
{
    for(short i=1; i<=Decades; i++)
    {
        AddOneDecadeToDate(Date);
    }
    return Date;
}

stDate AddXDecadesFasterToDate(stDate &Date, short Decades)
{
    Date.Year += 10*Decades;  
    return Date;
}

stDate AddCenturyToDate(stDate &Date)
{
    Date.Year += 100;
    return Date;
}

stDate AddMillenniumToDate(stDate& Date)
{
    Date.Year += 1000;
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
    
    Date = AddOneDayToDate(Date);
    cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXDaysToDate(Date, 10);
    cout << "02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneWeekToDate(Date);
    cout << "03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = AddXWeeksToDate(Date, 10);
    cout << "04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneMonthToDate(Date);
    cout << "05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXMonthToDate(Date, 5);
    cout << "06-Adding 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneYearToDate(Date);
    cout << "07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXYearsToDate(Date, 10);
    cout << "08-Adding 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = AddXYearsFasterToDate(Date, 10);
    cout << "09-Adding 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneDecadeToDate(Date);
    cout << "10-Adding decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXDecadesToDate(Date, 10);
    cout << "11-Adding 10 decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    AddXDecadesFasterToDate(Date, 10);
    cout << "12-Adding 10 decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    AddCenturyToDate(Date);
    cout << "13-Adding century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    AddMillenniumToDate(Date);
    cout << "14-Adding millennuim is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    system("pause>0");
}



