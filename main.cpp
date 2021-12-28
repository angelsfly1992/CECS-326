#include <iostream>
#include <string>
#include <numeric>
using namespace std;

struct Acess {
	char array[20];
}s;

int main()
{
	Acess **st;
	st = new Acess *[20];
	for (int i = 1; i <= 20; i++)
	{
		st[i] = new Acess;
	}
	int choice;
	cout << "enter the element in upper case:";
	for (int i = 1; i <= 20; i++)
	{
		cin >> st[i]->array[i];
	}
	bool On = true;
	while (On != false)
	{
		cout << "*******************************\n";
		cout << " 1 - Display 10 random char's.\n";
		cout << " 2 - Delete the character and deallocate the memory.\n";
		cout << " 3 - Exit program.\n";
		cout << " Enter your choice and press return: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Display the character\n";
			for (int i = 1; i <= 20; i++)
			{
				cout << st[i]->array[i] << "\n";
			}
			break;
		case 2:
			cout << "Delete the character and deallocate the memory\n";
			char position;
			cout << "enter the element to delete and deallocate its space:";
			cin >> position;
			for (int i = 1; i <= 20; i++)
			{
				if (st[i]->array[i] == position)
				{
					delete st[i];
					cout << "deleted!!!!!";
				}
			}
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}
}
