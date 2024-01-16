// Assignment-7: Circular Doubly Linked List
// 1. Define a class CDLL to implement Circular Doubly linked list data structure with nember variable start pointer of type node.
// 2. In question 1, define a constructor to initialise start pointer with NULL.
// 3. In question 1, define a method to insert a data into the list at the beginning.
// 4. In question 1, define a method to insert a data into the list at the end
// 5. In question 1, define a method to search a node with the give item.
// 6. In question 1, define a method to insert a data into the list after the specified node of the list.
// 7. In question 1, define a method to delete first node from the list.
// 8. In question 1, define a method to delete last node of the list.
// 9. In question 1, define a method to delete a specific node.
// 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class CDLL
{
private:
    node *start;

public:
    CDLL();
    void insertAtFirst(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~CDLL();
};

CDLL::CDLL()
{
    start = NULL;
}

void CDLL::insertAtFirst(int data)
{
    node *n = new node;
    n->data = data;

    if (start != NULL)
    {
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
    else
    {
        start = n;
        n->next = n;
        n->prev = n;
    }
}

void CDLL::insertAtLast(int data)
{
    node *n = new node;
    n->data = data;

    if (start != NULL)
    {
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
    else
    {
        start = n;
        n->next = n;
        n->prev = n;
    }
}

node *CDLL::search(int data)
{ // Code isn't entirely correct.
    node *t = start;

    if (start)
    {
        do
        {
            if (t->data == data)
            {
                return t;
            }
            t = t->next;
        } while (t != start);
    }
    return NULL;
}

void CDLL::insertAfter(node *ptr, int data)
{
    if (ptr)
    {
        node *n = new node;
        n->data = data;
        n->next = ptr->next;
        n->prev = ptr;
        ptr->next->prev = n;
        ptr->next = n;
    }
}

void CDLL::deleteFirst()
{
    if (start != NULL)
    {
        node *temp = start;
        if (start->next == start)
        {
            start = NULL;
        }
        else
        {
            start->prev->next = start->next;
            start->next->prev = start->prev;
            start = start->next;
        }
        delete temp;
    }
}

void CDLL::deleteLast()
{
    if (start != NULL)
    {

        node *t = start->prev;
        if (start->next = start)
        {
            start = NULL;
        }
        else
        {
            t->prev->next = start;
            start->prev = t->prev;
        }
        delete t;
    }
}

void CDLL::deleteNode(int data)
{
    node *t = search(data);
    if (t)
    {
        if (t == start)
        {
            deleteFirst();
        }
        else if (t == start->prev)
        {
            deleteLast();
        }
        else
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;
        }
    }
}

CDLL::~CDLL()
{
    while (start != NULL)
    {
        deleteFirst();
    }
}