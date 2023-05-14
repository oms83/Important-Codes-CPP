
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


// #include <iostream>
// using namespace std;

// // Create a node
// class Node
// {
// public:
//     Node* next;
//     int value;
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

// // Insert a node after a node
// void InsertAfter(Node* prev_node, int Value) {

//     if (prev_node == NULL) {
//         cout << "the given previous node cannot be NULL";
//         return;
//     }

//     Node* new_node = new Node();
//     new_node->value = Value;
//     new_node->next = prev_node->next;
//     prev_node->next = new_node;
// }


// // Print the linked list
// void PrintList(Node* head)

// {
//     cout << "\n";
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
//     Node* N1 = NULL;

//     N1 = Find(head, 2);

//     InsertAfter(N1, 7);

//     PrintList(head);

//    /* N1 = Find(head, 500);
//     InsertAfter(N1, 600);
//     PrintList(head);*/

//     system("pause>0");

// }


// #include<iostream>
// using namespace std;

// class Node
// {
//     public:

//         Node* next;
//         int value;
// };

// void InsertAtBeginning(Node *& head, int value)
// {
//     Node *new_node = new Node();

//     new_node->value = value;
//     new_node->next  = head;

//     head = new_node;
// }

// void Print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->value << "\t";
//         head = head->next;
//     }
//     cout << "\n";
// }
// Node *Find(Node* head, int value)
// {
//     while (head != NULL)
//     {
//         if (head->value == value)
//         {
//             return head;
//         }

//         head = head->next;
//     }
//     return NULL;
// }
// void InsertAfter(Node *prev_node, int value)
// {
//     if (prev_node == NULL)
//     {
//         cout << "the given previous node cannot be NULL";
//         return;
//     }

//     Node* new_node = new Node();
//     new_node->value = value;
//     new_node->next = prev_node->next;
//     prev_node->next = new_node; 
// }

// int main()
// {
//     Node *head = NULL;
//     InsertAtBeginning(head, 1);
//     InsertAtBeginning(head, 2);
//     InsertAtBeginning(head, 3);
//     InsertAtBeginning(head, 4);
//     InsertAtBeginning(head, 5);

//     Print(head);

//     Node *N1;
//     N1 = Find(head, 2);

//     InsertAfter(N1, 7);

//     Print(head);
// }