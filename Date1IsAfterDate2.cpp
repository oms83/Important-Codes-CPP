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

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month==Date2.Month ? Date1.Day<Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false ) : false;
}

bool Date1AfterDate2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

stDate GetDate(stDate& Date)
{
    Date.Day = GetPositiveNumber("Enter a day: ");
    Date.Month = GetPositiveNumber("Enter a month: ");
    Date.Year = GetPositiveNumber("Enter a year: ");

    return Date;
}

int main()
{
    system("cls");
    
    stDate Date1;
    GetDate(Date1);

    stDate Date2;
    GetDate(Date2);

    if(Date1AfterDate2(Date1, Date2))
        cout << "Yes: Date1 is After Date2 \n";
    else 
        cout << "No: Date1 Is Not  After Date2 \n";
    
    system("pause>0");
}