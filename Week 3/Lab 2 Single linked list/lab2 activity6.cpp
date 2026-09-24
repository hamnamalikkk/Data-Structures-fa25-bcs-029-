#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

void insert_end(int value)
{
    Node* p = new Node;
    p->data = value;
    p->next = NULL;

    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}

void delete_last()
{
    if (first == NULL)
    {
        cout << "Linked List is empty.";
        return;
    }

    Node* q = first;
    Node* q1 = NULL;

    while (q != last)
    {
        q1 = q;
        q = q->next;
    }

    if (q == first)
    {
        first = last = NULL;
    }
    else
    {
        q1->next = NULL;
        last = q1;
    }

    delete q;

    cout << "Last node deleted.";
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

    delete_last();

    cout << "\nLinked List: ";
    display();

    return 0;
}