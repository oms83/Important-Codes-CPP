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

int CalculateVacation(stDate Date1, stDate Date2) 
{ 
    int Days = 0; 
    
    while (IsDate1BeforeDate2(Date1, Date2))     
    {         

        if(!IsItWeekend(Date1))
            Days++; 
            
        Date1 = AddOneDayToDate(Date1);     
    } 

    return Days; 
    
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
    
    cout << "Valaction Starts: \n";
    stDate Date1;
    Date1 = GetDate(Date1);

    cout << "\nValaction Ends: \n";
    stDate Date2;
    Date2 = GetDate(Date2);
    
    cout << "Valaction From " << GetDayByText(Date1) << ", " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl; 
    cout << "Valaction To " << GetDayByText(Date2) << ", " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year << endl; 

    cout << "Actucal Valaction: " << CalculateVacation(Date1, Date2) << endl;
    
    
    system("pause>0");
}



