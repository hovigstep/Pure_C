#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int Data;
	Node* Next;
	Node* Previous;
};

Node* Start;
void AddToFront();
void PrintListForward();
void AddToBack(int);
void PrintListBackward();
void DeleteFromFront();
void DeleteFromBack();
void AddToMiddleAfter();
void DeleteFromMiddleAfter();
void AddToMiddleBefore();
void DeleteFromMiddleBefore();
void PurgeList();
void SaveinSeq();
void LoadfromSeq();
void main()
{
	Start = 0;
	int Choice;
	int MaxChoices;
	char Username[10];

	// set up your Maximum Choice here 
	MaxChoices = 16;
	// It creates a menu with 10 items
	Choice = 0;
	printf("%s\n", "Please Enter your name?");
	scanf("%s", Username);
	while (Choice < MaxChoices)
	{

		printf("%s", "Welcome ");
		printf("%s\n\n", Username);
		printf("%s\n", "************** MAIN MENU ****************");
		printf("%s\n", "Please Enter one of the following Choices");
		printf("%s\n\n", "**********Linked List Processing **********");
		printf("%s\n\n", "1: Add a Node to the Front of the List");
		printf("%s\n\n", "2: Add a node to the back of the list ");
		printf("%s\n\n", "3: Add a node to the middle of the list after a specific node");
		printf("%s\n\n", "4: Add a node to the middle of the list before a specific node");
		printf("%s\n\n", "5: Delete a node from the front of the list");
		printf("%s\n\n", "6: Delete a node from the back of the list");
		printf("%s\n\n", "7: Delete a node from the middle of the list after a specific node");
		printf("%s\n\n", "8: Delete a node from the middle of the list before a specific node");
		printf("%s\n\n", "9: Print a list forward");
		printf("%s\n\n", "10: Print a list backward");
		printf("%s\n\n", "11: Save the list in a Sequantial file");
		printf("%s\n\n", "12: Load the list from a Sequantial file");
		printf("%s\n\n", "13: Save the list in a Random file");
		printf("%s\n\n", "14: Load the list from a Random file");
		printf("%s\n\n", "15: Purge The list (delete all nodes)");
		printf("%s\n\n\n\n", "16: Exit The Program");
		// Print Your choices here
		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			AddToFront();
			break;
		case 2:
			int MyData;
			printf("Please Enter This Node's data ");
			scanf("%d", &MyData);
			printf("\n");
			AddToBack(MyData);
			break;
		case 3:
			AddToMiddleAfter();
			break;
		case 4:
			AddToMiddleBefore();
			break;
		case 5:
			DeleteFromFront();
			break;
		case 6:
			DeleteFromBack();
			break;
		case 7:
			DeleteFromMiddleAfter();
			break;
		case 8:
			DeleteFromMiddleBefore();
			break;
		case 9:
			PrintListForward();
			break;
		case 10:
			PrintListBackward();
			break;
		case 11:
			// Save in Seq file
			SaveinSeq();
			break;
		case 12:
			//Purge the list first 
			PurgeList();
			LoadfromSeq();
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			PurgeList();
			break;
		case 16:
			return;
		}
	}



}
void AddToFront()
{
	Node * NewNode;
	if (Start == 0)
	{
		// Empty list 
		//NewNode = (Node *)malloc(sizeof(Node)); // This Just allocates memmory but new allocates it then calls the constructor.
		Node* NewNode = new Node();
		printf("Please Enter This Node's data ");
		scanf("%d",&NewNode->Data);
		printf("\n");
		NewNode->Next = 0;
		NewNode->Previous = 0;
		Start = NewNode;
		printf("The First Node added succesfully\n");
		PrintListForward();
	}
	else
	{
		// When list is not empty
		NewNode = (Node *)malloc(sizeof(Node));
		printf("Please Enter This Node's data ");
		scanf("%d", &NewNode->Data);
		printf("\n");
		// Fix pointers 
		NewNode->Previous = 0;
		NewNode->Next = Start;
		Start->Previous = NewNode;
		Start = NewNode;
		printf("Node added succesfully\n");
		PrintListForward();
	}

}
void PrintListForward()
{
	if (Start == 0)
	{
		printf("Empty List!\n");
		return;
	}
	Node * Current;
	Current = Start;

	while (Current != 0)
	{
		printf("%d", Current->Data);
		printf("->");
		Current = Current->Next;
	}
	printf("NULL\n");
}
void AddToBack(int NodeData)
{
	Node * NewNode;
	if (Start == 0)
	{
		// Empty list 
		NewNode = (Node *)malloc(sizeof(Node));
		NewNode->Data = NodeData;
		NewNode->Next = 0;
		NewNode->Previous = 0;
		Start = NewNode;
		printf("The First Node added succesfully\n");
		PrintListForward();
	}
	else
	{
		// When list is not empty
		//Traverse to the end 
		Node * Current;
		Current = Start;
		while (Current->Next != 0)
		{
			Current = Current->Next;
		}
		// At this point Current points to the last node
		// We have to create a new node 
		NewNode = (Node *)malloc(sizeof(Node));
		NewNode->Data = NodeData;
		// Fix pointers 
		NewNode->Next = 0;
		NewNode->Previous = Current;
		Current->Next = NewNode;
		printf("The Node added to the end succesfully\n");
		PrintListForward();
	}

}
void PrintListBackward()
{
	if (Start == 0)
	{
		printf("Empty List!\n");
		return;
	}
	//Traverse to the end 
	Node * Current;
	Current = Start;
	while (Current->Next != 0)
	{
		Current = Current->Next;
	}
	while (Current != 0)
	{
		printf("%d", Current->Data);
		printf("->");
		Current = Current->Previous;
	}
	printf("NULL\n");
}
void DeleteFromFront()
{
	if (Start == 0)
	{
		//List is empty, nothing to Delete
		printf("%s", "List is Empty, no node to delete");
		PrintListForward();
		return;
	}
	// list is not empty 
	Node * Current;
	Node * NextOfCurrent;
	Current = Start;
	NextOfCurrent = Current->Next;
	if (NextOfCurrent == 0)
	{
		Start = 0;
	}
	else
	{
		NextOfCurrent->Previous = 0;
		Start = NextOfCurrent;
	}
	free(Current);
	printf("Node deleted from the front succesfully\n");
	PrintListForward();
}
void DeleteFromBack()
{
	if (Start == 0)
	{
		//List is empty, nothing to Delete
		printf("%s", "List is Empty, no node to delete");
		PrintListForward();
		return;
	}
	// list is not empty 
	Node * Current;
	Node * NextOfCurrent;
	Current = Start;
	NextOfCurrent = Current->Next;
	if (NextOfCurrent == 0)
	{
		Start = 0;
		free(Current);
		PrintListForward();
		return;
	}
	// There is more than one node 
	// Traverse the list to the end 

	while (NextOfCurrent->Next  != 0)
	{
		Current = Current->Next;
		NextOfCurrent = Current->Next;
	}

	Current->Next = 0;
	free(NextOfCurrent);
	printf("Node deleted from the back succesfully\n");
	PrintListForward();
}
void AddToMiddleAfter()
{
	int DataToFind;
	Node * Current;
	Node * NextOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	NextOfCurrent = Current->Next;
	if (Start == 0)
	{
		printf("List is Empty, This option does not apply.\n");
		return;
	}
	printf("Please give me the data of a node that you want to put the new node after it");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		NextOfCurrent = Current->Next;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
// I have a match
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("Please Enter This Node's data ");
	scanf("%d", &NewNode->Data);
	printf("\n");
	if (NextOfCurrent == 0)
	{
		Current->Next = NewNode;
		NewNode->Previous = Current;
		NewNode->Next = 0;
		printf("The node is succesfully added after ");
		printf("%d\n", DataToFind);
		PrintListForward();
		return;
	}
	Current->Next = NewNode;
	NewNode->Previous = Current;
	NextOfCurrent->Previous = NewNode;
	NewNode->Next = NextOfCurrent;
	printf("The node is succesfully added after ");
	printf("%d\n", DataToFind);
	PrintListForward();
}
void DeleteFromMiddleAfter()
{
	int DataToFind;
	Node * Current;
	Node * NextOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	NextOfCurrent = Current->Next;
	if (Start == 0)
	{
		printf("List is Empty, This option does not apply.\n");
		return;
	}
	printf("Please give me the data of a node that you want to delete the new node after it");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		NextOfCurrent = Current->Next;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
// I found the node and current pointing at it 
	if (Current->Next == 0)
	{
		// Last node found 
		printf("The node I found is the last node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	if (NextOfCurrent->Next == 0)
	{
		Current->Next = 0;
		free(NextOfCurrent);
		PrintListForward();
		return;
	}
	Current->Next = NextOfCurrent->Next;
	NextOfCurrent->Previous = Current;
	free(NextOfCurrent);
	PrintListForward();
	return;

}
void AddToMiddleBefore()
{
	int DataToFind;
	Node * Current;
	Node * PreviousOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	PreviousOfCurrent = Current->Previous ;
	if (Start == 0)
	{
		printf("List is Empty, This option does not apply.\n");
		return;
	}
	printf("Please give me the data of a node that you want to put the new node before it");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		PreviousOfCurrent = Current->Previous;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	// I have a match
	Node * NewNode;
	NewNode = (Node *)malloc(sizeof(Node));
	printf("Please Enter This Node's data ");
	scanf("%d", &NewNode->Data);
	printf("\n");
	if (PreviousOfCurrent == 0)
	{
		printf("Node I found is the first Node, This option does not apply.\n");
		PrintListForward();
		return;
	}
	Current->Previous = NewNode;
	NewNode->Next = Current;
	PreviousOfCurrent->Next = NewNode;
	NewNode->Previous = PreviousOfCurrent;
	printf("The node is succesfully added before ");
	printf("%d\n", DataToFind);
	PrintListForward();
}
void DeleteFromMiddleBefore()
{
	int DataToFind;
	Node * Current;
	Node * PreviousOfCurrent;
	Current = Start;
	int IsFound;
	IsFound = 0; // I think there is no match 
	PreviousOfCurrent = Current->Previous;
	if (Start == 0)
	{
		printf("List is Empty, This option does not apply.\n");
		return;
	}
	printf("Please give me the data of a node that you want to delete the new node before it");
	scanf("%d", &DataToFind);
	printf("\n");
	while (Current != 0)
	{
		if (Current->Data == DataToFind)
		{
			// It's a match, I found the node with desired data
			IsFound = 1; // It means it is Matched
			break;
		}

		Current = Current->Next;
		if (Current == 0)
		{
			break;
		}
		PreviousOfCurrent = Current->Previous;
	}
	if (IsFound == 0)
	{
		// Did not find that Node 
		printf("Did not Find the node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	// I found the node and current pointing at it 
	if (PreviousOfCurrent->Previous == 0)
	{
		// First node found 
		printf("The node I found is the first node, this option does not apply.\n");
		PrintListForward();
		return;
	}
	if (PreviousOfCurrent->Previous == 0)
	{
		Current->Previous = 0;
		free(PreviousOfCurrent);
		PrintListForward();
		return;
	}
	Current->Previous = PreviousOfCurrent->Previous;
	PreviousOfCurrent->Previous ->Next = Current;
	PrintListForward();
	return;

}
void PurgeList()
{
	if (Start == NULL)
	{
		printf("Empty List cannot be purged\n");
		return;
	}
	Node * Current, * NextNode;
	Current = Start;
	NextNode = Current->Next;
	// Delete Every Single Node 
	while (Current->Next != NULL)
	{
		free (Current);
		Current = NextNode;
		NextNode = Current->Next;
	}
	Start = NULL;
	printf("List Purged Succesfully\n");
}
void SaveinSeq()
{
	Node * Current;
	if (Start == 0)
	{
		//Empty List
		printf("No data to save");
		return;
	}
	Current = Start; // go to the beginning of the list 
	// get reay for file processing 
	FILE *cfPtr;   /* cfPtr = clients.dat file pointer */
	if ((cfPtr = fopen("LinkedListSaved.dat", "w")) == NULL)
		printf("File could not be opened\n");
	else
	{
		// Read the list and write in file 
		while (Current != NULL)
		{
			fprintf(cfPtr, "%d\n",
				Current->Data);
			Current = Current->Next;
		}
		fclose(cfPtr);
		printf("Data in the list saved in seqential file succesfully\n");
	}

}
void LoadfromSeq()
{
	FILE *cfPtr;   /* cfPtr = clients.dat file pointer */
	int MyData;
	if ((cfPtr = fopen("LinkedListSaved.dat", "r")) == NULL)
		printf("File could not be opened\n");
	else
	{
		fscanf(cfPtr, "%d", &MyData);

		while (!feof(cfPtr)) {
			AddToBack(MyData);
			fscanf(cfPtr, "%d", &MyData);
		}

		fclose(cfPtr);
	}
	printf("Linked list is now Loaded with the Sequential File information\n");
}