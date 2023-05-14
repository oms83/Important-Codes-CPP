#include<iostream>
using namespace std;
int ReadAPositiveNumber()
{
    int Number=0;
    do
    {
        cout << "Enter a positive number: ";
        cin >> Number;
    }while(Number<0);
    return Number;
}
void PrintFibonacci(int Number, int Temp)
{
    static int Perv1=1, Perv2=0, FibNumber=0;
    if(Number==Temp)
    {
        cout << "1   ";
        PrintFibonacci(Number-1, Temp);
    }
    if(Number == Temp/2)
        return;
    else
    {
        FibNumber = Perv1+Perv2;
        cout << FibNumber << "   ";
        Perv2 = Perv1;
        Perv1 = FibNumber;
        return PrintFibonacci(Number-1, Temp);

    }
}
// int main()
// {
//     int Number = ReadAPositiveNumber();
//     PrintFibonacci(Number, Number);
//     system("pause>0");
// }
void printFibonacciSeriesUsingRecurssion(short number, int prev1, int prev2) {
	int result;
	result = prev1 + prev2;
	cout << result << "   ";
	prev2 = prev1;
	prev1 = result;
	if (number > 2)
		printFibonacciSeriesUsingRecurssion(number - 1, prev1, prev2);
}
int main() {
	srand((unsigned)time(NULL));
	cout << "1   ";
	printFibonacciSeriesUsingRecurssion(10, 1, 0);
	system("pause>0");
	return 0;
}
// previous سابق متقدم