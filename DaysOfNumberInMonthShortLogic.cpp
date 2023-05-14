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
short NumberOfDaysInAMonth(short Year, short Month)
{   
    if(Month<0 || Month>12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1];
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