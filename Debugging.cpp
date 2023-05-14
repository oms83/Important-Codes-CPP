#include<iostream>
using namespace std;
int MySum(int a, int b)
{
	return a + b;
}
int main()
{
	int arr[5] = { 10, 20, 43, 65, 29 };
	int a, b, c;
	a = 10;
	b = 20;
	
	a++;
	++b;

	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	for (short i = 1; i <= 5; i++)
	{
		cout << i << endl;
		a = a * i + a;
	}
	
	c = MySum(a, b);

	cout << c << endl;

}