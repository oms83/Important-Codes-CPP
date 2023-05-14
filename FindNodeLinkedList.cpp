

// #include <iostream>
// using namespace std;

// // Create a node
// class Node
// {
// public:
//     int value;
//     Node* next;
// };

// void InsertAtBeginning(Node*& head, int value)
// {
//     // Allocate memory to a node
//     Node* new_node = new Node();

//     // insert the data
//     new_node->value = value;
//     new_node->next = head;

//     // Move head to new node
//     head = new_node;

// }

// Node *Find(Node* head, int Value)
// {

//     while (head != NULL) {

//         if (head->value == Value)
//             return head;


//         head = head->next;
//     }

//     return NULL;


// }


// // Print the linked list
// void PrintList(Node* head)

// {
//     while (head != NULL) {
//         cout << head->value << " ";
//         head = head->next;
//     }
// }

// int main()
// {
//     Node* head = NULL;
//     InsertAtBeginning(head, 1);
//     InsertAtBeginning(head, 2);
//     InsertAtBeginning(head, 3);
//     InsertAtBeginning(head, 4);
//     InsertAtBeginning(head, 5);

//     PrintList(head);

//     Node* N1 = Find(head, 9);

//     if (N1 != NULL)
//         cout << "\nNode Found :-)\n";
//     else
//         cout << "\nNode Is not found :-(\n";


//     system("pause>0");

// }


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

int main()
{
    Node *Head = NULL;

    InsertInBeginning(Head, 1);
    InsertInBeginning(Head, 2);
    InsertInBeginning(Head, 3);
    InsertInBeginning(Head, 4);
    InsertInBeginning(Head, 5);

    Node* N1 = Find(Head, 7);

    if (N1 != NULL)
        cout << "Node found \n";
    else
        cout << "Node Is not found\n";
}

