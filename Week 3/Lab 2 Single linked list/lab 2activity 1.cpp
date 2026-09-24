#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

void insert_end()
{
    Node* p = new Node;

    cout << "Enter data: ";
    cin >> p->data;

    p->next = NULL;

    if (first == NULL)
    {
        first = last = p;
    }
    else
    {
        last->next = p;
        last = p;
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
    insert_end();
    insert_end();
    insert_end();

    cout << "Linked List: ";
    display();

    return 0;
}