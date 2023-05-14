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

short NumberOfDaysInAMonth(short Year, short Month)
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
string GetMonth(short Month)
{
    string Months[12] = { "Jan", "Feb", "Mar", "Epr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; 
    return Months[Month-1];
}

void PrintMonthCalendar(short Year, short Month) 
{ 
    int NumberOfDays; 
    
    int current = DayOfWeekOrder(Year, Month, 1);    

    NumberOfDays = NumberOfDaysInAMonth(Year, Month); 

    printf("\n  _______________%s_______________\n\n", GetMonth(Month).c_str() ); 

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
    
    int i; 
    
    for (i = 0; i < current; i++)         
        printf("     "); 
    

    for (int j = 1; j <= NumberOfDays; j++)     
    {         
        printf("%5d", j); 
        
            if (++i == 7)         
            {             
                i = 0;             
                printf("\n");         
            }     
    }    

    printf("\n  _________________________________\n"); 
    
}
 
void PrintfYearCalender(short Year)
{
    for(short Month=1; Month<=12; Month++)
    {
        PrintMonthCalendar(Year, Month);
        cout << endl << endl;
    }
}
int main()
{
    system("cls");
    short Year = GetPositiveNumber("Enter a year: ");

    PrintfYearCalender(Year);

    system("pause>0");
}