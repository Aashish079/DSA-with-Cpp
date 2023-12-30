// 1. Define a class Stack with capacity, top and ptr pointer as member variables.
// Implement stack using array.
// 2. In question 1, define a parameterzied constructor to initialise member variables.
// 3. In question 1, define a method to push a new element on to the Stack.
// 4. In question 1, define a method to peek top element of the stack.
// 5. In question 1, define a method to pop the top element of the stack.
// 6. In question 1, define a destructor to deallocates the memory.
// 7. In question 1, define a method to check stack overflow
// 8. In question 1, define a method to check stack underflow.
// 9. Define a method to reverse a stack.
// 10. Define a solution to keep track of minimum value element in the stack.

#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    Stack(int);
    Stack(Stack &s); // Copy Constructor for deep copy
    ~Stack();
    void push(int);
    int peek();
    int pop();
    bool isFull();
    bool isEmpty();
    void reverse();
    int getSize();
    Stack &operator=(Stack &); // Copy Assignment Operator for deep copy
};

Stack::Stack(int cap)
{
    if (cap <= 0)
        cap = -cap;
    if (cap == 0)
        cap = 4; // Making the program more robust

    capacity = cap;
    top = -1;
    ptr = new int[capacity];
}
Stack::Stack(Stack &s)
{
    capacity = s.capacity;
    top = s.top;
    ptr = new int[capacity];
    for (int i = 0; i <= top; i++)
        ptr[i] = s.ptr[i];
}
bool Stack::isFull()
{
    return top == capacity - 1;
}
bool Stack::isEmpty()
{
    return top == -1;
}
void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return; // to exit function early
    }
    ptr[++top] = data;
}
int Stack::peek()
{
    try
    {
        if (isEmpty())
            throw "Stack Underflow";
        return ptr[top];
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        return -1;
    }
}
int Stack::pop()
{
    try
    {
        if (isEmpty())
            throw "Stack Underflow";
        return ptr[top--];
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        return -1;
    }
}

Stack::~Stack()
{
    delete[] ptr;
}

void Stack::reverse()
{
    int t;
    for (int i = 0; i < (top + 1) / 2; i++)
    {
        t = ptr[i];
        ptr[i] = ptr[top - i];
        ptr[top - i] = t;
    }
}
int Stack::getSize()
{
    return top + 1;
}
Stack &Stack::operator=(Stack &s)
{                   // Understand better at 30:21
    if (this != &s) // To avoid self assignment: code breaks at ptr = new int[capacity]; if same object is passed

    {
        capacity = s.capacity;
        top = s.top;
        if (ptr != NULL)
            delete[] ptr;
        ptr = new int[capacity];
        for (int i = 0; i <= top; i++)
            ptr[i] = s.ptr[i];
    }
    return *this;
}
// Non-Member implementation
void reverseStack(Stack &s)
{
    Stack *tempStack = new Stack(s.getSize());

    while (!s.isEmpty())
    {
        tempStack->push(s.pop());
    }
    s = *tempStack;
}

void minValueTracking()
{
    Stack s1(5);
    Stack min(5);
    int x;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter element a number: ";
        cin >> x;
        s1.push(x);
        if (min.isEmpty())
            min.push(x);
        else
        {
            if (x < min.peek())
                min.push(x);
            else
                min.push(min.peek());
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "\n Minimum value in stack is: " << min.peek();
        s1.pop();
        min.pop();
    }
}
int main()
{
    minValueTracking();
    cout<<endl;
    return 0;
}