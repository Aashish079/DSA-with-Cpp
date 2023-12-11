// 2. Convert :
// a. Infix expression to postfix expression
// b. Infix expression to prefix expression
// 3. Evaluate the postfix expression
// 4. Check the paired parenthesis in mathematical expression
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
    bool isOperator(char);
    string infixToPostfix(string &);
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
        return -1;
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
bool Stack<T>::isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(')
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
string Stack<T>::infixToPostfix(string &infix)
{
    Stack<char> s1(20);
    string postfix;

    
}

int main()
{
    Stack<char> s1(50);
    string infix, postfix;
    cout << "Enter Infix expression" << endl;
    cin >> infix;

    postfix = infixToPostfix(infix);

    cout << "Postfix Expression:" << postfix;

    return 1;
}
