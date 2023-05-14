#include<iostream>
#include<stack>
#include<vector>

using namespace std;


int main()
{
    stack <short> MyStack1;
    stack <short> MyStack2;

    MyStack1.push(10);
    MyStack1.push(20);
    MyStack1.push(30);
    MyStack1.push(40);

    MyStack2.push(50);
    MyStack2.push(60);
    MyStack2.push(70);
    MyStack2.push(80);

    cout << "Size of Stack 1 is : " << MyStack1.size() << endl;
    cout << "Stack 1 Items: ";
    while(!MyStack1.empty())
    {
        cout << MyStack1.top() << "  ";
        MyStack1.pop();
    }
    cout << endl << endl;

    cout << "Size of Stack 2 is : " << MyStack2.size() << endl;
    cout << "Stack 2 Items: ";
    while(!MyStack2.empty())
    {
        cout << MyStack2.top() << "  ";
        MyStack2.pop();
    }
    cout << endl << endl;



    MyStack1.push(10);
    MyStack1.push(20);
    MyStack1.push(30);
    MyStack1.push(40);

    MyStack2.push(50);
    MyStack2.push(60);
    MyStack2.push(70);
    MyStack2.push(80);

    MyStack1.swap(MyStack2);

    
    cout << "Size of Stack 1 is : " << MyStack1.size() << endl;
    cout << "Stack 1 Items: ";
    while(!MyStack1.empty())
    {
        cout << MyStack1.top() << "  ";
        MyStack1.pop();
    }
    cout << endl << endl;

    cout << "Size of Stack 2 is : " << MyStack2.size() << endl;
    cout << "Stack 2 Items: ";
    while(!MyStack2.empty())
    {
        cout << MyStack2.top() << "  ";
        MyStack2.pop();
    }
    cout << endl << endl;
    

    vector <short> vNumbers;
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);

    cout << "Vector istems: ";
    for(short Number : vNumbers)
    {
        cout << Number << "  ";
    }

    

    cout << endl << endl;
    
}
