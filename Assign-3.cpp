#include <iostream>
using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *arr;

protected:
    void doubleArray();
    void halfArray();

public:
    DynArray(int);
    DynArray(DynArray &);
    DynArray &operator=(DynArray &);
    ~DynArray();
    int getCapacity();
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getElement(int);
    int countElements();
    int findElement(int);
};

DynArray::DynArray(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        this->lastIndex = -1;
        this->arr = new int[capacity];
    }
    else
    {
        this->arr = NULL;
    }
}

DynArray::DynArray(DynArray &a)
{
    capacity = a.capacity;
    lastIndex = a.lastIndex;
    arr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        arr[i] = a.arr[i];
}
DynArray &DynArray::operator=(DynArray &a)
{
    if (this != &a)
    {
        if (arr != NULL)
            delete[] arr;
        capacity = a.capacity;
        lastIndex = a.lastIndex;
        arr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++)
            arr[i] = a.arr[i];
    }

    return *this;
}

DynArray::~DynArray()
{
    delete[] arr;
}
void DynArray::doubleArray()
{
    int *temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++)
        temp[i] = arr[i];
    delete[] arr; // deleting the small array arr was pointing to.
    arr = temp;   // you shouldn't write delete temp b/c it will delete the array temp is pointing to.
    // No need to worry about temp because it will die as soon as the control goes out of scope.
    capacity = capacity * 2;
}
void DynArray::halfArray()
{
    if (lastIndex > capacity / 2)
    {
        cout << "Can't Half the Array.";
    }
    else
    {
        int *temp = new int[capacity / 2];
        for (int i = 0; i <= lastIndex; i++)
            temp[i] = arr[i];
        arr = temp;

        capacity = capacity / 2;
        delete[] temp;
    }
}
int DynArray::getCapacity()
{
    return capacity;
}

bool DynArray::isEmpty()
{
    return lastIndex == -1;
}
bool DynArray::isFull()
{
    return lastIndex == capacity - 1;
}
void DynArray::append(int element)
{
    if (isFull())
        doubleArray();
    arr[++lastIndex] = element;
}
void DynArray::insert(int element, int index)
{
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "Invalid Index";
    }
    else
    {
        if (isFull())
            doubleArray();
        for (int i = lastIndex; i >= index; i--)
            arr[i + 1] = arr[i];
        arr[index] = element;
        lastIndex++;
    }
}
void DynArray::edit(int element, int index)
{
    if (index > lastIndex || index < 0)
    {
        cout << "/n Invalid Index";
    }
    else
    {
        arr[index] = element;
    }
}
void DynArray::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "/n Invalid Index";
    }
    else
    {
        for (int i = index; i < lastIndex; i++)
        {
            arr[i] = arr[i + 1];
        }
        lastIndex--;
        while (capacity / 2 >= lastIndex + 1 && capacity > 1)
            halfArray();
    }
}

int DynArray::getElement(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "/n Invalid Index or empty array";
        throw new exception();
    }
    return arr[index];
}
int DynArray::countElements()
{
    return lastIndex + 1;
}
int DynArray::findElement(int element)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}