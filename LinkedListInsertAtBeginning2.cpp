#include<iostream>
using namespace std; 

struct Node
{
    Node *Next;
    int Value;
};
void InsertAtBeginning(Node* &Head, int Value)
{
    Node *NewNode = new Node();
    NewNode->Next = Head;
    NewNode->Value = Value;
    
    Head = NewNode;

}

void PrintList(Node *Head)
{
    while (Head != NULL)
    {
        cout << Head->Value << "\t";
        Head = Head->Next;
    }

}


int main()
{
    Node *Head = NULL;
    InsertAtBeginning(Head, 1);
    // head => |1|NULL|
    InsertAtBeginning(Head, 2);
    // head => |2|node1| => |1|NULL|
    InsertAtBeginning(Head, 3);
    // head => |3|node2|  =>  |2|node1|  =>  |1|NULL|
    InsertAtBeginning(Head, 4);
    // head => |4|node3|  =>  |3|node2|  =>  |2|node1|  =>  |1|NULL|

    PrintList(Head);
    
}

