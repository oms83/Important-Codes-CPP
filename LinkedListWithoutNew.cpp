#include<iostream>
using namespace std;

// struct Node
// {
//     int Value;
//     Node *Next;
// };
class Node
{
    public:

        Node *Next;
        short Value;
};

int main()
{

    Node *Head;

    Node *Node1 = NULL;
    Node *Node2 = NULL;
    Node *Node3 = NULL;
    Node N1,N2,N3;
    // Node1 = new Node();
    // Node2 = new Node();
    // Node3 = new Node();

    N1.Value = 1;
    N2.Value = 2;
    N3.Value = 3;

    N1.Next = N2.Next;
    N2.Next = N3.Next;
    N3.Next = NULL;

    Node1 = &N1;
    Node2 = &N2;
    Node3 = &N3;

    Head = Node1;
    while(Head != NULL)
    {
        cout << Head->Value << "    ";
        Head = Head->Next;
    }

    // short *p1;
    // short x=5;
    // short *p2;
    // // p1 = &x;
    // // // p1 = new short;
    // // // *p1 = 5;
    // // cout << *p1; 


    // p1 = &x;
    // p2 = p1;

    // cout << endl << *p2 << endl;
    
    // int a = 10;
    // int &b = a;

    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl << endl;

    // cout << "&a: " << &a << endl;
    // cout << "&b: " << &b << endl << endl;

}
