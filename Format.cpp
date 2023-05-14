#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int MyRound(float Number)
{
    float part;
    part = Number - int(Number);
    if(Number>0)
    {
        if(part> .5)
            return int(Number+1);
        else
            return int(Number);
    }
    else
    {
        if(part> -.5)
            return int(Number);
        else
            return int(Number-1);
    }
    return Number;
}
int main()
{
    cout << MyRound(-2.3) << endl;
    cout << MyRound(-2.6) << endl;
}