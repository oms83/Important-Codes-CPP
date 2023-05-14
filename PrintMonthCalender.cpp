#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const string Months[12] = { "Jan", "Feb", "Mar", "Epr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const string Days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "sat" };

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
short ClaculateDate(short Year, short Month, short Day=1)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
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
void PrintDays(short Year, short Month, short Day=1)
{
    short NumOfDaysInMonth = NumberOfDaysInAMonth(Year, Month);
    short WhatDayDoesTheMonthStart = ClaculateDate(Year, Month, Day);
    short Counter = 0;
    for(short j=1; j<=WhatDayDoesTheMonthStart; j++)
    {
        cout << "      ";
    }

    for(short i=1; i<=NumOfDaysInMonth; i++)
    {
        
        if(7 == WhatDayDoesTheMonthStart+Counter)
        {
            cout << "\n";
            Counter=0;
            WhatDayDoesTheMonthStart=0;
        } 
        Counter++;
        cout << setw(6) << left << i;

    }
}
void PrintCalender(short Year, short Month, short Day=1)
{
    cout << "\n____________________ " <<  Months[Month-1] << " ____________________\n\n";
    cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat"  << endl;
    PrintDays(Year, Month, Day);
    cout << "\n_____________________________________________\n";

}
int main()
{
    system("cls");
    
    short Year = GetPositiveNumber("Please Enter a Year: "); 
    short Month = GetPositiveNumber("Please Enter a Month: "); 
    
    PrintCalender(Year, Month);

    system("pause>0");
}