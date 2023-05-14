#include<iostream>  
#include<vector>

using namespace std;

class cls
{
    public:

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

    vector <cls> vCls;
    for(short i=0; i<5; i++)
    {
        vCls.push_back(cls(i));
    }
    
    for(short i=0; i<5; i++)
    {
        vCls.at(i).Print();
    }
    
    system("pause>0");
}