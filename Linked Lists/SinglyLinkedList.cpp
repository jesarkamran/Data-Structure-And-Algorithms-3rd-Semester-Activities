#include <iostream>
#include <string>
using namespace std;
struct  Student
{
	string id;
	int marks;
	Student *next= NULL;
};
Student *first= NULL, *last =NULL;
Student *curr;
void opt();
void display()
{
	Student *p = first;
	if (first == NULL)
	{
		cout<<"No Data to Display\n";
	}
	else
	{
		cout<<"\n";
		while(p != NULL)
		{
			cout<<"Student Id: "<<p->id<<"\n";
			cout<<"Marks: "<<p->marks<<"\n";
			p = p->next;
			cout<<"\n";
		}
	}
}
void insert_end()
{
	curr = new Student;
	cout<<"Enter ID no: ";
	cin>>curr->id;

	cout<<"Enter marks: ";
	cin>>curr->marks;
	cout<<"\n";
	
	if(first==NULL)
	{
		first=last=curr;
	}
	else
	{
		last->next = curr;
		last = curr;
	}

}
void insert_start()
{
	curr = new Student;
	cout<<"Enter ID no: ";
	cin>>curr->id;

	cout<<"Enter marks: ";
	cin>>curr->marks;
	cout<<"\n";
	
	if(first==NULL)
	{
		first=last=curr;
	}
	else
	{
		curr->next = first;
		first = curr;
	}

}
void deletion_end()
{
	
	Student *p = first;
	while(p != NULL)
	{
		if (p->next == NULL)
		{
			delete last;
			last = p;
			last->next = NULL;
			break;
		}
		p = p->next;
	}
}
void deletion_start()
{
	curr = first->next;
	delete first;
	first = curr;
}
void reverse_display()
{
	Student *p = first, *k;
	while(first != k)
	{

		if (p->next == NULL)
		{
			cout<<"Student Name is: "<<p->id;
			k = p; p = first;
		}
		if (p->next == k)
		{
			cout<<"Student Name is: "<<p->id;
			k = p; p = first;
		}
		else{
			p = first->next;
		}
	}

}
// void deleteNodes(int val, char criteria)
// {
// 	Student *p = first;
// 	while (p!=NULL)
// 	{
// 		if (p->marks == val)
// 		{
// 			if (p->next != NULL)
// 			{
// 				p = p->next;
// 			}
// 			else
// 			{
// 				p = NULL;
// 			}	
// 		}
// 		else if (p->marks < val && criteria == 'L')
// 		{
// 			p = 
// 		}
// 	}
// }
void minimumfinder()
{
	Student *p = first, *q = first;
	while (p!=NULL)
	{
		if (q->marks > p->marks)
		{
			q = p;
		}
		p = p->next;
	}
	cout<<"\nMinimum value: "<<q->marks<<"\n";
}
void opt()
{
	cout<<"\nEnter 1 to Display Data\n";
	cout<<"Enter 2 to Insert at End\n";
	cout<<"Enter 3 to Insert at Start\n";
	cout<<"Enter 4 to Delete at End\n";
	cout<<"Enter 5 to Delete at Start\n";
	cout<<"Enter 6 to Delete after specfic value\n";
	cout<<"Enter 7 to Delete before specfic value\n";
	cout<<"Enter 8 to Delete specfic value\n";
	cout<<"Enter 0 to Quit\n";
	cout<<"\nEnter task no: to Perform: ";
	int option;
	cin>>option;

	switch(option)
	{
		case 1:
			cout<<"\nDisplay of Data Method\n";
			display(); opt(); break;

		case 2:
			cout<<"\nInsertion at End Method\n";
			insert_end(); opt(); break;

		case 3:
			cout<<"\nInsertion at Start Method\n";
			insert_start(); opt(); break;

		case 4:
			cout<<"\nDeletion at End Method\n";
			deletion_end(); opt(); break;

		case 5:
			cout<<"\nDeletion at Start Method\n\n";
			deletion_start(); opt(); break;

		case 6:
			cout<<"\nDeletion after Specfic Method\n";
			insert_start(); opt(); break;

		case 7:
			cout<<"\nDeletion before Specfic Method\n";
			insert_start(); opt(); break;

		case 8:
			cout<<"\nDeletion of Specfic Method\n";
			insert_start(); opt(); break;
		case 9:
			cout<<"\nReverse Display\n";
			reverse_display(); opt(); break;

		case 10:
			cout<<"\nMinimum value node finder\n";
			minimumfinder(); opt(); break;
		
		case 0:
			cout<<"\nProcess Terminated Successfully\n";
			

		default:
			cout<<"\nInvalid Entry Try Again!!\n";
			opt(); break;
	}
}

int main()
{
	opt();
	return 0;
}
