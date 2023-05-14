#include<iostream>
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
    return (Year%400==0) || ( (Year%4 == 0) && (Year%100 != 0) ) ? true : false; 
}

short NumberOfDaysInAMonth(short Year, short Month)
{   
    if(Month<0 || Month>12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1];
}
struct stDate
{
    short Year;
    short Month;
    short Day;
};


void GetDate(stDate &Date)
{
    Date.Year = GetPositiveNumber("Please Enter a Year: "); 
    Date.Month = GetPositiveNumber("Please Enter a Month: "); 
    Date.Day = GetPositiveNumber("Please Enter a Day: ");

    cout << endl << endl;
}
void PrintDate(stDate Date)
{
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

bool LastMonth(stDate Date)
{
    return  NumberOfDaysInAMonth(Date.Year, Date.Month)==Date.Day;
}
bool LastDay(stDate Date)
{
    return  Date.Month==12;
}
int main()
{
    system("cls");
    
    stDate Date;
    GetDate(Date);
    PrintDate(Date);



    if(LastDay(Date))
        cout << "Yes: Is Last Day In Month. " << endl;
    else
        cout << "No: Is Not Last Day In Month. " << endl;

    if(LastMonth(Date))
        cout << "Yes: Is Last Month In Year. " << endl;
    else
        cout << "No: Is Not Last Month In Year. " << endl;
    system("pause>0");

    // return (Date1.Year < Date2.Year) ?   true   :   ( (Date1.Year==Date2.Year)?  (Date1.Month < Date2.Month?   true   :    (Date1.Month==Date2.Month  ? Date1.Day < Date2.Day : false))   :   false );
}