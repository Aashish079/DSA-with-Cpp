// 1. Define a class SLL to implement singly linked list data structure with member variable start pointer of type node.
// 2. In question 1, define a constructor to initialise start pointer with NULL.

// 3. In question 1, define a method to insert a data into the list at the beginning.

// 4. In question 1, define a method to insert a data into the list at the end

// 5. In question 1, define a method to search a node with the give item.

// 6. In question 1, define a method to insert a data into the list after the specified node of the list.

// 3: In queston 1, define a mend to dete fast node ome helist.

// 9. In question 1, define a method to delete a specific node.

// 10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.

#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};
class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~SLL();
};

SLL::SLL()
{
    start = NULL;
}
void SLL::insertAtStart(int data)
{
    node *temp = new node;
    temp->item = data;
    temp->next = start;
    start = temp;
}
void SLL::insertAtEnd(int data)
{
    node *n, *p;
    n = new node;
    n->item = data;
    n->next = NULL;

    if (start == NULL)
        start = n;
    else
    {
        p = start;
        while (p->next != NULL)
            p = p->next;
        p->next = n; // Updating the next of node pointed by p
    }
}

node *SLL::search(int data)
{
    node *p;
    p = start;
    while (p != NULL)
    {
        if (p->item == data)
            return p;
        p = p->next;
    }
    return NULL;
}
void SLL::insertAfter(node *p, int data)
{
    if (p == NULL) // Checking if the node is valid or not. When programmer uses search method, it may return NULL if the node is not found.
        cout << "Invalid node" << endl;
    else
    {
        node *n = new node;
        n->item = data;
        n->next = p->next;
        p->next = n;
    }
}
void SLL::deleteFirst()
{
    if (start)
    {
        node *temp = start; // Created a temporary pointer to store the address of the first node and then delete it.
        start = temp->next; // or start = start->next;
        delete temp;
    }
}
void SLL::deleteLast()
{
    if (start)
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        // approach with two pointer variables
        // else
        // {
        //     node *temp1, *temp2;
        //     temp2 = start;
        //     temp1 = start->next;

        //     while (temp1->next != NULL)
        //     {
        //         temp2 = temp1;
        //         temp1 = temp1->next;
        //     }
        //     temp2->next = NULL;
        //     delete temp1;
        // }
        // approach with single pointer variable
        else
        {
            node *temp = start;
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}
// Some thing is error in this code! Fix it and also look at the efficient method done by sir.
void SLL::deleteNode(int data)
{
    if (start)
    {
        if (start->item == data)
        {
            node *temp = start;
            start = temp->next;
            delete temp;
        }
        else
        {
            node *temp1, *temp2;
            temp2 = start;
            temp1 = start->next;

            while (temp1->next != NULL)
            {
                if (temp1->item == data)
                {
                    temp2->next = temp1->next;
                    delete temp1;
                    break;
                }
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
    }
}
SLL::~SLL()
{
    while (start!=NULL)
    {
        deleteFirst();
    }
}
//Create Copy Constructor and Copy assignment operator.