// 1.
// Define a class CLL to implement Circular linked list data structure with member variable last pointer of type node.
// 2.
// In question 1, define a constructor to initialise last pointer with NULL.
// 3.
// In question 1, define a method to insert a data into the list at the beginning.
// 4.
// In question 1, define a method to insert a data into the list at the end
// 5.
// In question 1, define a method to search a node with the give item.
// 6.
// In question 1, define a method to insert a data into the list after the specified node of the list.
// 7.
// In question 1, define a method to delete first node from the list.
// 8
// In question 1, define a method to delete last node of the list.
// 9.
// In question 1, define a method to delete a specific node.

// 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list…

#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class CLL
{
private:
    node *last;

public:
    CLL();
    ~CLL();
    void insertFirst(int);
    void insertLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(node *);
};
CLL::CLL()
{
    last = NULL;
}
CLL::~CLL()
{
}
void CLL::insertFirst(int data)
{
    node *n = new node;
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
    }
    else
    {
        last = n;
        last->next = last;
    }
}
void CLL::insertLast(int data)
{
    node *n = new node;
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    else
    {
        last = n;
        last->next = last;
    }
}
node *CLL::search(int data)
{
    node *t;
    if (last != NULL)
    {
        t = last->next;

        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != last->next);
    }
    return NULL;
}
void CLL::insertAfter(node *t, int data)
{
    node *n = new node;
    n->item = data;
    if (t != NULL)
    {
        n->next = t->next;
        t->next = n;
        if (t == last)
            last = n;
    }
}
void CLL::deleteFirst()
{
    node *t;
    if (last != NULL)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            t = last->next;
            last->next = t->next;
            delete t;
        }
    }
}
void CLL::deleteLast()
{
    node *t;
    if (last != NULL)
    {
        if(last->next == last){
            delete last;
            last = NULL;
        }
        else
        {
            t = last->next; // Setting the pointer to the first node
            while (t->next != last)
            {
                t = t->next;
            }
            t->next = last->next;
            delete last;
            last = t;
        }
    }
}
void CLL::deleteNode(node *t)
{
    
}
