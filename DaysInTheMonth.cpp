#include<iostream>
using namespace std;

enum enMonths {Jan=31, Feb=28, Mar=31, Epr=30, May=31, Jun=30, Jul=31, Aug=31, Sep=30, Oct=31, Nov=30, Dec=31, LeapFeb=29 };
short ReadAPositiveNumber(string Message)
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
enMonths NumberOfDaysInAMonth(short Year, short Month)
{

    switch(Month)
    {
        case 1:
            return enMonths::Jan;
        case 2:
            return IsLeapYear(Year) ? enMonths::LeapFeb : enMonths::Feb;
        case 3:
            return enMonths::Mar;
        case 4:
            return enMonths::Epr;
        case 5:
            return enMonths::May;
        case 6:
            return enMonths::Jun;
        case 7:
            return enMonths::Jul;
        case 8:
            return enMonths::Aug;
        case 9:
            return enMonths::Sep;
        case 10:
            return enMonths::Nov;
        case 11:
            return enMonths::Oct;
        case 12:
            return enMonths::Dec;
    }
 
    return enMonths::Feb; 
}
int NumberOfHoursInMonth(short Year, short Month)
{
    return int(NumberOfDaysInAMonth(Year, Month)) * 24;
}
int NumberOfMinutesInMonth(short Year, short Month)
{
    return int(NumberOfHoursInMonth(Year, Month))*60;
}
int NumberOfSecondsInMonth(short Year, short Month)
{
    return int(NumberOfMinutesInMonth(Year, Month))*60;
}
void CalculateDate(short Year, short Month)
{
    cout << "Number Of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month) << endl;
    cout << "Number Of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month) << endl;
    cout << "Number Of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month) << endl;
    cout << "Number Of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month) << endl;
}
void PrintDate()
{
    short Year = ReadAPositiveNumber("Enter Year: ");
    short Month = ReadAPositiveNumber("Enter Month: ");
    CalculateDate(Year, Month);

}
int main()
{
    PrintDate();
}