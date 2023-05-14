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

short Compare(stDate Date1, stDate Date2)
{
    if(IsDate1BeforeDate2(Date1, Date2))
        return -1;
    else if(IsDate1EqualDate2(Date1, Date2))
        return 0;
    else
        return 1;
}
short CompareF(stDate Date1, stDate Date2)
{
    return IsDate1BeforeDate2(Date1, Date2) ? -1 : ( IsDate1EqualDate2(Date1, Date2) ? 0 : 1 ); 
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

    cout << endl; 

    stDate Date2;
    GetDate(Date2);

    cout << "Compare Result: " << CompareF(Date1, Date2) << endl;
    system("pause>0");
}