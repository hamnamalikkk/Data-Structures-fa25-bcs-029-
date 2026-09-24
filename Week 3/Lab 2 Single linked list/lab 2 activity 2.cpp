#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* first = NULL;
Node* last = NULL;

void insert_start()
{
    Node* p = new Node;

    cout << "Enter data: ";
    cin >> p->data;

    if (first == NULL)
    {
        p->next = NULL;
        first = last = p;
    }
    else
    {
        p->next = first;
        first = p;
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
    insert_start();
    insert_start();
    insert_start();

    cout << "Linked List: ";
    display();

    return 0;
}