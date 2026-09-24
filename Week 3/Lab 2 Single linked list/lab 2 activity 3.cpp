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
    {
        first = last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

Node* search(int key)
{
    Node* p = first;

    while (p != NULL && p->data != key)
    {
        p = p->next;
    }

    return p;
}

int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);

    int key;

    cout << "Enter value to search: ";
    cin >> key;

    Node* result = search(key);

    if (result != NULL)
        cout << "Value found.";
    else
        cout << "Value not found.";

    return 0;
}