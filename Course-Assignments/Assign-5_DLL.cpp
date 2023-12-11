
// 1. Define a class DLL to implement singly linked list data structure with member variable start pointer of type node.
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
    node *prev;
    int item;
    node *next;
};

class DLL
{
private:
    node *start;

public:
    DLL();
    ~DLL();
    void deleteFirst();
    void insertAtFirst(int);
    void insertAtLast(int);
    node *search(int);
    void insertDataAfter(node *, int);
    void deleteLast();
    void deleteNode(int);
};

DLL::DLL()
{
    start = NULL;
}
void DLL::deleteFirst()
{
    if (start != NULL)
    {
        node *temp = start;
        start = temp->next;
        if (start != NULL)
            start->prev = NULL; // Check if the list has more than one node
        delete temp;
        // You can also do in similar way to deleting the last node.
    }
}
DLL::~DLL()
{
    while (start != NULL)
    {
        deleteFirst();
    }
}
void DLL::insertAtFirst(int element)
{

    node *temp = new node;
    temp->item = element;
    temp->next = start;
    temp->prev = NULL;
    if (start != NULL)
    {
        start->prev = temp;
    }
    start = temp;
}
void DLL::insertAtLast(int element)
{
    node *n = new node;
    n->item = element;
    n->next = NULL;
    node *temp = start;
    if (start != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        n->prev = temp;
        // Finally our node is ready to be inserted(i.e set element, next and prev)
        temp->next = n;
        // Finally connected our node to the list
    }
    else
    {
        start = n;
        n->prev = NULL;
    }
}
node *DLL::search(int element)
{
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->item == element)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void DLL::insertDataAfter(node *t, int element)
{
    if (t == NULL)
    {
        cout << "Node not found" << endl;
    }
    else
    {
        node *n = new node;
        n->item = element;
        n->prev = t;
        n->next = t->next;
        // Completed building the node
        // Now need to link other nodes.
        t->next = n;
        t->next->prev = n;
    }
}
void DLL::deleteLast()
{
    if (start != NULL)
    // checking if the list is empty
    {
        if (start->next == NULL)
        {
            // Only one item in the List
            delete start;
            start = NULL;
        }
        else
        {
            node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }
}

void DLL::deleteNode(int element)
{
    node *t = start;
    if (start != NULL)
    {
        while (t != NULL)
        {
            if (t->item == element)
            {
                if (t->next != NULL)
                    t->next->prev = t->prev;

                if (t->prev != NULL)
                    t->prev->next = t->next;
                if (t->prev == NULL)
                    start = t->next;
                delete t;

                break;
            }
            t = t->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}