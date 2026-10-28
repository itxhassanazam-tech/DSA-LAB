
#include <iostream>
using namespace std;

class myCarStack
{
private:
	int cars[8];
	int count;

public:
	// Constructor
	myCarStack()
	{
		count = 0;
	}

	// Check empty
	bool isEmpty()
	{
		return count == 0;
	}

	// Check full
	bool isFull()
	{
		return count == 8;
	}

	// Push car
	void push(int car)
	{
		if (isFull())
			cout << "Parking is full!" << endl;
		else
		{
			cars[count] = car;
			count++;
			cout << "Car parked successfully!" << endl;
		}
	}

	// Pop car
	int pop()
	{
		if (isEmpty())
			return -1;

		count--;
		return cars[count];
	}

	// Show top car
	int top()
	{
		if (isEmpty())
			return -1;

		return cars[count - 1];
	}

	// Total cars
	int totalCars()
	{
		return count;
	}

	// Search car
	bool search(int car)
	{
		for (int i = 0; i < count; i++)
		{
			if (cars[i] == car)
				return true;
		}

		return false;
	}

	// Display cars
	void display()
	{
		if (isEmpty())
		{
			cout << "Parking is empty!" << endl;
			return;
		}

		cout << "Cars parked (top to bottom):" << endl;

		for (int i = count - 1; i >= 0; i--)
			cout << cars[i] << endl;
	}

	// Remove a specific car
	void removeCar(int car)
	{
		if (!search(car))
		{
			cout << "Car not found!" << endl;
			return;
		}

		myCarStack temp;

		while (top() != car)
		{
			temp.push(pop());
		}

		pop();

		while (!temp.isEmpty())
		{
			push(temp.pop());
		}

		cout << "Car removed successfully!" << endl;
	}
};

int main()
{
	myCarStack parking;

	int choice, car;

	do
	{
		cout << "\n===== PARKING LOT MENU =====";
		cout << "\n1. Park a new car";
		cout << "\n2. Remove a car";
		cout << "\n3. Display parked cars";
		cout << "\n4. Total cars parked";
		cout << "\n5. Search for a car";
		cout << "\n6. Show top car";
		cout << "\n7. Exit";

		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter car number: ";
			cin >> car;
			parking.push(car);
			break;

		case 2:
			cout << "Enter car number to remove: ";
			cin >> car;
			parking.removeCar(car);
			break;

		case 3:
			parking.display();
			break;

		case 4:
			cout << "Total cars parked: "
				<< parking.totalCars() << endl;
			break;

		case 5:
			cout << "Enter car number to search: ";
			cin >> car;

			if (parking.search(car))
				cout << "Car is present in parking." << endl;
			else
				cout << "Car is not present." << endl;
			break;

		case 6:
			if (parking.isEmpty())
				cout << "Parking is empty!" << endl;
			else
				cout << "Top car: " << parking.top() << endl;
			break;

		case 7:
			cout << "Program ended." << endl;
			break;

		default:
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 7);

	return 0;
}
