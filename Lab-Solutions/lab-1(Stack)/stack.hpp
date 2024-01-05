#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size = 10)
    {
        capacity = size;
        arr = new T[size];
        top = -1;
    }
    void push(int);
    T pop();
    T peek();
    bool isFull();
    bool isEmpty();
};

template <class T>
void Stack<T>::push(int data)
{
    if (isFull())
    {
        cout << "Stack overflow." << endl;
    }
    else
    {
        arr[++top] = data;
    }
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
    }
    else
    {
        return arr[top--];
    }
}

template <class T>
bool Stack<T>::isFull()
{
    return top == capacity - 1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}
template <class T>
T Stack<T>::peek()
{
    if (top == -1){return '\0';}
    return arr[top];
}
