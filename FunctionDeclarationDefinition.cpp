#include<iostream>
using namespace std;

// Function Declaration
int add(int, int);
// Default Parameters
int MySum(int a, int b, int c=0, int d=0)
{
    return a+b+c+d;
}

// Function Overlaoding
int FunctionOverlaoding(int a, int b)
{
    return a+b;
}
int FunctionOverlaoding(int a, int b, int c)
{
    return a+b+c;
}
int FunctionOverlaoding(int a, int b, int c, int d)
{
    return a+b+c+d;
}
void FunctionOverlaoding(string Message)
{
    cout << "Hello " << Message << endl;
}
int main()
{
    // // Function Declaration  Function Definition
    // cout << add(10, 20);

    // // Default Parameters
    // cout << MySum(10, 12);

    // // Function Overlaoding
    cout << FunctionOverlaoding(2,3) << endl;
    cout << FunctionOverlaoding(2,3,5) << endl;
    cout << FunctionOverlaoding(2,3,5,7) << endl;
    FunctionOverlaoding("omer");

}
// Function Definition
int add(int a, int b)
{
    return a+b;
}