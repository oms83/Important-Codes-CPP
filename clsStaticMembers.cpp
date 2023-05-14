#include<iostream>
using namespace std;

class cls
{
    public:

        int Var;
        static int Counter;

        cls()
        {
            Counter++;
        }
        void Print()
        {
            cout << "Var: " << Var << endl;
            cout << "Counter: " << Counter << endl;
        }
};

int cls::Counter=0;

int main()
{
    cls A, B, C;

    A.Var = 22;
    B.Var = 55;
    C.Var = 77;

    A.Print();
    B.Print();
    C.Print();

    A.Counter = 500;
    
    A.Print();
    B.Print();
    C.Print();


    system("pause>0");
}