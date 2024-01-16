// Perform enqueue and dequeue operations in Circular Queue

#include <iostream>
using namespace std;

template <class T>
class CircularQueue
{
    private:
        int front, rear, size;
        int capacity;
        T *arr;
    public:
        CircularQueue(int);
        bool isFull();
        bool isEmpty();
        void enqueue(T);
        T dequeue();
};

template <class T>
CircularQueue<T>::CircularQueue(int size)
{
    capacity = size;
    arr = new T[size];
    front = rear = -1;
}

template <class T>
bool CircularQueue<T>::isFull()
{
    return front == (rear + 1) % capacity;
}

template <class T>
bool CircularQueue<T>::isEmpty()
{
    return front == -1;
}

template <class T>
void CircularQueue<T>::enqueue(T data)
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
        arr[rear] = data;
        rear = (rear + 1) % capacity; //Modulo increment remember group theory
    }
}

template <class T>
T CircularQueue<T>::dequeue()
{
    if(front == -1){
        cout<<"Underflow"<<endl;
        return -1;
    }
    else{
        T item = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % capacity;
        }
        cout<<"Item deleted."<<endl;
        return item;
    }
}

int main(){
    int n;
    cout<<"Enter size of queue:";
    cin>>n;
    CircularQueue<int> cq(n);

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
            cq.enqueue(data);
            break;

        case 2:
            cout << cq.dequeue()<<endl;
            break;
        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}