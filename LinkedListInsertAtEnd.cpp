
#include<iostream>
using namespace std;

struct Node
{

    Node *Next;
    int Value;

};

// class Node
// {
// public:
//     int Value;
//     Node* Next;
// };

void InsertInBeginning(Node* &Head, int Value)
{
    Node* NewNode = new Node();
    
    NewNode->Next = Head;
    NewNode->Value = Value;

    Head = NewNode;
}

void Print(Node* Head)
{
    while (Head != NULL)
    {
        cout << Head->Value << "\t";

        Head = Head->Next;


    }

}

Node *Find(Node *Head, int Value)
{
    while (Head != NULL)
    {
        if (Head->Value == Value)
        {
            return Head;
        }
        Head = Head->Next;
    }
    return NULL;
}

void InsertAfter(Node* prev_node, int Value) {

    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->Value = Value;
    new_node->Next = prev_node->Next;
    prev_node->Next = new_node;
}

int main()
{
    Node *Head = NULL;

    InsertInBeginning(Head, 1);
    InsertInBeginning(Head, 2);
    InsertInBeginning(Head, 3);
    InsertInBeginning(Head, 4);
    InsertInBeginning(Head, 5);

    Node* N1 = NULL;
    N1 = Find(Head, 2);

    InsertAfter(N1, 70);
    Print(Head);


    // if (N1 != NULL)
    //     cout << "Node found \n";
    // else
    //     cout << "Node Is not found\n";
}
