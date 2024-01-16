// Perform operations in Deque( Double ended queue) for:
// a. Add at beginning
// b. Add at end
// c. Delete from beginning
// d. Delete from end
#include <iostream>
using namespace std;

template <class T>
class Deque
{

private:
    int front, rear, size;
    int capacity;
    T *arr;

public:
    Deque(int);
    bool isFull();
    bool isEmpty();
    void enqueueFront(T);
    void enqueueRear(T);
    T dequeueFront();
    T dequeueRear();
};
template <class T>
Deque<T>::Deque(int size)
{
    capacity = size;
    arr = new T[size];
    front = rear = -1;
}
template <class T>
bool Deque<T>::isFull()
{
    return ((rear + 1) % capacity == front);
}
template <class T>
bool Deque<T>::isEmpty()
{
     return (front == -1);
}

template <class T>
void Deque<T>::enqueueRear(T data)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
    }
}
template <class T>
void Deque<T>::enqueueFront(T data)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        front = (front - 1 + capacity) % capacity; // Modulo decrement remember group theory, +capacity is added to avoid negative values
        arr[front] = data;
        cout<<"Enqued data: "<<data<<endl;
    }
}
template <class T>
T Deque<T>::dequeueFront()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }
    else
    {
        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return value;
    }
}
template <class T>
T Deque<T>::dequeueRear()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }
    else
    {
        int value = arr[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + capacity) % capacity; // to aoivd negative values
        }
        return value;
    }
}

int main()
{
    Deque<int> dq(5);
    dq.enqueueFront(1);
    dq.enqueueFront(2);
    dq.enqueueFront(3);
    dq.enqueueFront(4);
    dq.enqueueFront(5);
    dq.enqueueFront(6);
    cout << dq.dequeueFront() << endl;
    cout << dq.dequeueFront() << endl;
    cout << dq.dequeueFront() << endl;

    return 0;
}