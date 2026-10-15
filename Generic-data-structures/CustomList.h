#include "MyList.h"

using namespace std;

// ================= TASK 3: CUSTOMLIST CLASS =================

template <class Type>
class CustomList : public MyList<Type>
{
private:
    // Check whether a number is prime
    bool isPrime(Type number)
    {
        if (number < 2)
            return false;

        for (Type j = 2; j <= number / j; j++)
        {
            if (number % j == 0)
                return false;
        }

        return true;
    }

    // Reverse a section of the array
    void reversePart(int start, int end)
    {
        while (start < end)
        {
            Type temp = this->arr[start];
            this->arr[start] = this->arr[end];
            this->arr[end] = temp;

            start++;
            end--;
        }
    }

    // Rotate one section clockwise (right)
    void rotateRight(int start, int length, int r)
    {
        if (length <= 1)
            return;

        r = r % length;

        if (r < 0)
            r += length;

        if (r == 0)
            return;

        reversePart(start, start + length - 1);
        reversePart(start, start + r - 1);
        reversePart(start + r, start + length - 1);
    }

    // Rotate one section anticlockwise (left)
    void rotateLeft(int start, int length, int r)
    {
        if (length <= 1)
            return;

        r = r % length;

        if (r < 0)
            r += length;

        if (r == 0)
            return;

        reversePart(start, start + r - 1);
        reversePart(start + r, start + length - 1);
        reversePart(start, start + length - 1);
    }

public:
    // Parameterized constructor with default argument
    CustomList(int size = 10) : MyList<Type>(size) {}

    // Copy constructor
    CustomList(const CustomList<Type>& other)
        : MyList<Type>(other) {}

    // Sum of all prime numbers
    Type sum_ofPrime()
    {
        Type sum = Type{};

        for (int i = 0; i < this->currentSize; i++)
        {
            if (isPrime(this->arr[i]))
                sum += this->arr[i];
        }

        return sum;
    }

    // Second maximum distinct even number
    Type secondMaxEven()
    {
        Type maximum = Type{};
        Type second = Type{};
        bool foundMax = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type value = this->arr[i];

            if (value % 2 == 0)
            {
                if (!foundMax || value > maximum)
                {
                    if (foundMax)
                    {
                        second = maximum;
                        foundSecond = true;
                    }

                    maximum = value;
                    foundMax = true;
                }
                else if (value != maximum &&
                    (!foundSecond || value > second))
                {
                    second = value;
                    foundSecond = true;
                }
            }
        }

        if (!foundSecond)
        {
            cout << "Second maximum even number does not exist.\n";
            return Type{};
        }

        return second;
    }

    // Second minimum distinct odd number
    Type secondMinOdd()
    {
        Type minimum = Type{};
        Type second = Type{};
        bool foundMin = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type value = this->arr[i];

            if (value % 2 != 0)
            {
                if (!foundMin || value < minimum)
                {
                    if (foundMin)
                    {
                        second = minimum;
                        foundSecond = true;
                    }

                    minimum = value;
                    foundMin = true;
                }
                else if (value != minimum &&
                    (!foundSecond || value < second))
                {
                    second = value;
                    foundSecond = true;
                }
            }
        }

        if (!foundSecond)
        {
            cout << "Second minimum odd number does not exist.\n";
            return Type{};
        }

        return second;
    }

    // Print each duplicated value once
    void printDuplicates()
    {
        bool duplicateFound = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            bool appearedBefore = false;

            for (int k = 0; k < i; k++)
            {
                if (this->arr[k] == this->arr[i])
                {
                    appearedBefore = true;
                    break;
                }
            }

            if (appearedBefore)
                continue;

            for (int j = i + 1; j < this->currentSize; j++)
            {
                if (this->arr[i] == this->arr[j])
                {
                    cout << this->arr[i] << " ";
                    duplicateFound = true;
                    break;
                }
            }
        }

        if (!duplicateFound)
            cout << "No duplicates found.";

        cout << endl;
    }

    // Divide into two halves and rotate both clockwise
    void rotateClockwaise(int r)
    {
        if (this->currentSize == 0)
            return;

        int firstHalf = (this->currentSize + 1) / 2;
        int secondHalf = this->currentSize - firstHalf;

        rotateRight(0, firstHalf, r);
        rotateRight(firstHalf, secondHalf, r);
    }

    // Divide into two halves and rotate both anticlockwise
    void rotateanitclockwaise(int rt)
    {
        if (this->currentSize == 0)
            return;

        int firstHalf = (this->currentSize + 1) / 2;
        int secondHalf = this->currentSize - firstHalf;

        rotateLeft(0, firstHalf, rt);
        rotateLeft(firstHalf, secondHalf, rt);
    }

    // Destructor
    ~CustomList() override {}
};

#endif // CUSTOMLIST_H
