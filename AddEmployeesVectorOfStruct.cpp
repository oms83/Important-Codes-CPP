#include<iostream>
#include<vector>
using namespace std;
struct stEmployee
{
    string FirstName;
    string LastName;
    int Salary;
};
void AddEmployees(vector <stEmployee> &vEmployees)
{
    char AddMore = 'Y';
    stEmployee TempEmployee;
    do
    {
        cout << "Enter The First Name For Emplyee: ", cin >> TempEmployee.FirstName;
        cout << "Enter The Last Name For Emplyee: ", cin >> TempEmployee.LastName;
        cout << "Enter The Salary For Emplyee: ", cin >> TempEmployee.Salary;
        vEmployees.push_back(TempEmployee);
        cout << "Do you want to add more emplyees ? ", cin >> AddMore;
    }while(AddMore=='Y'||AddMore=='y');
}
void PrintEmployeesInfo(vector <stEmployee> &vEmployees)
{
    for(stEmployee &Employee : vEmployees)
    {
        cout << "First Name: " << Employee.FirstName << endl;
        cout << "Last Name : " << Employee.LastName << endl;
        cout << "Salary    : " << Employee.Salary << endl;
        cout << endl;
    } 
}
int main()
{
    vector <stEmployee> vEmployees;
    AddEmployees(vEmployees);
    PrintEmployeesInfo(vEmployees);
}