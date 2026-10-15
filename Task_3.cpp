#include <iostream>
#include "CustomList.h"

using namespace std;

// ================= MENU-BASED MAIN =================

int main()
{
    int capacity;

    cout << "Enter list capacity: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Capacity must be positive.\n";
        return 0;
    }

    CustomList<int> list(capacity);

    int choice, value, index, rotations;

    do
    {
        cout << "\n====== CUSTOM LIST MENU ======\n";
        cout << "1. Add element at first\n";
        cout << "2. Add element at last\n";
        cout << "3. Remove element from end\n";
        cout << "4. Remove element from start\n";
        cout << "5. Insert at index\n";
        cout << "6. Display list\n";
        cout << "7. Check empty\n";
        cout << "8. Check full\n";
        cout << "9. Current size\n";
        cout << "10. Get last element\n";
        cout << "11. Search element\n";
        cout << "12. Sum of prime numbers\n";
        cout << "13. Second maximum even number\n";
        cout << "14. Second minimum odd number\n";
        cout << "15. Print duplicates\n";
        cout << "16. Rotate clockwise\n";
        cout << "17. Rotate anticlockwise\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        case 3:
            if (!list.empty())
                cout << "Removed: "
                << list.removeElementFromEnd() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 4:
            list.removeElementFromStart();
            break;

        case 5:
            cout << "Enter index (0-based): ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Element inserted successfully.\n";
            else
                cout << "Invalid index or list is full.\n";
            break;

        case 6:
            list.display();
            break;

        case 7:
            cout << (list.empty() ? "List is empty.\n"
                : "List is not empty.\n");
            break;

        case 8:
            cout << (list.full() ? "List is full.\n"
                : "List is not full.\n");
            break;

        case 9:
            cout << "Current size: " << list.size() << endl;
            break;

        case 10:
            if (!list.empty())
                cout << "Last element: " << list.last() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 11:
            cout << "Enter value to search: ";
            cin >> value;

            cout << (list.search(value) ? "Element found.\n"
                : "Element not found.\n");
            break;

        case 12:
            cout << "Sum of prime numbers: "
                << list.sum_ofPrime() << endl;
            break;

        case 13:
            cout << "Second maximum even: "
                << list.secondMaxEven() << endl;
            break;

        case 14:
            cout << "Second minimum odd: "
                << list.secondMinOdd() << endl;
            break;

        case 15:
            cout << "Duplicate elements: ";
            list.printDuplicates();
            break;

        case 16:
            cout << "Enter rotation count: ";
            cin >> rotations;

            if (rotations < 0)
                cout << "Enter a non-negative count.\n";
            else
            {
                list.rotateClockwaise(rotations);
                list.display();
            }
            break;

        case 17:
            cout << "Enter rotation count: ";
            cin >> rotations;

            if (rotations < 0)
                cout << "Enter a non-negative count.\n";
            else
            {
                list.rotateanitclockwaise(rotations);
                list.display();
            }
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
