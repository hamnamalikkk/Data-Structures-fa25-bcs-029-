#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
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

// Display list
void display(Node* first)
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Merge two lists into a new third list
Node* mergeLists(Node* first, Node* second)
{
    Node* third = NULL;

    Node* p = first;

    while (p != NULL)
    {
        insert(third, p->data);
        p = p->next;
    }

    p = second;

    while (p != NULL)
    {
        insert(third, p->data);
        p = p->next;
    }

    return third;
}

int main()
{
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // First list
    insert(first, 10);
    insert(first, 20);
    insert(first, 30);

    // Second list
    insert(second, 40);
    insert(second, 50);
    insert(second, 60);

    cout << "First List: ";
    display(first);

    cout << "\nSecond List: ";
    display(second);

    third = mergeLists(first, second);

    cout << "\nMerged List: ";
    display(third);

    return 0;
}