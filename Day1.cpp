// DONE in Day1 :
/*  1. Creation of linked List
    2. Insertion at front, back and at position
 */

// TODO
/*  1. Deletion [Done]
    2. Algoritms Important
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtLast(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    head = curr;
}

void insertAtFront(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void insertAtPos(Node *&head, int data, int pos)
{
    Node *newNode = new Node(data);
    int position = 0;
    Node *curr = head;
    while (curr->next != NULL && position < pos)
    {
        curr = curr->next;
        position++;
    }
    if (curr->next == NULL && pos == position)
    {
        curr->next = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int main()
{
    Node *head = new Node(10);
    insertAtLast(head, 20);
    insertAtFront(head, 5);
    insertAtPos(head, 6, 1);
    insertAtPos(head, 160, 4);
    printList(head);
    return 0;
}