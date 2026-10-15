#include <iostream>
using namespace std;

// ================= TASK 1: ABSTRACT CLASS =================

template <class Type>
class List
{
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10)
    {
        maxSize = (size > 0) ? size : 10;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    // Copy constructor: deep copy
    List(const List<Type>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List()
    {
        delete[] arr;
    }
};

#endif // LIST_H
