#include<iostream>
using namespace std;

void PrintNumber()
{
    static int Number=1;
    cout << "=> " << Number << endl;
    Number++;
}
int main()
{
    PrintNumber();
    PrintNumber();
    PrintNumber();
}