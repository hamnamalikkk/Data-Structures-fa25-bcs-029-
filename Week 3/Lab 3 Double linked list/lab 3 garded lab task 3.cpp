#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* first = NULL;
Node* last = NULL;

void insert_end(int value)
{
    Node* p = new Node;

    p->data = value;
    p->next = NULL;
    p->prev = NULL;

    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
    }
}

void swapNodes(int value1, int value2)
{
    Node* node1 = first;
    Node* node2 = first;

    while (node1 != NULL && node1->data != value1)
        node1 = node1->next;

    while (node2 != NULL && node2->data != value2)
        node2 = node2->next;

    if (node1 == NULL || node2 == NULL)
    {
        cout << "One or both values not found.";
        return;
    }

    if (node1 == node2)
    {
        cout << "Both values are the same.";
        return;
    }

    // If node1 is before node2
    Node* temp;

    if (node1->next == node2)
    {
        temp = node1->prev;

        if (node1->prev != NULL)
            node1->prev->next = node2;

        if (node2->next != NULL)
            node2->next->prev = node1;

        node1->next = node2->next;
        node2->prev = temp;

        node2->next = node1;
        node1->prev = node2;
    }
    else if (node2->next == node1)
    {
        temp = node2->prev;

        if (node2->prev != NULL)
            node2->prev->next = node1;

        if (node1->next != NULL)
            node1->next->prev = node2;

        node2->next = node1->next;
        node1->prev = temp;

        node1->next = node2;
        node2->prev = node1;
    }
    else
    {
        Node* prev1 = node1->prev;
        Node* next1 = node1->next;

        Node* prev2 = node2->prev;
        Node* next2 = node2->next;

        if (prev1 != NULL)
            prev1->next = node2;

        if (next1 != NULL)
            next1->prev = node2;

        if (prev2 != NULL)
            prev2->next = node1;

        if (next2 != NULL)
            next2->prev = node1;

        node1->prev = prev2;
        node1->next = next2;

        node2->prev = prev1;
        node2->next = next1;
    }

    if (first == node1)
        first = node2;
    else if (first == node2)
        first = node1;

    if (last == node1)
        last = node2;
    else if (last == node2)
        last = node1;

    cout << "Nodes swapped successfully.";
}

void display()
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    cout << "Original List: ";
    display();

    int value1, value2;

    cout << "\nEnter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;

    swapNodes(value1, value2);

    cout << "\nAfter swapping nodes: ";
    display();

    return 0;
}