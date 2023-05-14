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

bool ComparisonDate(stDate Date1, stDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

int main()
{
    system("cls");
    
    stDate Date1;
    GetDate(Date1);
    PrintDate(Date1);

    stDate Date2;
    GetDate(Date2);
    PrintDate(Date2);


    if(ComparisonDate(Date1, Date2)==true)
        cout << "Yes: Date1 Equal Date2. " << endl;
    else
        cout << "No: Date1 Not Equal Date2. " << endl;
    system("pause>0");

    // return (Date1.Year < Date2.Year) ?   true   :   ( (Date1.Year==Date2.Year)?  (Date1.Month < Date2.Month?   true   :    (Date1.Month==Date2.Month  ? Date1.Day < Date2.Day : false))   :   false );
}