#include<iostream>  
#include<vector>

using namespace std;

class cls
{
    public:
        cls()
        {

        }
        cls(int Value)
        {
            x = Value;
        }
        int x;
        void Print()
        {
            cout << "X: " << x << endl;
        }
};

int main()
{
    system("cls");

    short NumberOfObject = 5;
    
    // cls* arr = new cls[NumberOfObject]; 
    // cls arr[5];
    // for(short i=0; i<5; i++)
    // {
    //     arr[i] = cls(i);
    // }
    
    cls arr[5] = { cls(10), cls(20), cls(30), cls(40), cls(50) };

    for(short i=0; i<5; i++)
    {
        arr[i].Print();
    }

    system("pause>0");
}