#include <iostream>
using namespace std;
int task1(int intArray[11], int lastIndex)
{
	cout<<"\nEnter a value to insert at end: ";
	cin>>intArray[lastIndex+1]; 
	lastIndex = lastIndex + 1;
	return lastIndex;
}
void task2(int intArray[11], int firstIndex, int lastIndex)
{
	cout<<"Display of Data: ";
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		cout<<intArray[i]<<",";
	}
	cout<<"\n";
}
int task3(int intArray[11], int firstIndex)
{
	cout<<"\nEnter a value to insert at start: ";
	cin>>intArray[firstIndex-1]; 
	firstIndex = firstIndex - 1;
	return firstIndex;
}

int task4(int intArray[11], int firstIndex)
{
	cout<<"\nDeletion from start\n";
	firstIndex = firstIndex + 1;
	return firstIndex;
}
int task5(int intArray[11], int lastIndex)
{
	cout<<"\nDeletion at End\n";
	lastIndex = lastIndex - 1;
	return lastIndex;
}
int task6(int intArray[11], int firstIndex, int lastIndex)
{
	cout<<"Enter Specfic value to delete value before it: ";
	int specfic;
	cin>>specfic;
	int index = 10;
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (intArray[i]==specfic)
		{
			index = i;
			intArray[i-1] = intArray[i];
			i++;
		}
		if (i>index)
		{
			intArray[i-1] = intArray[i];
		}
	}
	lastIndex = lastIndex -1;
	return lastIndex;
}

int task7(int intArray[11], int firstIndex, int lastIndex)
{
	cout<<"Enter Specfic value to delete value after it: ";
	int specfic;
	cin>>specfic;
	int index = 10;
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (intArray[i]==specfic)
		{
			intArray[i+1] = intArray[i+2];
			i++;
			index = i;			
		}
		if (i>index)
		{
			intArray[i] = intArray[i+1];
		}
	}
	lastIndex = lastIndex -1;
	return lastIndex;
}

int task8(int intArray[11], int firstIndex, int lastIndex)
{
	cout<<"Enter Specfic value to delete value before it: ";
	int specfic;
	cin>>specfic;
	int index = 10;
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (intArray[i]==specfic)
		{
			index = i;
			intArray[i] = intArray[i+1];
		}
		if (i>index)
		{
			intArray[i] = intArray[i+1];
		}
	}
	lastIndex = lastIndex -1;
	return lastIndex;
}

int main()
{
	//declaration and initialization of first and last Index values
	int firstIndex=0, lastIndex = 0;
	int intArray[11] = {1,2,3,4,5,6,7,8,9,10,11};
	int size = sizeof(intArray)/sizeof(intArray[0]);	
	firstIndex=1, lastIndex = size-2;

	

	//displaying array befor insertion
	task2(intArray, firstIndex, lastIndex);
	
	//#Task1: Insertion at End 
	cout<<"\nTASK 01: ";
	lastIndex = task1(intArray, lastIndex);
	
	//#Task2: Displaying Array after insertion at end
	cout<<"\nTASK 02: ";
	task2(intArray, firstIndex, lastIndex);
	

	
	//Task3: Insertion at Start
	cout<<"\nTASK 03: ";
	firstIndex = task3(intArray, firstIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);

	//Task4: Deletion from start
	cout<<"\nTASK 04: ";
	firstIndex = task4(intArray, firstIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);
	
	//Task5: Deletion from end
	cout<<"\nTASK 05: ";
	lastIndex = task5(intArray, lastIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);

	
	//Task6: Deletion before specfic
	cout<<"\nTASK 06: \n";
	lastIndex = task6(intArray, firstIndex,lastIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);

	//Task7: Deletion after specfic
	cout<<"\nTASK 07: ";
	lastIndex = task7(intArray, firstIndex,lastIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);

	//Task8: Deleting specfic
	cout<<"\nTASK 08: ";
	lastIndex = task8(intArray, firstIndex,lastIndex);
	
	//displaying array after insertion at Start
	task2(intArray, firstIndex, lastIndex);

}
