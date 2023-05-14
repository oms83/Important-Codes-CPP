#include<iostream>
using namespace std;
struct stEmployee
{
    string Name;
    int Salary;
};
int main()
{
    stEmployee Employee, *Ptr;
    Employee.Salary = 10000;
    Employee.Name = "Omer";

    cout << "Name   : " << Employee.Name << endl;
    cout << "Salary : " << Employee.Salary << endl;

    Ptr = &Employee;
    cout << "Name   : " << Ptr->Name << endl;
    cout << "Salary : " << Ptr->Salary << endl;
    
}