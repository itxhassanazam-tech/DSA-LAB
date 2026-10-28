#include <iostream>
using namespace std;

// Abstract Class
template <typename T>
class AbstractStack
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractStack() {}
};

// Child Class
template <typename T>
class myStack : public AbstractStack<T>
{
private:
	T* arr;
	T* minArr;
	int maxSize;
	int count;
	int minCount;

public:
	// Default Constructor
	myStack()
	{
		maxSize = 5;
		count = 0;
		minCount = 0;

		arr = new T[maxSize];
		minArr = new T[maxSize];
	}

	// Parameterized Constructor
	myStack(int size)
	{
		maxSize = size;
		count = 0;
		minCount = 0;

		arr = new T[maxSize];
		minArr = new T[maxSize];
	}

	// Push
	void push(T value)
	{
		if (isFull())
		{
			cout << "Stack is full!" << endl;
			return;
		}

		arr[count] = value;
		count++;

		if (minCount == 0 || value <= minArr[minCount - 1])
		{
			minArr[minCount] = value;
			minCount++;
		}

		cout << "Element pushed." << endl;
	}

	// Pop
	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return T();
		}

		T value = arr[count - 1];
		count--;

		if (value == minArr[minCount - 1])
		{
			minCount--;
		}

		return value;
	}

	// Top
	T top() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return T();
		}

		return arr[count - 1];
	}

	// Check Empty
	bool isEmpty() const
	{
		return count == 0;
	}

	// Check Full
	bool isFull() const
	{
		return count == maxSize;
	}

	// Get Minimum
	T getMin() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return T();
		}

		return minArr[minCount - 1];
	}

	// Display
	void display() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return;
		}

		cout << "Stack elements (top to bottom):" << endl;

		for (int i = count - 1; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}

	// Destructor
	~myStack()
	{
		delete[] arr;
		delete[] minArr;
	}
};

// Main Function
int main()
{
	int size;

	cout << "Enter stack size: ";
	cin >> size;

	if (size <= 0)
	{
		cout << "Invalid stack size!" << endl;
		return 0;
	}

	myStack<int> s(size);

	int choice, value;

	do
	{
		cout << "\n1. Push element";
		cout << "\n2. Pop element";
		cout << "\n3. Show top element";
		cout << "\n4. Check if stack is empty";
		cout << "\n5. Check if stack is full";
		cout << "\n6. Display stack elements";
		cout << "\n7. Show minimum element";
		cout << "\n8. Exit";

		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter value: ";
			cin >> value;
			s.push(value);
			break;

		case 2:
			if (!s.isEmpty())
				cout << "Popped element: " << s.pop() << endl;
			else
				cout << "Stack is empty!" << endl;
			break;

		case 3:
			if (!s.isEmpty())
				cout << "Top element: " << s.top() << endl;
			else
				cout << "Stack is empty!" << endl;
			break;

		case 4:
			if (s.isEmpty())
				cout << "Stack is empty." << endl;
			else
				cout << "Stack is not empty." << endl;
			break;

		case 5:
			if (s.isFull())
				cout << "Stack is full." << endl;
			else
				cout << "Stack is not full." << endl;
			break;

		case 6:
			s.display();
			break;

		case 7:
			if (!s.isEmpty())
				cout << "Minimum element: " << s.getMin() << endl;
			else
				cout << "Stack is empty!" << endl;
			break;

		case 8:
			cout << "Program ended." << endl;
			break;

		default:
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 8);

	return 0;
}
