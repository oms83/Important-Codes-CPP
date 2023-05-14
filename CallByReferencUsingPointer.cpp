#include<iostream>
using namespace std;
void rSwap(int &a, int &b)
{
    int Temp = a;
    a = b;
    b = Temp;
}
void pSwap(int *a, int *b)
{
    int Temp = *a;
    *a = *b;
    *b = Temp;
}
int main()
{
    int x=7, y=4;
    cout << "x: " << x << "  y: " << y << endl;
    pSwap(&x, &y);
    cout << "x: " << x << "  y: " << y << endl;
    rSwap(x, y);
    cout << "x: " << x << "  y: " << y << endl;
}