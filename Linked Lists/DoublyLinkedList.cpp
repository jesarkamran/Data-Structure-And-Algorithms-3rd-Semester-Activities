/*
DOUBLY LINKED LIST Program by KAMRAN JESAR
SP21-BCS-033
*/
#include <iostream>
using namespace std;
struct Student
{
    int id;
    float marks;
    Student *prev = NULL;
    Student *next = NULL;
};
Student *first = NULL;
Student *last = NULL;
void insert_End()
{
    Student *curr = new Student;
    
    cout<<"\nEnter Student ID: ";
    cin>>curr->id;

    cout<<"Enter Student Marks: ";
    cin>>curr->marks;

    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr; curr->prev = last;
        last = curr;
    }
}
void insert_Start()
{
    Student *curr = new Student;
    
    cout<<"\nEnter Student ID: ";
    cin>>curr->id;

    cout<<"Enter Student Marks: ";
    cin>>curr->marks;

    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        first->prev = curr; curr->next = first;
        first = curr;
    }
}
void insert_Before_Specific()
{
    cout<<"Enter Specific id to insert before it: ";
    int key; cin>>key;
    Student *curr = new Student;
    
    cout<<"\nEnter Student ID: ";
    cin>>curr->id;

    cout<<"Enter Student Marks: ";
    cin>>curr->marks;

    Student *k; k = first;

    while ((k->id != key)&(k->next != NULL))
    {
        k = k->next;
    }
    if (k->id == key)
    {
        curr->prev = k->prev; curr->next = k;
        k->prev->next = curr; k->prev = curr;
    
    }
    else
    {
        cout<<"\nNot Found\n";
    }    
}
void insert_After_Specific()
{
    cout<<"Enter Specific id to insert After it: ";
    int key; cin>>key;
    Student *curr = new Student;
    
    cout<<"\nEnter Student ID: ";
    cin>>curr->id;

    cout<<"Enter Student Marks: ";
    cin>>curr->marks;

    Student *k; k = first;

    while ((k->id != key)&(k->next != NULL))
    {
        k = k->next;
    }
    if (k->id == key)
    {
        curr->prev = k; curr->next = k->next;
        k->next->prev = curr; k->next = curr;
    }
    else
    {
        cout<<"\nNot Found\n";
    }
    
}
void deletion_Start()
{
    if (first == NULL)
    {
        cout<<"\nNo Data to Delete\n";
    }
    else
    {
        Student *p = first;
        first = first->next;
        first->prev = NULL;
        delete p;
    }
    
    
}
void deletion_End()
{
    if (first == NULL)
    {
        cout<<"\nNo Data to Delete\n";
    }
    else if (first == last)
    {
        deletion_Start();
    } 
    else
    {
      
        Student *p = last;
        last = last->prev;
        last->next = NULL;
        delete p;
    }
}
void deletion_Before_Specific()
{
    cout<<"Enter id to delete data before it : ";
    int key; cin>>key;

    if (first == NULL)
    {
        cout<<"\nNo Data to Delete\n";
    }
    else if (first->id == key)
    {
        cout<<"There is nothing to delete before it";
    }
    else if (first->next->id == key)
    {
        deletion_Start();
    }
    
    else
    {
        Student *p = first;
        while ((p!=NULL)&(p->id!=key))
        {
            p = p->next;
        }

        if (p->id == key)
        {
            Student *curr = p->prev;
            p->prev = curr->prev; p->prev->next = p;
            delete curr;
        }
        else
        {
            cout<<"\nData not found\n";
        }
    }
    
}
void deletion_After_Specific()
{
    cout<<"Enter id to delete data before it : ";
    int key; cin>>key;

    if (first == NULL)
    {
        cout<<"\nNo Data to Delete\n";
    }
    else if (last->id == key)
    {
        cout<<"There is nothing to delete After it";
    }
    else if (last->prev->id == key)
    {
        deletion_End();
    }
    else
    {
        Student *p = first;
        while ((p!=NULL)&(p->id!=key))
        {
            p = p->next;
        }

        if (p->id == key)
        {
            Student *curr = p->next;
            p->next = curr->next; curr->prev = p;
            delete curr;
        }
        else
        {
            cout<<"\nData not found\n";
        }
    }
}
void deletion_Specfic()
{
    cout<<"Enter id to delete: ";
    int key; cin>>key;

    if (first == NULL)
    {
        cout<<"\nNo Data to Delete\n";
    }
    else if (first->id == key)
    {
        deletion_Start();
    }
    else if (last->id == key)
    {
        deletion_End();
    }
    else
    {
        Student *p = first;
        while ((p!=NULL)&(p->id!= key))
        {
            p = p->next;
        }
        if (p->id == key)
        {
            p->next->prev = p->prev; p->prev->next = p->next;
            delete p;
        }
        else
        {
            cout<<"\nData not found\n";
        }
        
    }
    
    
    
}
void display()
{
    Student *k = first;
    while (k != NULL)
    {
        cout<<"\nStudent ID: "<<k->id<<"\n";
        cout<<"Student MARKS: "<<k->marks<<"\n";
        k = k->next;
    }
    
}

void reverse_Display()
{
    Student *k = last;
    while (k != NULL)
    {
        cout<<"\nStudent ID: "<<k->id<<"\n";
        cout<<"Student MARKS: "<<k->marks<<"\n";
        k = k->prev;
    }
}
void opt()
{
    cout << "\nEnter 1 to insert at Start\n";
    cout << "Enter 2 to insert at End\n";
    cout << "Enter 3 to insert before a Specific\n";
    cout << "Enter 4 to insert after a Specific\n";
    cout << "Enter 5 to delete at Start\n";
    cout << "Enter 6 to delete at End\n";
    cout << "Enter 7 to delete before a Specific\n";
    cout << "Enter 8 to delete after a Specific\n";
    cout << "Enter 9 to delete a Specfic\n";
    cout << "Enter 10 to Display data in Linked List\n";
    cout << "Enter 11 to Reverse Display of data in Linked List\n";
    cout << "Enter 0 to Quit\n";

    cout << "\nEnter your choice from Above: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nINSERTION AT START METHOD\n";
        insert_Start(); opt(); break;

    case 2:
        cout << "\nINSERTION AT END METHOD\n";
        insert_End(); opt(); break;

    case 3:
        cout << "\nINSERTION BEFORE SPECIFIC METHOD\n";
        insert_Before_Specific(); opt(); break;

    case 4:
        cout << "\nINSERTION AFTER SPECIFIC METHOD\n";
        insert_After_Specific(); opt(); break;

    case 5:
        cout << "\nDELETION AT START METHOD\n";
        deletion_Start(); opt(); break;

    case 6:
        cout << "\nDELETION AT END METHOD\n";
        deletion_End(); opt(); break;

    case 7:
        cout << "\nDELETION BEFORE SPECIFIC METHOD\n";
        deletion_Before_Specific(); opt(); break;

    case 8:
        cout << "\nDELETION AFTER SPECIFIC METHOD\n";
        deletion_After_Specific(); opt(); break;

    case 9:
        cout << "\nDELETION OF SPECIFIC METHOD\n";
        deletion_Specfic(); opt(); break;

    case 10:
        cout << "\nDISPLAY METHOD\n";
        display(); opt(); break;

    case 11:
        cout << "\nREVERSE DISPLAY METHOD\n";
        reverse_Display(); opt(); break;

    default:
        cout << "\nPROCESS TERMINATED SUCCESSFULLY\n";
        break;
    }
}

int main()
{
    opt();
    return 0;
}
