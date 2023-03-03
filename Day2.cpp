// Day 2:
/*  1. Deletion in Linked List */

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

void deleteLast(Node *&head)
{
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void deleteFirst(Node *&head)
{
    Node *curr = head;
    curr = curr->next;
    free(head);
    head = curr;
}

void deleteAtPosition(Node *&head, int d)
{
    Node *curr = head;
    Node *prev = NULL;
    if (curr->data == d)
    {
        deleteFirst(head);
    }
    else
    {
        while (curr->data != d && curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            deleteLast(head);
        }
        else
        {
            cout << curr->data << endl;
            prev->next = curr->next;
            free(curr);
        }
    }
}

int main()
{
    Node *head = new Node(10);
    insertAtLast(head, 20);
    insertAtFront(head, 5);
    insertAtPos(head, 6, 1);
    insertAtPos(head, 160, 4);
    deleteLast(head);
    deleteFirst(head);
    deleteAtPosition(head, 6);
    printList(head);
    return 0;
}