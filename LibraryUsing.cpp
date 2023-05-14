#include<iostream>
#include "MyFunc.h"
#include "MyInputLibrary.h"

using namespace std;
using namespace MyLib;
using namespace InputLib;
struct MyInfo
{
	string Name = "Omer";
	string Surname = "Memes";
	short Age = 22;
	string Country = "Syria"
};
int main()
{
	// // MyLib::SeyHello("omer");
	// SeyHello("omer");
	// cout << "omer";
	// cout << "\nSummation of two number:: " << Sum(10, 20) << endl;
	// // cout << "\nSummation of two number:: " << Sum(ReadANumber(), ReadANumber());
	// int Number1, Number2;

	// // Short Hand If
	// Number1 = ReadANumber();
	// (Number1 > 0) ? cout << "Positive" : (Number1<0) ? cout << "Negative" :  cout << "Zero";

	// Ranged Loop
	// collection مجموعة  declaration تصريح  expression تعبير
	
	string Names[3] = {"Omer", "Ali", "Osman"};
	for(string Name : Names)
	{
		cout << Name << endl;
	}
	int Numbers[5] = {1, 2, 3, 4, 5};
	for(int Number : Numbers)
	{
		cout << endl << Number;
	}


}
