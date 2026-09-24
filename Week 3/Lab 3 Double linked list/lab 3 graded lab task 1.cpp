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

void reverseList()
{
    Node* current = first;
    Node* temp;

    while (current != NULL)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    temp = first;
    first = last;
    last = temp;
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

    reverseList();

    cout << "\nReversed List: ";
    display();

    return 0;
}