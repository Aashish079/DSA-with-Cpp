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
    void insertFirst();
};
CLL::CLL()
{
    last = NULL;
}
CLL::~CLL()
{
}
void CLL::insertFirst(){
    
}