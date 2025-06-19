#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

void displayMenu()
{
	cout << "\nArray Operations Menu \n";
	cout << "1. Creating Array\n";
	cout << "2. Insert Elements\n";
	cout << "3. Modify Element\n";
	cout << "4. Search Element\n";
	cout << "5. Delete Element\n";
	cout << "6. Display Element\n";
	cout << "7. Exit\n";
	cout << "Enter your choice: \n";
}

void createArray(int arr[], int &size)
{
	cout << "Enter size of array ( max " << MAX_SIZE << " )";
	cin >> size;
	
	if(size > MAX_SIZE || size <= 0)
	{
		cout << "Invalid Input\n";
		size = 0;
		
		return;
	}
	
	cout << "Enter " << size << " Elements : \n";
	
	for(int i = 0; i<size; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Array Creating Successfully!!!";
}

void insertElement(int arr[], int &size)
{
	if(size >= MAX_SIZE)
	{
		cout << "Array is Full \n";
		return;
	}
	
	int element, position;
	
	cout << "Enter the element to insert : ";
	cin >> element;
	
	cout << "Enter the position ( 0 - " << size << " )";
	cin >> position;
	
	if(position < 0 || position > size)
	{
		cout << "Invalid Position";
		return;
	}
	
	//inserting element at position
	
//	[2,4,6,8,10]
//	//elem = 7 // pos = 3
	
	for(int i = size; i > position; i--) // i = 4; i > 3; i--
	{
		arr[i] = arr[i-1]; 
		
	}
	
	arr[position] = element;
	//arr[2] = 7
	
	size++;
	//4 -> 5
	
	cout<<"Element inserted Successfully\n";
}

void modifyElement(int arr[], int &size)
{
	if(size == 0)
	{
		cout << "Array is Empty\n";
		return;
	}
	
	int position, newValue;
	
	cout << "Enter position to modify ( 0 - " << size - 1 << " ) : ";
	cin >> position;
	
	if(position < 0 || position >= size)
	{
		cout << "Invalid Position\n";
		return;
	}
	
	cout << "Enter the new value : ";
	cin >> newValue;
	
	arr[position] = newValue;
	
	cout << "Element Modified Successfully\n";
}

void searchElement(int arr[], int &size)
{
	if(size == 0)
	{
		cout << "Array is empty\n";
		return;
	}
	
	int element, found = 0;
	
	cout << "Enter the element to search : ";
	cin >> element;
	
	cout << "Element found at position : ";
	for(int i = 0; i<size; i++)
	{
		if(arr[i] == element)
		{
			cout << i << " ";
			found = 1;
			break;
		}
	}
	
	if(found == 0)
	{
		cout << "Element not found\n";
	}
	
	cout << endl;
}
void deleteElement(int arr[], int &size)
{
	if(size == 0)
	{
		cout << "Array is empty\n";
		return;
	}
	
	int position;
	
	cout<< "Enter position to delete ( 0 - " << size-1 << " )";
	cin >> position;
	
	if(position < 0 || position >= size)
	{
		cout << "Invalid position\n";
		return;
	}
	
	//Deletion
	for(int i = position; i < size; i++)
	{
		arr[i] = arr[i+1];
	}
	
	size--;	
	cout << "Element deleted Successfully\n";
}

void displayArray(int arr[], int &size)
{
	if(size == 0)
	{
		cout << "Array is empty\n";
		return;
	}
	
	cout << "Array Elements : ";
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	int arr[MAX_SIZE];
	
	int size = 0;
	
	int choice;
	
	do
	{
		displayMenu();
		
		cin >> choice;
		
		switch(choice)
		{
			case 1 : 
				createArray(arr,size);
				break;
				
			case 2 :
				insertElement(arr, size);
				break;
				
			case 3 : 
				modifyElement(arr, size);
				break;
				
			case 4 : 
				searchElement(arr, size);
				break;
				
			case 5 :
				deleteElement(arr, size);
				break;
				
			case 6 : 
				displayArray(arr, size);
				break;
				
			case 7 :
				cout << "Exit Program.. \n";
				break;
				
			default :
				cout << "Invalid Choice\n"; 
		}
	}while(choice != 7);
	
	return 0;
}