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
    void insertAtLast(int);
    bool isEmpty();
    int peek();
    Stack &operator=(const Stack &s);
    int pop();
    ~Stack();
};

Stack::Stack()
{
    top = NULL;
}
void Stack::push(int data)
{
    node *n = new node;
    n->data = data;
    n->next = top;
    top = n;
}
void Stack::insertAtLast(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;

    node *t = top;
    if (t != NULL)
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }
    else{
        top = n;
    }
}

int Stack::peek()
{
    if (top == NULL)
        throw 1;

    return top->data;
}

int Stack::pop()
{
    int top_value = top->data;
    node *temp = top;
    top = top->next;

    delete temp;

    return top_value;
}

Stack::~Stack()
{
    while (top != NULL)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty()
{
    return top == NULL;
}

Stack &Stack::operator=(const Stack &s)
{

    if (this != &s)
    {
        if (top != NULL)
        {
            while (top != NULL)
            {
                pop();
            }
        }
        node *t;
        t = s.top;

        while (t != NULL)
        {
            this->insertAtLast(t->data);
            t = t->next;
        }
    }

    return *this;
}

void reverse(Stack &s)
{
    Stack tempStack;
    while (!s.isEmpty())
        tempStack.push(s.pop());

    s = tempStack;
}

bool isPalindrome(int x){
    int l=0, y, i;

    Stack s;
    y = x;
    while(y){
        y = y/10;
        l++;
    }
    for(i=1; i<=l/2;i++){
        s.push(x%10);
        x=x/10;
    }
    if(l%2)
        x=x/10;
    for(i=1; i<=l/2;i++){
        //52:00
        

    }

}