#include <iostream>
#include <climits>
#include "LinkedList.hpp"

using namespace std;

class Queue
{
private:
    SLL queue;
    int front, rear;
public:
    Queue();
    void enqueue(int data);
    int dequeue();
};

Queue::Queue()
{
    front

}

void Queue::enqueue(int data)
{
    queue.insertEnd(data);
}

int main()
{

    return 0;
}