/* QUEUE DATA STRUCTURE Dynamic Implentation
By: Kamran Jesar SP21-BCS-033
*/
#include <iostream>
using namespace std;
struct Queue
{
    int id;
    Queue *next = NULL;
};
Queue *front=NULL, *rear = NULL;

void enQueue();
void deQueue();
bool isEmpty();
void display();

void enQueue()
{
    Queue *curr = new Queue;

    cout<<"Enter id to enQueue in the DATA: ";
    cin>>curr->id;
    if(isEmpty() == true)
    {
        front = rear = curr;
    }
    else
    {
        rear->next = curr;
        rear = curr;
    }
}

void deQueue()
{
    if (isEmpty() == false)
    {
        cout<<"ID: "<<front->id<<" DeQueued form DATA"<<endl;
        front = front->next;
    }
    else
    {
        cout<<"\nNO DATA to DeQueue"<<endl;
    }
}
bool isEmpty()
{
    if (front == NULL)
    {
        return true;
    }
    
    return false;
}
void display()
{
    if(isEmpty() == false)
    {
        Queue *p = front;
        while (p != NULL)
        {
            cout<<"Id: "<<p->id<<endl;
            p = p->next;
        }
    }
    else
    {   
        cout<<"\nNO DATA DISPLAY"<<endl;
    }
     
}
void opt()
{
    cout<<"\nWELCOME TO QUEUE DATA STRUCTURE"<<endl;
    cout<<"\n1- ENQUEUE DATA"<<endl
        <<"2- DEQUEUE DATA"<<endl
        <<"3- IS QUEUE EMPTY"<<endl
        <<"4- DISPLAY QUEUE DATA"<<endl
        <<"0- TERMINATE THE PROGRAM"<<endl;

    cout<<"\nEnter choice: ";
    int choice; cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\nENQUEUE DATA METHOD"<<endl;
        enQueue(); opt(); break;
    
    case 2:
        cout<<"\nDEQUEUE DATA METHOD"<<endl;
        deQueue();opt(); break;
    
    case 3:
        cout<<"\nIS QUEUE EMPTY METHOD"<<endl;
        isEmpty(); opt(); break;

    case 4:
        cout<<"\nDISPLAY QUEUE DATA METHOD"<<endl;
        display(); opt(); break;
    
    case 0:
        cout<<"\nPROCESS TERMINATED SUCCESSFULLY\n"<<endl;
        break;
    
    default:
        cout<<"\nINVALID CHOICE ENTERED TRY AGAIN!!"<<endl;
        opt(); break;
    }
}
int main()
{
    opt();
    return 0;
}
