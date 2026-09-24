#include <iostream>
using namespace std;

struct SinglyNode
{
    int data;
    SinglyNode* next;
};

struct DoublyNode
{
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};

void insertSingly(SinglyNode*& first, int value)
{
    SinglyNode* p = new SinglyNode;

    p->data = value;
    p->next = NULL;

    if (first == NULL)
    {
        first = p;
    }
    else
    {
        SinglyNode* temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }
}

DoublyNode* convertToDoubly(SinglyNode* first)
{
    DoublyNode* newFirst = NULL;
    DoublyNode* last = NULL;

    SinglyNode* p = first;

    while (p != NULL)
    {
        DoublyNode* newNode = new DoublyNode;

        newNode->data = p->data;
        newNode->next = NULL;
        newNode->prev = last;

        if (newFirst == NULL)
        {
            newFirst = newNode;
        }
        else
        {
            last->next = newNode;
        }

        last = newNode;
        p = p->next;
    }

    return newFirst;
}

void display(DoublyNode* first)
{
    DoublyNode* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    SinglyNode* singlyFirst = NULL;

    insertSingly(singlyFirst, 10);
    insertSingly(singlyFirst, 20);
    insertSingly(singlyFirst, 30);
    insertSingly(singlyFirst, 40);

    DoublyNode* doublyFirst = convertToDoubly(singlyFirst);

    cout << "Converted Doubly Linked List: ";
    display(doublyFirst);

    return 0;
}