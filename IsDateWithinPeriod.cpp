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

struct stPeriod
{
    stDate Start;
    stDate End;
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

// bool IsDateWithinPeriod(stPeriod Period, stDate Date) 
// { 
//     return ( Date1AfterDate2(Period.End, Date) && IsDate1BeforeDate2(Period.Start, Date) ) || IsDate1EqualDate2(Date, Period.End) || IsDate1EqualDate2(Date, Period.Start); 
// }

bool IsDateWithinPeriod(stPeriod Period, stDate Date) 
{ 
    return !( Date1AfterDate2(Date, Period.End) || IsDate1BeforeDate2(Date, Period.Start) ); 
}
void PrintDate(stDate Date)
{
    cout << "\nToday is " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
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

    cout << "\nEnter Date: \n";
    Period.End = GetDate();

    return Period;
}

int main()
{
    system("cls");

    cout << "\nEnter Period 1: ";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Date: ";
    stDate Date = GetDate();

    // stPeriod S[2] = {StartDate1, EndDate1};
    // stPeriod E[2] = {StartDate2, EndDate2};

    if(IsDateWithinPeriod(Period1, Date))
        cout << "Yes: Date Within Period\n";
    else
        cout << "No: Date Without Period\n";


    

    // cout << "Compare Result: " << CompareF(Date1, Date2) << endl;
    system("pause>0");
}