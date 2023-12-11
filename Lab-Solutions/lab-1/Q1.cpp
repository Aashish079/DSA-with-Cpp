// Write an algorithm and program code for the following:
// 1. Perform push and pop operations in stack

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
    Stack(int size)
    {
        capacity = size;
        arr = new T[size];
        top = -1;
    }
    void push(int);
    T pop();
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

int main()
{
    Stack<int> s1(5);

    while (1)
    {
        cout<<"**** MENU ****"<<endl;
        cout << "1-> Push" << endl;
        cout << "2-> Pop " << endl;
        cout << "3->Exit" << endl;
        int choice;
        fflush(stdin);
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the value to be Pushed: " << endl;
            cin >> data;
            s1.push(data);
            break;

        case 2:
            cout << s1.pop()<<endl;
            break;
        case 3:
            exit(1);
            break;
        }
    }

    return 1;
}