//SP21-BC2-033: KAMRAN JESAR
#include <iostream>
#include <string>
using namespace std;
struct Student
{
	string name[8] = {"null", "Kamran", "Deepak", "Hemant", "Sartaj", "Faiz", "Imran", "null"};
	int rollN[8] = {1,2,3,4,5,6,7,8,};
	int marks[8] = {0,80,70,60,65,80,85,0};
};
Student st[8];
int firstIndex = 1, lastIndex = 6;
void options();
bool checkSpace();
void display();
void insertion_At_End();
void insertion_At_Start();
void deletion_At_End();
void deletion_At_Start();
void deletion_Before_Specfic();
void deletion_After_Specfic();
void deletion_Of_Specfic();
void left_Shift(int a, int b);

int main()
{
	options();
}
void options()
{
	cout<<"\nEnter 1 to Display Data ";
	cout<<"\nEnter 2 to insert at end ";
	cout<<"\nEnter 3 to insert at start ";
	cout<<"\nEnter 4 to delete at End ";
	cout<<"\nEnter 5 to delete at start ";
	cout<<"\nEnter 6 to delete after specfic ";
	cout<<"\nEnter 7 to delete before specfic ";
	cout<<"\nEnter 8 to delete specfic ";
	cout<<"\nEnter 0 to quit \n";
	
	cout<<"\n";
	cout<<"Enter task number to perform: ";
	int task; cin>>task; cout<<"\n";
	switch(task)
	{
		case 0:	
			cout<<("Process Successfully Finished\n");
			break;
		case 1:	
			cout<<"\nDisplay of Data: \n";
			display(); options(); break;
		case 2:
			cout<<"Insertion At End Method\n";
			insertion_At_End(); options(); break;
		case 3:
			cout<<"Insertion At Start Method\n";	
			insertion_At_Start(); options(); break;
		case 4:
			cout<<"Deletion At End Method\n";
			deletion_At_End(); options(); break;
		case 5:
			cout<<"Deletion At Start Method\n";
			deletion_At_Start(); options(); break;
		case 6:
			cout<<"Deletion After a Specfic value Method\n";
			deletion_After_Specfic(); options(); break;
		case 7:
			cout<<"Deletion before a Specfic value Method\n";
			deletion_Before_Specfic(); options(); break;
		case 8:
			cout<<"Deletion of Specfic value Method\n";
			deletion_Of_Specfic(); options(); break;
		default:
			cout<<"Invalid Entry\n";
			cout<<"Try Again!!!";options(); break;
	}
}
void display()																	//Task #01
{
	for(int i =firstIndex; i<=lastIndex;i++)
	{
		cout<<"Name: "<<st[i].name[i]<<endl;
		cout<<"Roll No: "<<st[i].rollN[i]<<endl;
		cout<<"Marks: "<<st[i].marks[i];
		cout<<"\n\n";
	}
}
bool checkSpace()																//Checks Space in array 
{
	if (firstIndex == -1)
	{
		firstIndex = lastIndex = 0;
		cout<<"Array is Empty:\n";
	}
	else if((firstIndex == 0)&&(lastIndex == 7))
	{
		cout<<"Array is full!!";
		return false;
	}
	else
	{
		cout<<"Array is semifull: ";
		return true;
	}
	return true;
}
void insertion_At_End()															//Task #02
{
	if (checkSpace() == true)
	{
		lastIndex = lastIndex+1;
		cout<<"Enter the name of student: ";
		cin>>st[lastIndex].name[lastIndex];
		
		cout<<"Enter the roll number: ";
		cin>>st[lastIndex].rollN[lastIndex];
		
		cout<<"Enter the marks of student: ";
		cin>>st[lastIndex].marks[lastIndex];

		cout<<"\nDisplaying data after insertion at End\n";
		display();
	}
}

void insertion_At_Start()														//Task #03
{
	if (checkSpace() == true)
	{
		firstIndex = firstIndex-1;
		
		cout<<"Enter the name of student: ";
		cin>>st[firstIndex].name[firstIndex];
		
		cout<<"Enter the roll number: ";
		cin>>st[firstIndex].rollN[firstIndex];
		
		cout<<"Enter the marks of student: ";
		cin>>st[firstIndex].marks[firstIndex];

		cout<<"\nDisplaying data after insertion at Start\n";
		display();
	}
}
void deletion_At_End()															//Task #04
{
	if (firstIndex != -1)
	{
		lastIndex--;
		cout<<"\nDisplaying data after deletion at End\n";
		display();
	}
}
void deletion_At_Start()
{
	//Task #05
	if (firstIndex != -1)
	{
		firstIndex++;
		cout<<"\nDisplaying data after deletion at Start\n";
		display();
	}
}
void deletion_After_Specfic() 													//Task #06
{
	if (firstIndex != -1)
	{
		cout<<"\nEnter specfic Student name to delete record after it: ";
		string nam; cin>>nam;
		cout<<"\nDisplaying data after deletion before specfic value\n";
		for (int i = firstIndex; i < lastIndex; i++)
		{
			if (nam == st[i].name[i])
			{
				left_Shift(i+2, lastIndex); break;
				
			}
		}
	}
}

void left_Shift(int a, int b)													//Method for Left shifting
{
	int j=0;
	for (int i = a; i <= b; i++)
	{
		 j = i-1;
		st[j].name[j] = st[i].name[i];
		st[j].rollN[j] = st[i].rollN[i];
		st[j].marks[j] = st[i].marks[i];
		
	}
	lastIndex--; display();
}
void deletion_Before_Specfic()													//Task #07
{
	if (firstIndex != -1)
	{
		cout<<"\nEnter specfic Student name to delete record before it: ";
		string nam; cin>>nam;
		cout<<"\nDisplaying data after deletion before specfic value\n";
		for (int i = firstIndex; i < lastIndex; i++)
		{
			if (nam == st[i].name[i])
			{
				left_Shift(i, lastIndex); break;
				
			}
		}
	}
}

void deletion_Of_Specfic()														//Task #08
{	
	if (firstIndex != -1)
	{
		cout<<"\nEnter specfic Student name to delete it: ";
		string nam; cin>>nam;
		cout<<"\nDisplaying data after deletion before specfic value\n";
		for (int i = firstIndex; i < lastIndex; i++)
		{
			if (nam == st[i].name[i])
			{
				left_Shift(i+1, lastIndex); break;
				
			}
		}
	}
}
