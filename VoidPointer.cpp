#include<iostream>
using namespace std;
int main()
{
    void *Ptr;
    int x=10;
    Ptr = &x;
    cout << Ptr << endl;
    cout << *(static_cast<int*>(Ptr)) << endl;
    int ptrValue = *(static_cast<int *>(Ptr));
    cout << ptrValue << endl;

    int a = 10;
    int &b = a;
    cout << b << endl;
    cout << &b << endl;
    cout << &a << endl;
    int *ptr = &a;
    cout << ptr << endl;
    cout << &ptr << endl; 
    
}