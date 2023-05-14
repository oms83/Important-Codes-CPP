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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}

string DayShortName(short DayOfWeekOrder) 
{ 
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
    return arrDayNames[DayOfWeekOrder]; 

}

int main()
{
    system("cls");
    short Day = GetPositiveNumber("Enter a day: ");
    short Month = GetPositiveNumber("Enter a month: ");
    short Year = GetPositiveNumber("Enter a year: ");
    short DayOfOrder = DayOfWeekOrder(Year, Month, Day);
    
    cout << "Date: " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order: " << DayOfOrder << endl;
    cout << "Day Order: " << DayShortName(DayOfOrder) << endl;
    system("pause>0");
}