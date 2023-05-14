#include<queue>
#include<iostream>
using namespace std;

int main()
{
    
    queue <short> MyQueue;
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);

    cout << "Count : " << MyQueue.size() << endl;
    cout << "Front : " << MyQueue.front() << endl;
    cout << "Back : " << MyQueue.back() << endl;

    cout << "Queue items: ";
    while(!MyQueue.empty())
    {
        cout << MyQueue.front() << "  ";
        MyQueue.pop();
    }
    cout << endl << endl;



    queue <short> MyQueue1;
    MyQueue1.push(10);
    MyQueue1.push(20);
    MyQueue1.push(30);
    MyQueue1.push(40);
    
    queue <short> MyQueue2;
    MyQueue2.push(50);
    MyQueue2.push(60);
    MyQueue2.push(70);
    MyQueue2.push(80);

    cout << "Count 1: " << MyQueue1.size() << endl;
    cout << "Front 1: " << MyQueue1.front() << endl;
    cout << "Back 1: " << MyQueue2.back() << endl;

    cout << "Queue 1 items: ";
    while(!MyQueue1.empty())
    {
        cout << MyQueue1.front() << "  ";
        MyQueue1.pop();
    }
    cout << endl << endl;



    cout << "Count 2: " << MyQueue1.size() << endl;
    cout << "Front 2: " << MyQueue1.front() << endl;
    cout << "Back 2: " << MyQueue1.back() << endl;

    cout << "Queue 2 items: ";
    while(!MyQueue2.empty())
    {
        cout << MyQueue2.front() << "  ";
        MyQueue2.pop();
    }
    cout << endl << endl;



    MyQueue1.push(10);
    MyQueue1.push(20);
    MyQueue1.push(30);
    MyQueue1.push(40);
    
    MyQueue2.push(50);
    MyQueue2.push(60);
    MyQueue2.push(70);
    MyQueue2.push(80);

    MyQueue1.swap(MyQueue2);




    cout << "Count 1: " << MyQueue1.size() << endl;
    cout << "Front 1: " << MyQueue1.front() << endl;
    cout << "Back 1: " << MyQueue2.back() << endl;

    cout << "Queue 1 items: ";
    while(!MyQueue1.empty())
    {
        cout << MyQueue1.front() << "  ";
        MyQueue1.pop();
    }
    cout << endl << endl;



    cout << "Count 2: " << MyQueue1.size() << endl;
    cout << "Front 2: " << MyQueue1.front() << endl;
    cout << "Back 2: " << MyQueue1.back() << endl;

    cout << "Queue 2 items: ";
    while(!MyQueue2.empty())
    {
        cout << MyQueue2.front() << "  ";
        MyQueue2.pop();
    }
    cout << endl << endl;



}

