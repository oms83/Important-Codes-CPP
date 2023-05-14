#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout << "|---------|------------------------------|---------|" << endl;
    cout << "|  Code   |              Name            |  Mark   |" << endl;
    cout << "|---------|------------------------------|---------|" << endl;
    cout << "|" << setw(9) << "Mat116" << "|" << setw(30) << "Matematik" << "|" << setw(9) << "99" << "|" <<  endl; 
    cout << "|" << setw(9) << "Mat227" << "|" << setw(30) << "Diferansiyel" << "|" << setw(9) << "100" << "|" << endl; 
    cout << "|" << setw(9) << "YMU113" << "|" << setw(30) << "Algoritma" << "|" << setw(9) << "90" << "|" << endl; 
    cout << "|---------|------------------------------|---------|" << endl;
}