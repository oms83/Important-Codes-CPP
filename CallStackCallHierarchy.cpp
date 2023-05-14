#include<iostream>
using namespace std;
void Koko();
void Function4()
{
    cout << "Call Stack Function2 & Call Hierarchy";
}
void Function3()
{
    Function4();
}
void Koko()
{
    Function3();
}
void Function1()
{
    Koko();
    Function4();
}
int main()
{
    Function1();
}