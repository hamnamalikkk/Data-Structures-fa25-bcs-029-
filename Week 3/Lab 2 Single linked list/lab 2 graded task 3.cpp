#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

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

void display(Node* first)
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Find occurrences
void findOccurrences(Node* first, int value)
{
    Node* p = first;
    int count = 0;

    while (p != NULL)
    {
        if (p->data == value)
        {
            count++;
        }

        p = p->next;
    }

    cout << value << " occurs " << count << " times.";
}

int main()
{
    Node* first = NULL;

    insert(first, 10);
    insert(first, 20);
    insert(first, 10);
    insert(first, 30);
    insert(first, 10);
    insert(first, 40);

    cout << "Linked List: ";
    display(first);

    cout << "\n";

    findOccurrences(first, 10);

    return 0;
}