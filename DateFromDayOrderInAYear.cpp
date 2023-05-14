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
short NumberOfDaysInAMonth(short Year, short Month=1)
{   
    if(Month<0 || Month>12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month==2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month-1];
}

short TotalDays(short Year, short Month, short Day)
{
    short Total=0;
    for(short i=1; i<=Month-1; i++)
    {
        Total += NumberOfDaysInAMonth(Year, i);
    }
    return Total+Day;
}

void DateFromOrderInYear(short Year, short Month, short Day, short Total)
{
    short Counter=0, Temp;
    Temp=Total;
    for(short i=1; i<=Month-1; i++)
    {
        Total -= NumberOfDaysInAMonth(Year, i);
        Counter++;
    }

    if(Total>=0) Counter+=1;
    if(Total==0) Total+=1;
    cout << "Date For [" << Temp << "] is: " << Total << "/" << Counter << "/" << Year << endl;

}
int main()
{
    system("cls");
    
    short Year = GetPositiveNumber("Please Enter a Year: "); 
    short Month = GetPositiveNumber("Please Enter a Month: "); 
    short Day = GetPositiveNumber("Please Enter a Day: ");
    short Total = TotalDays(Year, Month, Day);
    DateFromOrderInYear(Year, Month, Day, Total);

    system("pause>0");
}