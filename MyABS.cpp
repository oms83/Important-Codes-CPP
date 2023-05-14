#include<iostream>
#include<cmath>
using namespace std;

float ReadNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}
float MyABS(float Number)
{
    if(Number>=0)
        return Number;
    else
        return Number*(-1);
}
int main()
{
    float Number = MyABS(ReadNumber("Enter any number:: "));
    cout << "MyABS:: " << Number; 
    cout << "\nC++ abs:: " << Number; 
}