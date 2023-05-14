#include<iostream>
using namespace std;

class clsPerson
{
    private:
    
        int ID;
        string Name;
        float Salary;



    public:

        clsPerson(int ID, string Name, float Salary)
        {
            this->ID = ID;
            this->Name = Name;
            this->Salary = Salary;
        }
        
        static void Func1(clsPerson Person)
        {
            Person.Print();
        }

        void Func2()
        {
            Func1(*this);
        }

        static void Func3()
        {
            cout << "Hello, i am func3... \n";
        }

        void Print()
        {
            cout << "\nID: " << ID << endl;
            cout << "Name: " << Name << endl;
            cout << "Salary: " << Salary << endl << endl;
        }

};

int main()
{
    system("cls");

    clsPerson::Func3();

    clsPerson Person1(99215, "Omer MEMES", 9500);
    Person1.Print();

    Person1.Func2();

    system("pause>0");
    
    
}