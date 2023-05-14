#include<iostream>  
using namespace std;

class cls
{
    public:

        int x=50;
        void print()
        {
            cout << "x: " << x << endl;
        }    
};

void Func1(cls Obj)
{
    Obj.x = 300;
}

void Func2(cls& Obj)
{
    Obj.x = 500;
}

int main()
{
    system("cls");
    
    cls Obj;
    Obj.x = 100;

    Func1(Obj);
    Obj.print();

    Func2(Obj);
    Obj.print();

    system("pause>0");
}