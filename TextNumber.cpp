#include<iostream>
#include<string>
using namespace std;

int GetPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;

    }while(Number<0);

    return Number;
}
string TextNumber(int Number)
{
    string Numbers[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine", "ten", "eleven", "twelve", "thirteen",
                        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string Tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    if(Number<20)
        return Numbers[Number] + " ";
    else if(Number<100)
        return Tens[Number/10] + " " + Numbers[Number%10] + " ";
    else if(Number<1000)
        return TextNumber(Number/100) + " " + "hundred" + " " + TextNumber(Number%100) + " ";
    else if(Number<1000000)
        return TextNumber(Number/1000) + " " + "thousand" + " " + TextNumber(Number%1000) + " ";
    else if(Number<1000000000)
        return TextNumber(Number/1000000) + " " + "million" + " " + TextNumber(Number%1000000) + " ";
    else if(Number<1000000000000)
        return TextNumber(Number/1000000000) + " " + "billion" + " " + TextNumber(Number%1000000000) + " ";
   
}
int main()
{
    system("cls");
    int Number = GetPositiveNumber("Enter a positive number: ");
    cout << TextNumber(Number);
    system("pause>0");
}