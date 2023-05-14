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

struct stDate
{
    short Year;
    short Month;
    short Day;
};


void GetDate(stDate Date)
{
    Date.Year = GetPositiveNumber("Please Enter a Year: "); 
    Date.Month = GetPositiveNumber("Please Enter a Month: "); 
    Date.Day = GetPositiveNumber("Please Enter a Day: ");

    cout << endl << endl;
}


void ComparisonDate(stDate &Date1, stDate &Date2)
{
    if(Date1.Year < Date2.Year)
        cout << "Yes: Date1 is less than Date2. " << endl;
    else if(Date1.Month < Date2.Month)
        cout << "Yes: Date1 is less than Date2. " << endl;
    else if(Date1.Day < Date2.Day)
        cout << "Yes: Date1 is less than Date2. " << endl;
    else
        cout << "No: Date1 is not less than Date2. " << endl;
}

int main()
{
    system("cls");
    
    stDate Date1;
    GetDate(Date1);
    
    stDate Date2;
    GetDate(Date2);

    ComparisonDate(Date1, Date2);
    system("pause>0");
}