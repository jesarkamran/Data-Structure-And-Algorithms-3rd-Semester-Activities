/* QUEUE DATA STRUCTURE Static Implentation
By: Kamran Jesar SP21-BCS-033
*/
#include <iostream>
using namespace std;
struct Queue
{
    int *idArr;
    int front = -1, rear = -1;
};

Queue *curr = new Queue;
void enQueue();
void deQueue();
bool isEmpty();
void display();
bool isFull();

void enQueue()
{
    cout<<"Enter id to enQueue in the DATA: ";
    int id; cin>>id;
    if((id != -1)&&(isFull() == false))
    {
        if(isEmpty() == true)
        {
            curr->front = curr->rear += 1;
            curr->idArr[curr->front] = id;
        }
        else
        {
            curr->rear++;
            curr->idArr[curr->rear] = id;
        }
        enQueue();
    }
    else
    {
        if (isFull() == true)
        {
            cout<<"QUEUE is FULL can't ENQUEUE Data further"<<endl;
        }
        else
        {
            cout<<"ENQUEUE of DATA Stopped"<<endl;
        }
    }

}

void deQueue()
{
    if (isEmpty() == false)
    {
        if (curr->front == curr->rear)
        {
            cout<<"ID: "<<curr->idArr[curr->front]<<" DeQueued form DATA"<<endl;
            curr->front = curr->rear = -1;
        }
        else
        {
            cout<<"ID: "<<curr->idArr[curr->front]<<" DeQueued form DATA"<<endl;
            curr->front++;
        }
    }
    else
    {
        cout<<"\nNO DATA to DeQueue"<<endl;
    }
}
bool isEmpty()
{
    if (curr->front == -1)
    {
        return true;
    }
    
    return false;
}
bool isFull()
{
    if (curr->rear  == 10-1)
    {
        return true;
    }
    return false;
}
void display()
{
    if(isEmpty() == false)
    {
        for(int i = curr->front; i<=curr->rear; i++)
        {
            cout<<"Id: "<<curr->idArr[i]<<endl;
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
        <<"4- IS QUEUE FULL"<<endl
        <<"5- DISPLAY QUEUE DATA"<<endl
        <<"0- TERMINATE THE PROGRAM"<<endl;

    cout<<"\nEnter choice: ";
    int choice; cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\nENQUEUE DATA METHOD"<<endl;
        cout<<"Enter -1 to stop EnQueue of Data\n";
        enQueue(); opt(); break;
    
    case 2:
        cout<<"\nDEQUEUE DATA METHOD"<<endl;
        deQueue();opt(); break;
    
    case 3:
        cout<<"\nIS QUEUE EMPTY METHOD"<<endl;
        if(isEmpty()==true)
        {
            cout<<"QUEUE is EMPTY"<<endl;
        }
        else
        {
            cout<<"QUEUE is not EMPTY"<<endl;
        }       
        opt(); break;

    case 4:
        cout<<"\nIS QUEUE FULL METHOD"<<endl;
        if(isFull()==true)
        {
            cout<<"QUEUE is FULL"<<endl;
        }
        else
        {
            cout<<"QUEUE is not FULL"<<endl;
        }       
        opt(); break;
    
    case 5:
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
    curr->idArr = new int[10];
    opt();
    return 0;
}
