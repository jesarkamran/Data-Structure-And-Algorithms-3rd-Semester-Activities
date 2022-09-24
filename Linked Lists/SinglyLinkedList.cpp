#include <iostream>
#include <string>
using namespace std;
struct Student
{
	string name;
	Student *next = NULL;
};
Student *first=NULL, *last=NULL, *curr;
void display(Student *p)
{
	if (p != NULL)
	{
		cout<<p->name<<" ";
		display(p->next);
	}
}
void insert_At_Start()
{
	curr = new Student;	
	cout<<"Enter student Name: ";
	cin>>curr->name;
	if (first == NULL)
	{
		first = last = curr;
	}
	else
	{
		curr->next = first;
		first = curr;
	}
	cout<<"\nInsertion At Start Last's next value: "<<last->next<<"\n";
}
void insert_At_End()
{
	curr = new Student;	
	cout<<"Enter student Name: ";
	cin>>curr->name;
	if (first == NULL)
	{
		first = last = curr;
	}
	else
	{
		last->next = curr;
		last = curr;
	}
	cout<<"\nInsertion At End Last's next value: "<<last->next<<"\n";
}

int main()
{
	for (int i = 0; i < 5; i++)
	{

		cout<<"\nEnter 1 to Insert at Start\n\nEnter 2 to Insert at end: ";
		int choice; cin>>choice;cout<<"\n";
		
		
		if (choice == 2)
		{
			insert_At_End();
		}
		if (choice == 1)
		{
			insert_At_Start();
		}
	}
	display(first);
	return 0;
}
