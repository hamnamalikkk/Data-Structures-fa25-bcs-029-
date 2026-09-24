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

void delete_first()
{
    if (first == NULL)
    {
        cout << "Linked List is empty.";
    }
    else
    {
        Node* p = first;
        first = first->next;

        if (first == NULL)
            last = NULL;

        delete p;

        cout << "First node deleted.";
    }
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

    delete_first();

    cout << "\nLinked List: ";
    display();

    return 0;
}