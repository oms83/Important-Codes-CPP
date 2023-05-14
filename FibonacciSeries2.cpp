#include<string>
#include<iostream>
using namespace std;
int ReadAPositiveNumber()
{
    int Number;
    do
    {
        cout << "Enter a positive number: ";
        cin >> Number;
    }
    while(Number<0);
    return Number;
}
void FibonacciS(int Number)
{
    short perv1=1;
    short perv2=0;
    short FibNumber=0;
    cout << perv1 << "  ";
    for(int i=0; i<Number-1; i++)
    {
        FibNumber = perv1 + perv2;
        cout << FibNumber << "  ";
        perv2 = perv1;
        perv1 = FibNumber;
    }
}
int main()
{
    FibonacciS(ReadAPositiveNumber());   

    string str = "hello my name is omer my grandfather names omer";
    str.replace(str.find("omer"), 4, "ali");
    str.replace(str.find("omer"), 4, "ali");
    cout << endl << str << endl;
}