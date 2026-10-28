
#include <iostream>
using namespace std;

class myStack
{
private:
	char arr[100];
	int count;

public:
	// Constructor
	myStack()
	{
		count = 0;
	}

	// Push
	void push(char ch)
	{
		if (count == 100)
		{
			cout << "Stack is full!" << endl;
			return;
		}

		arr[count] = ch;
		count++;
	}

	// Pop
	char pop()
	{
		if (count == 0)
			return '\0';

		count--;
		return arr[count];
	}

	// Check Empty
	bool isEmpty()
	{
		return count == 0;
	}

	// Clear Stack
	void clear()
	{
		count = 0;
	}
};

int main()
{
	myStack undoStack;
	myStack redoStack;

	char text[100];
	int length = 0;
	int choice;
	char ch;

	text[0] = '\0';

	do
	{
		cout << "\n===== TEXT EDITOR =====";
		cout << "\n1. Type character";
		cout << "\n2. Delete character";
		cout << "\n3. Undo";
		cout << "\n4. Redo";
		cout << "\n5. Display text";
		cout << "\n6. Exit";

		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (length == 99)
			{
				cout << "Text is full!" << endl;
				break;
			}

			cout << "Enter character: ";
			cin >> ch;

			undoStack.push('T');
			undoStack.push(ch);

			redoStack.clear();

			text[length] = ch;
			length++;
			text[length] = '\0';

			cout << "Character added." << endl;
			break;

		case 2:
			if (length == 0)
			{
				cout << "Text is empty!" << endl;
				break;
			}

			ch = text[length - 1];

			undoStack.push('D');
			undoStack.push(ch);

			redoStack.clear();

			length--;
			text[length] = '\0';

			cout << "Character deleted." << endl;
			break;

		case 3:
			if (undoStack.isEmpty())
			{
				cout << "Nothing to undo!" << endl;
				break;
			}

			ch = undoStack.pop();

			if (undoStack.isEmpty())
			{
				cout << "Nothing to undo!" << endl;
				break;
			}

			if (ch == 'T')
			{
				ch = undoStack.pop();

				length--;
				text[length] = '\0';

				redoStack.push('T');
				redoStack.push(ch);
			}
			else
			{
				ch = undoStack.pop();

				text[length] = ch;
				length++;
				text[length] = '\0';

				redoStack.push('D');
				redoStack.push(ch);
			}

			cout << "Undo successful." << endl;
			break;

		case 4:
			if (redoStack.isEmpty())
			{
				cout << "Nothing to redo!" << endl;
				break;
			}

			ch = redoStack.pop();

			if (ch == 'T')
			{
				ch = redoStack.pop();

				text[length] = ch;
				length++;
				text[length] = '\0';

				undoStack.push('T');
				undoStack.push(ch);
			}
			else
			{
				ch = redoStack.pop();

				length--;
				text[length] = '\0';

				undoStack.push('D');
				undoStack.push(ch);
			}

			cout << "Redo successful." << endl;
			break;

		case 5:
			cout << "Current text: " << text << endl;
			break;

		case 6:
			cout << "Program ended." << endl;
			break;

		default:
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 6);

	return 0;
}
