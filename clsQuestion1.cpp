#include<iostream>
using namespace std;

class clsPerson
{
private:

    int _ID;
    string _FirstName;
    string _LastName;
    string _FullName;
    string _Email;
    string _Phone;

public:

    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = _ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _FullName = FirstName + " " + LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void SetID(int ID) { _ID = ID; }
    int GetID() { return _ID; }

    void SetFirstName(string FirstName) { _FirstName = FirstName; }
    string GetFirstName() { return _FirstName; }

    void SetLastName(string LastName) { LastName = LastName; }
    string GetLastName() { return _LastName; }

    void SetEmail(string Email) { _Email = Email; }
    string GetEmail() { return _Email; }

    void SetPhone(string Phone) { _Phone = Phone; }
    string GetPhone() { return _Phone; }

    void Print()
    {
        cout << "First Name: " << _FirstName << endl;
        cout << "Last Name: " << _LastName << endl;
        cout << "Full Name: " << _FullName << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "Email: " << _Email << endl;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "The following message sent successfully to mail: " << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl;
    }

    void SendSMS(string Body)
    {
        cout << "The following message sent successfully to phone: " << _Phone << endl;
        cout << Body << endl;
    }

    // __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    // __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    // __declspec(property(get = GetEmail, put = SetEmail)) string Email;
    // __declspec(property(get = GetPhone, put = SetPhone)) string Phone;
};

class clsEmployee : public clsPerson
{
    private:
    
        string _Title;
        float _Salary;
        string _Department;

    public:

        clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, float Salary, string Department)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
        {
            _Title = Title;
            _Salary = Salary; 
            _Department = Department;
        }

        void SetTitle(string Title) { _Title = Title; }
        string GetTitle() { return _Title; }

        void SetDepartment(string Department) { _Department = Department; }
        string GetDepartment() { return _Department; }

        void SetSalary(float Salary) { _Salary = Salary; }
        float GetSalary() { return _Salary; }

        void Print()
        {
            clsPerson::Print();
            cout << "Salary: " << _Salary << endl;
            cout << "Department: " << _Department << endl;
            cout << "Title: " << _Title << endl;
        }

};

class clsDeveloper : public clsEmployee
{
    private:

        string _MainProgrammingLanguage;

    public:

        clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, float Salary, string Department, string MainProgrammingLanguage)
        : clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Salary, Department)
        {
            _MainProgrammingLanguage = MainProgrammingLanguage;
        }
        string GetMainProgrammingLanguage() { return _MainProgrammingLanguage; }
        void SetMainProgrammingLanguage(string MainProgrammingLanguage) { _MainProgrammingLanguage = MainProgrammingLanguage; }
        void Print()
        {
            clsEmployee::Print();
            cout << "Main Programming Language: " << _MainProgrammingLanguage << endl;
        }
};

int main()
{
    system("cls");
    clsDeveloper Developer1(44, "Omer", "MEMES", "omer.memes20@gmail.com", "05398914803", "OMS", 9550, "Software Engineer", "C++");
    Developer1.Print();
    system("pause>0");
    
}