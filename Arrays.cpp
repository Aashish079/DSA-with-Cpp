// Assignment-1: Array Data Structure
// 1. Define a class Array to implement array data structure with member variables to store capacity of array, last index of the last filled block of the array and a pointer to hold the address of the first block of the dynamically created array.

// 2. In question 1, define a parameterised constructor to create an array of specified size.
// 3.
// In the question 1, add a method to check whether an array is empty or not by returning True or False.

// 4. In question 1, define a method to append a new element in the array

// 5. In question 1, define a method to insert a new element at specified index

// 6. In question 1, define a method to edit an element at specified index.

// 7. In question 1, define a method to delete an element at specified index.

// 8. In question 1, define a method to check if the array is full by returning true or false.

// 9. In question 1, define a method to get element at specified index.

// 10. In question 1, define a method to count number of elements present in the array.

// 11. In question 1, define a destructor to deallocate the memory of array.

// 12. In question 1, define a method to find an element in the array. Return index if the
// element found, otherwise return -1.

#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *arr;

public:
    Array(int capacity)
    {
        this->capacity = capacity;
        this->lastIndex = -1;
        this->arr = new int[capacity];
    }
    ~Array()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (lastIndex == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void append(int element)
    {
        if (lastIndex == capacity - 1)
        {
            cout << "Arrray is Full";
        }
        else
        {
            lastIndex++;
            arr[lastIndex] = element;
        }
    }

    void insert(int element, int index)
    {
        if (lastIndex == capacity - 1)
        {
            cout << "Arrray is Full";
        }
        else
        {
            // Shift Array Elements
            for (int i = lastIndex; i >= index; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[index] = element;
        }
    }

    void edit(int element, int index)
    {
        if (index > lastIndex || index < 0)
        {
            cout << "Index Out of Bound";
        }
        else
        {
            arr[index] = element;
        }
    }
    void del(int index)
    {
        if (index > lastIndex || index < 0)
        {
            cout << "Index Out of Bound";
        }
        else
        {
            for (int i = index; i < lastIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            lastIndex--;
        }
    }
    bool isFull()
    {
        if (lastIndex == capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getElement(int index)
    {
        return arr[index];
    }
    int countElements()
    {
        return lastIndex + 1;
    }
    int findElement(int element)
    {
        //Linear Search
        for (int i = 0; i<= lastIndex; i++)
        {
            if(arr[i] == element)
            { 
                return i;
            }
            return -1;
        } 
    }
    
};