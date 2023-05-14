#include<iostream>
using namespace std;

struct Node
{
    Node* Next;
    int Value;
};
void InsertAtBeginning(Node* &Head, int Value)
{
    Node* NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Next = Head;

    Head = NewNode;
    
}

void PrintList(Node *Head)
{
    while(Head!=NULL)
    {
        cout << Head->Value << "  ";
        Head = Head->Next;
    }
}

int main()
{
    Node* Head = NULL;

    InsertAtBeginning(Head, 1);
    InsertAtBeginning(Head, 1);
    InsertAtBeginning(Head, 1);
    InsertAtBeginning(Head, 1);

    PrintList(Head);


}