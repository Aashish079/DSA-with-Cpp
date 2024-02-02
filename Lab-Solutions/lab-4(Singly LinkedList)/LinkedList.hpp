#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

class SLL
{
private:
    node *start;

public:
    SLL();
    void insertBeg(int);
    void insertBefore(node *, int);
    void insertAfter(node *, int);
    void insertEnd(int);

    void deleteBeg();
    void deleteEnd();
    void deleteNode(int);

    node *search(int);
    void displayList();
};

SLL::SLL()
{
    start = NULL;
}

void SLL::insertBeg(int data)
{
    node *n = new node;
    n->data = data;
    n->next = start;
    start = n;
}

void SLL::insertBefore(node *p, int data)
{
    if (p == NULL) // Checking if the node is valid or not. When programmer uses search method, it may return NULL if the node is not found.
        cout << "Invalid node" << endl;
    else
    {
        node *n = new node;
        n->data = data;
        node *t;
        while (t->next != p)
        {
            t = t->next;
        }

        t->next = n;
        n->next = p;
    }
}

void SLL::insertAfter(node *p, int data)
{
    if (p == NULL) // Checking if the node is valid or not. When programmer uses search method, it may return NULL if the node is not found.
        cout << "Invalid node" << endl;
    else
    {
        node *n = new node;
        n->data = data;
        n->next = p->next;
        p->next = n;
    }
}
void SLL::insertEnd(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    if (start == NULL)
    {
        cout << "Invalid Node" << endl;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void SLL::deleteBeg()
{
    if (start == NULL)
    {
        cout << "No nodes to delete" << endl;
    }
    else
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}

void SLL::deleteEnd()
{
    if (start == NULL)
    {
        cout << "No nodes to delete" << endl;
    }
    else
    {
        node *temp1 = start;
        node *temp2 = start->next;

        while (temp2->next != NULL)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;

        delete temp2;
    }
}
void SLL::deleteNode(int data)
{

    if (start == NULL)
    {
        cout << "No nodes to delete" << endl;
    }
    else
    {
        node *temp1 = start;
        node *temp2 = start->next;

        while (temp1->data != data)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;

        delete temp2;
    }
}
node *SLL::search(int data)
{
    node *p;
    p = start;
    while (p != NULL)
    {
        if (p->data == data)
            return p;
        p = p->next;
    }
    return NULL;
}

void SLL::displayList()
{
    node *t;
    t = start;
    while (t != NULL)
    {
        cout << t->data << " " << endl;
        t = t->next;
    }
}
