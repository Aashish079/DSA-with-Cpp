
// 1. Define a class Queue with capacity, front, rear and ptr pointer as member variables.
// Implement queue using array.

// 2. In question 1, define a parameterzied constructor to initialise member variables.

// 3. In question 1, define a method to insert a new element at the rear in the queue.

// 4. In question 1, define a method to view rear element of the queue.

// 5. In question 1, define a method to view front element of the queue.

// 6. In question 1, define a method to delete the front element of the queue.

// 7. In question 1, define a destructor to deallocates the memory.

// 8. In question 1, define a method to check queue overflow

// 9. In question 1, define a method to check queue underflow.

// 10. In question 1, Define a method to count number of elements present in the queue

#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear;
    int capacity;
    int *arr;

public:
    Queue(int);
    void enqueue(int);
    int viewRear();
    int viewFront();
    void dequeue();
    ~Queue();
    bool isOverflow();
    bool isUnderflow();
    int count();
};

Queue::Queue(int capacity)
{
    this->capacity = capacity;
    front = rear = -1;
    arr = new int[capacity];
}

bool isOverflow(){
    return 

}
bool isUnderflow(){

}

void Queue::enqueue(int data)
{

}
