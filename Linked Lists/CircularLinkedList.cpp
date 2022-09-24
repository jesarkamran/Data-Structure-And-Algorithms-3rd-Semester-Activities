/* CIRCULAR LINKED LIST  QUESTION 1
SP21-BCS-033 KAMRAN JESAR
*/
#include <iostream>
using namespace std;
struct Student
{
    int id;
    float marks;
    Student *next = NULL;
};
Student *last = NULL;
void insert_Start()
{
    Student *curr = new Student;
    cout << "Enter Student id: ";
    cin >> curr->id;
    cout << "Enter Student marks: ";
    cin >> curr->marks;
    if (last == NULL)
    {
        
        last = curr; 
        //below statement will keep the list rotatable
        curr->next = last; //consider current as first node 
    }
    else
    {
        /*In circular List Last's next is first element
        that's why assigning the first node address to curr node
        after that changing the first node by assignin curr node
        address to last->next
        */
        curr->next = last->next;
        last->next = curr;
    }
}
void insert_End()
{
    Student *curr = new Student;
    cout << "Enter Student id: ";
    cin >> curr->id;
    cout << "Enter Student marks: ";
    cin >> curr->marks;
    if (last == NULL)
    {
        last = curr; curr->next = last;
    }
    else
    {
        curr->next = last->next;
        last->next = curr;
        /*Above two lines follows same instruction as of Insert_Start
        this below line just changes last pointer by setting it to curr
        which says I am the last of this list and also points to first node
        and that defines the circular linked list*/ 
        last = curr;
    }
}

void insert_Before_Specific()
{
    cout << "Enter Specific id to insert before it: ";
    int key; cin>>key; Student *p = last->next;
    while ((p->next->id != key)&(p != NULL))
    {
        p = p->next;
    }
    if (p->next->id == key)
    {   
        Student *curr = new Student;
        cout<<"Enter Student id: ";
        cin>>curr->id;
        cout<<"Enter Student marks: ";
        cin>>curr->marks;

        curr->next = p->next; p->next = curr;
    }
    else
    {
        cout<<"Id you Entered is not present in Linked List";
    }
}
void insert_After_Specific()
{
    cout << "Enter Specific id to insert after it: ";
    int key; cin>>key; Student *p = last->next;
    if (last->id != key)
    {    
        while ((p->id != key)&(p != NULL))
        {
            p = p->next;
        }
        if (p->id == key)
        {   
            Student *curr = new Student;
            cout<<"Enter Student id: ";
            cin>>curr->id;
            cout<<"Enter Student marks: ";
            cin>>curr->marks;

            curr->next = p->next; p->next = curr;
        }
        else
        {
            cout<<"Id you Entered is not present in Linked List";
        }
    }
    else
    {
        insert_End();
    }
      
}
void delete_Start()
{
    Student *p = last->next;
    last->next = p->next;
    delete p;
}
void delete_End()
{
    Student *p = last->next;
    while (p->next != last)
    {
        p = p->next;
    }
    if (p->next == last)
    {
        Student *d = last;
        p->next = last->next; last = p;
        delete d;
    }
}
void delete_Before_Specific()
{
    Student *p = last->next;
    cout << "Enter Specific id to delete before it: ";
    int key; cin>>key;
    if (last->next->id != key)
    {
        while (p->next->next->id != key)
        {
            p = p->next;
        }
        if (p->next->next->id == key)
        {
            Student *d = p->next;
            p->next = d->next;
            delete d;
        }
    }
    else
    {
        cout<<"Can't delete before First";
    }
    
}

void delete_After_Specific()
{
    Student *p = last->next;
    cout << "Enter Specific id to delete it: ";
    int key; cin>>key;
    if (last->id != key)
    {
        while ((p->id != key)&(p != last))
        {
            p = p->next;
        }
        if (p->id == key)
        {
            Student *d = p->next;
            p->next = d->next;
            delete d;
        }
    }
    else
    {
        cout<<"Can't delete after last";
    }
}
void delete_Specific()
{
    Student *p = last->next;
    cout << "Enter Specific id to delete it: ";
    int key; cin>>key;
    if ((last->id != key)&(last->next->id != key))
    {
        while ((p->next->id != key)&(p != last))
        {
            p = p->next;
        }
        if (p->next->id == key)
        {
            Student *d = p->next;
            p->next = d->next;
            delete d;
        }
    }
    else if (last->id == key)
    {
        delete_End();
    }
    else
    {
        delete_Start();
    }
    
    
}
void display()
{
    Student *p = last->next;
    if (last != NULL)
    {
        while (p != last)
        {
            cout<<"\nStudent Id: "<<p->id<<"\n";
            cout<<"Student Marks: "<<p->marks<<"\n";
            p = p->next;
        }
        cout<<"\nStudent Id: "<<p->id<<"\n";
        cout<<"Student Marks: "<<p->marks<<"\n";
    }
    else
    {
        cout<<"\nNo Data Display\n";
    }
    
}

void opt()
{
    cout << "\nEnter 1 to insert at start\n";
    cout << "Enter 2 to insert at End\n";
    cout << "Enter 3 to insert before a Specific\n";
    cout << "Enter 4 to insert after a specific\n";
    cout << "Enter 5 to Delete at Start\n";
    cout << "Enter 6 to Delete at End\n";
    cout << "Enter 7 to Delete before a Specific\n";
    cout << "Enter 8 to Delete after a Specific\n";
    cout << "Enter 9 to Delete a Specific\n";
    cout << "Enter 10 to Display data in Linked List\n";
    cout << "Enter 0 to to Quit\n";

    cout << "\nEnter your choice to perform the task: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nInsert at Start Method\n";
        insert_Start(); opt(); break;
    case 2:
        cout << "\nInsert at End Method\n";
        insert_End(); opt(); break;
    case 3:
        cout << "\nInsert before a Specific Method\n";
        insert_Before_Specific(); opt(); break;
    case 4:
        cout << "\nInsert after a Specific Method\n";
        insert_After_Specific(); opt(); break;
    case 5:
        cout << "\nDelete at Start Method\n";
        delete_Start(); opt(); break;
    case 6:
        cout << "\nDelete at End Method\n";
        delete_End(); opt(); break;
    case 7:
        cout << "\nDelete before a Specific Method\n";
        delete_Before_Specific(); opt(); break;
    case 8:
        cout << "\nDelete after a SpecificMethod\n";
        delete_After_Specific(); opt(); break;
    case 9:
        cout << "\nDelete a Specific Method\n";
        delete_Specific(); opt(); break;
    case 10:
        cout << "\nDISPLAY OF DATA Method\n";
        display(); opt(); break;
    case 0:
        cout << "\nPROCESS TERMINATED SUCCESSFULLY\n";
        break;

    default:
        cout <<"\nINVALID CHOICE ENTERED TRY AGAIN!!\n";
        opt(); break;
    }
}
int main()
{
    opt();
    return 0;
}
