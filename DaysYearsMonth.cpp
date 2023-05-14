#include<iostream>
using namespace std;

short ReadAPositiveNumber()
{
    short Number;
    do
    {
        cout << "Enter Year: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}
bool IsLeapYear(short Year)
{
    return (Year%400==0) || ( (Year%4 == 0) && (Year%100 != 0) ) ? true : false; 
}
void CalculateDate(short Year, short Days)
{
    cout << "Number Of Days    in Year [" << Year << "] is " << Days << endl;
    cout << "Number Of Hours   in Year [" << Year << "] is " << Days*24 << endl;
    cout << "Number Of Minutes in Year [" << Year << "] is " << Days*24*60 << endl;
    cout << "Number Of Seconds in Year [" << Year << "] is " << Days*24*60*60 << endl19;
}
void PrintDate()
{
    short Year = ReadAPositiveNumber();
    if(IsLeapYear(Year))
        CalculateDate(Year, 366);
    else
        CalculateDate(Year, 365);

}
int main()
{
    PrintDate();
}