#include<iostream>
#include<string>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
public:
    string GetFirstName()
    {
        return _FirstName;
    }
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetLastName()
    {
        return _LastName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

};
int main()
{
    clsPerson Person1;
    Person1.FirstName = "omer";
    cout << Person1.FirstName << endl;
    
}