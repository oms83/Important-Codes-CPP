#include<iostream>
using namespace std;
void PrintFibonacci(int Number, int Perv1, int Perv2)
{
    int FebNumber=0;
    if(Number>0)
    {
        FebNumber = Perv1 + Perv2;
        Perv2 = Perv1;
        Perv1 = FebNumber;
        cout << FebNumber << "    ";
        return PrintFibonacci(Number-1, Perv1, Perv2);
    }
}
int main()
{
    PrintFibonacci(10, 0, 1);
}