#include<iostream>
#include<cmath>
using namespace std;

float ReadNumber(string Message)
{
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
}
int MyCeil(float Number)
{
    if(Number>0)
        return int(Number)+1;
    else
        return int(Number);
}
int main()
{
    float Number = MyCeil(ReadNumber("Enter any number:: "));
    cout << "MyCeil:: " << Number; 
    cout << "\nC++ ceil:: " << ceil(Number); 
}
