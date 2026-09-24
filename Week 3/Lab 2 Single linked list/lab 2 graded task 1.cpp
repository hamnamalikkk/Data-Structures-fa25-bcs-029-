#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
void insert(Node*& first, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL)
    {
        first = newNode;
        return;
    }

    Node* p = first;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = newNode;
}

// Display linked list
void display(Node* first)
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Reverse display using loop
void reverseDisplay(Node* first)
{
    int count = 0;
    Node* p = first;

    // Count nodes
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    // Print from last node to first
    for (int i = count - 1; i >= 0; i--)
    {
        p = first;

        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }

        cout << p->data << " ";
    }
}

// Reverse display using recursion
void reverseRecursive(Node* p)
{
    if (p == NULL)
        return;

    reverseRecursive(p->next);

    cout << p->data << " ";
}

int main()
{
    Node* first = NULL;

    insert(first, 10);
    insert(first, 20);
    insert(first, 30);
    insert(first, 40);

    cout << "Original Linked List: ";
    display(first);

    cout << "\n\nReverse using Loop: ";
    reverseDisplay(first);

    cout << "\nReverse using Recursion: ";
    reverseRecursive(first);

    return 0;
}