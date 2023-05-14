#include<iostream>
#include<string>
using namespace std;

string TextNumber(int Number)
{
    string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    
    string Tens[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    if(Number<20)
        return arr[Number] + " ";
    
    else if(Number<100)
        return Tens[Number/10] + " " + TextNumber(Number%10);
        
    else if(Number<1000)
        return TextNumber(Number/100) + " Hundred " + TextNumber(Number%100);

    else if(Number<1000000)
        return TextNumber(Number/1000) + " Thousands " + TextNumber(Number%1000);

    else if(Number<1000000000)
        return TextNumber(Number/100000) + " Million " + TextNumber(Number%100000);
    
    else if(Number<1000000000000)
        return TextNumber(Number/1000000000) + " Billion " + TextNumber(Number%1000000000);
}
int ReadAPositiveNumber()
{
    int Number;
    do
    {
        cout << "Enter Any Number: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}

int main()
{
    system("cls");
    int Number = ReadAPositiveNumber();
    cout << TextNumber(Number);
    system("pause>0");
}