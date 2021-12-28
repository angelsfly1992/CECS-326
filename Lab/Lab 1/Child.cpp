#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
 
typedef struct {
	char** pointer;
	int *array;
}Node;
 
//create the array
void initialiseArray(int array[])
{
	array[0] = 2700;
	for (int i = 0; i<19; i++)
	{
		array[i + 1] = 2 * array[i];
	}
}
 
//
void initialiseCharsAtPointer(Node *node, int i) {
	srand(time(0));
	//cout<<"size: "<<node->array[i]<<endl;
	for (int j = 0; j<node->array[i]; j++)
	{
		//random uppercase letter
		char letter = (char)((rand() % 26) + 65);//0-25 random character
		node->pointer[i][j] = letter;
	}
}
 
void initialise(Node *node)
{
	node->array = (int*)malloc(20 * sizeof(int));
	initialiseArray(node->array);
	node->pointer = (char **)malloc(20 * sizeof(char*));
	for (int i = 0; i<20; i++)
	{
		node->pointer[i] = (char*)malloc(node->array[i] * sizeof(char));
		initialiseCharsAtPointer(node, i);
	}
}
 
//print the node
void print(Node *node)
{
	cout << node->pointer[0][1] << endl;
}
 
//print deallicated node  list
void listDeallocated(Node *node)
{
	cout << endl << "The deallocated memory indices are: ";
	for (int i = 0; i<20; i++)
	{
		if (node->pointer[i] == NULL)
			cout << i << " ";
	}
	cout << endl;
}
 
//deallocate all memory of pointers
void deallocateAll(Node *node)
{
	//for all pointers
	for (int i = 0; i<20; i++)
	{
		free(node->pointer[i]);//free pointer memory
		node->pointer[i] = NULL; //make it null
	}
}
 
//print first 10 chars
void printChars(Node *node, int index)
{
	//pointer at index is null
	if (node->pointer[index] == NULL)
	{
		cout << "The memory index is not allocated any memory." << endl;
		cout << "allocating new memory..." << endl;
		node->pointer[index] = (char*)malloc((node->array[index]) * sizeof(char));
		cout << "Initialising characters..." << endl;
		initialiseCharsAtPointer(node, index);
	}
	cout << endl;//new line
				 //print first 10 characters
	for (int i = 0; i<10; i++)
	{
		cout << node->pointer[index][i];
	}
	cout << endl;//new line
}
 
//delete all characters at particluar index
void deleteAllChars(Node *node, int index)
{
	//free memory
	free(node->pointer[index]);
	//allocate new memory
	node->pointer[index] = (char*)malloc(node->array[index] * sizeof(char));
}
 
 
 
//completely delete the node before exit
void deallocateNode(Node *node)
{
	free(node->array);//free array memory
	for (int i = 0; i<20; i++)
		free(node->pointer[i]);//free all pointers
	free(node->pointer);//free char pointer memory
	delete node;//free node memory
}
 
int main()
{
	Node *node = new Node();//create a new node
	initialise(node);//initialise the node
					 // print(node);
	
	int choice = 0;
	int index = 0;
	int choice1 = 0;
 
 
 
	do {
		switch (choice)
		{
		case 1:cout << "Enter the index to manipulate." << endl;
			cin >> index;
			//print the sub menu of access a pointer
			cout << "1. Print the first 10 characters in the chosen array." << endl;
			cout << "2. Delete all the characters associated with this pointer." << endl;
			cout << "3. Return to main menu." << endl;
			cin >> choice1;
			switch (choice1)
			{
 
			case 1:printChars(node, index);
				break;
			case 2:deleteAllChars(node, index);
				break;
			case 3: break; 
			};
			break;
 
		case 2:listDeallocated(node);
			break;
 
		case 3:deallocateAll(node);
			break;
 
		}
		//print the main menu
		cout << "\n\n1. Access a pointer." << endl;
		cout << "2. List deallocated memory (index)." << endl;
		cout << "3. Deallocate all memory." << endl;
		cout << "4. Exit program." << endl;
		cin >> choice;
 
	} while (choice != 4);
	//deallocate all memory
	deallocateNode(node);
	cin.get();
 
 
}
 
 
 
}
























