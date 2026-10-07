 
#include <iostream>
#include <string>
using namespace std;

 
template <typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
 
template <typename T, int N>
void printArray(T(&arr)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

 
template <typename T, int N>
void selectionSort(T(&A)[N])
{
    for (int i = 0; i < N - 1; i++)
    {
        int smallSub = i;                  

        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[smallSub])       
            {
                smallSub = j;
            }
        }

        swapValues(A[i], A[smallSub]);     
    }
}

int main() {
    
    int intArray[5] = { 64, 25, 12, 22, 11 };
    cout << "Original integer array: ";

    printArray(intArray);
    selectionSort(intArray);

    cout << "Sorted integer array: ";
    printArray(intArray);

    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    cout << "\nOriginal string array: ";

    printArray(stringArray);
    selectionSort(stringArray);

    cout << "Sorted string array: ";
    printArray(stringArray);

    return 0;
}