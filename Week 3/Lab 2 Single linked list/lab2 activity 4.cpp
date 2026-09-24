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

void insert_after(int key, int value)
{
    Node* p = first;

    while (p != NULL && p->data != key)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Value not found.";
    }
    else
    {
        Node* newNode = new Node;
        newNode->data = value;

        newNode->next = p->next;
        p->next = newNode;

        if (p == last)
        {
            last = newNode;
        }

        cout << "Node inserted successfully.";
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

    int key, value;

    cout << "Enter value after which you want to insert: ";
    cin >> key;

    cout << "Enter new value: ";
    cin >> value;

    insert_after(key, value);

    cout << "\nLinked List: ";
    display();

    return 0;
}