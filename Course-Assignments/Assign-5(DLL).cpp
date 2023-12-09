
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
        delete temp;
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
    if (start != NULL)
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
    else
    {
        start = new node;
        start->item = element;
        start->next = NULL;
        start->prev = NULL;
    }
}
void DLL::insertAtLast(int element)
{
    node *n = new node;
    n->item = element;
    n->next = NULL;
    node *temp = start;
    if(start !=NULL){
        while(temp->next !=NULL){
         temp = temp->next;
         temp->next = n;   
        }
        n->prev = temp;
    }
}
