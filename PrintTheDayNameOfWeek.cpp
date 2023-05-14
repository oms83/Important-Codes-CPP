#include<iostream>
#include<string>
using namespace std;

const string Days[7] = { "Pzr", "Pzrt", "Sal", "Car", "Per", "Cum", "Cumrt" };

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
short ClaculateDate(short Year, short Month, short Day)
{
    short y, a, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12*a - 2;
    return ( Day + y + (y/4) - (y/100) + (y/400) + ( (m*31)/12 ) ) % 7;
}
void PrintDate(short Year, short Month, short Day)
{
    cout << "Date       : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order  : " << ClaculateDate(Year, Month, Day) << endl;
    cout << "Day Name   : " << Days[ClaculateDate(Year, Month, Day)] << endl;
}
int main()
{
    short Year = GetPositiveNumber("Please Enter a Year: "); 
    short Month = GetPositiveNumber("Please Enter a Month: "); 
    short Day = GetPositiveNumber("Please Enter a Day: "); 

    PrintDate(Year, Month, Day);

}