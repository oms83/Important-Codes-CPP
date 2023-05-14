#include<iostream>
#include<vector>
using namespace std;
struct stEmployee
{
    string FirstName;
    string LastName;
    int Salary;
};

int main()
{
    vector <stEmployee> vEmployees;
    struct stEmployee TempEmplyee;

    TempEmplyee.FirstName = "Omer";
    TempEmplyee.LastName = "Memes";
    TempEmplyee.Salary = 10000;

    vEmployees.push_back(TempEmplyee);
    TempEmplyee.FirstName = "Ali";
    TempEmplyee.LastName = "Memes";
    TempEmplyee.Salary = 8090;
    vEmployees.push_back(TempEmplyee);

    TempEmplyee.FirstName = "Osman";
    TempEmplyee.LastName = "Memes";
    TempEmplyee.Salary = 10000;
    vEmployees.push_back(TempEmplyee);

    for(stEmployee &Employee : vEmployees)
    {
        cout << "First Name: " << Employee.FirstName << endl;
        cout << "Last Name : " << Employee.LastName << endl;
        cout << "Salary    : " << Employee.Salary << endl;
        cout << endl;
    }   
}