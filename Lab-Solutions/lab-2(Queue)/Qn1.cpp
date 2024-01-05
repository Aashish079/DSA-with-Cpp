// Perform enqueue and dequeue operations in Linear Queue
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int front, rear, size;
    int capacity;
    T *arr;

public:
    Queue(int);
    void enqueue(T);
    T dequeue();
};

template <class T>
Queue<T>::Queue(int size)
{
    capacity = size;
    arr = new T[size];
    front = rear = -1;
}
template <class T>
void Queue<T>::enqueue(T data)
{
    if (rear == capacity - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        arr[++rear] = data;
    }
}

template <class T>
T Queue<T>::dequeue(){
    if (front == rear)
    {
        cout << "Underflow" << endl;
        return -1;
    }
    else
    {
        return arr[++front];
    }
}

int main(){
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    Queue<int> q(n);

    while (1)
    {
        cout<<"**** MENU ****"<<endl;
        cout << "1-> Enqueue" << endl;
        cout << "2-> Dequeue " << endl;
        cout << "3-> Exit" << endl;
        int choice;
        fflush(stdin);
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the value to be Enqueued: " << endl;
            cin >> data;
            q.enqueue(data);
            break;

        case 2:
            cout << q.dequeue()<<endl;
            break;
        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}