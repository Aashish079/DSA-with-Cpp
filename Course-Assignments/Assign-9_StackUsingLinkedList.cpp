// 1. Define a class Stack with node type pointer top as member variable. Implement
// stack using linked list.

// 2. In question 1, define a constructor to initialise member variable.

// 3. In question 1, define a method to push a new element on to the Stack.

// 4. In question 1, define a method to peek top element of the stack.

// 5. In question 1, define a method to pop the top element of the stack.

// 6. In question 1, define a destructor to deallocates the memory.
// 7. Define a method to reverse a stack.

// 8. Define a method to check whether a given number is a palindrome or not using stack.

// 9. Define a method to convert infix to postfix expression.

// 10. Define a method to evaluate postfix expression.

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Stack
{
private:
    node *top;

public:
Stack();
void push(int);
};

Stack::Stack(){
    top = NULL;
}
void Stack::push(int data){
    node* n = new node;
    n->data = data;
    n->next = top;

    
}
