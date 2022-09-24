/* Circular Linked List
Kamran Jesar SP21-BCS-033
Merging Two Linked List
*/
#include <iostream>
using namespace std;
struct LinkedList
{
    int num;
    LinkedList *next = NULL;
};
LinkedList *last1 = NULL, *last2 = NULL, *last3 = NULL;
int intArr1[] = {12, 28, 18, 25, 19}; //data of 1st list
int intArr2[] = {5, 24, 12, 6, 15}; //data of 2nd list
void createList(int listNum, int intArr[], int size)
{
    if(listNum == 1)
    {
        for (int i = 0; i < size; i++)
        {
            LinkedList *curr; curr = new LinkedList;
            curr->num = intArr[i];
            if (last1 == NULL)
            {
                last1 = curr; curr->next = last1;
            }
            else
            {
                curr->next = last1->next;
                last1->next = curr;
                last1 = curr;
            }
        }
    }
    else if (listNum == 2)
    {
        for (int i = 0; i < size; i++)
        {
            LinkedList *curr; curr = new LinkedList;
            curr->num = intArr[i];
            if (last2 == NULL)
            {
                last2 = curr; curr->next = last2;
            }
            else
            {
                curr->next = last2->next;
                last2->next = curr;
                last2 = curr;
            }
        }
    }
    
}
    
void display(LinkedList *p, int i)
{
    if (p != NULL)
    {
        LinkedList *k = p;
        do
        {
            cout<<p->num<<"->";
            p = p->next;
        }
        while (p != k);
        cout<<"NULL\n";
    }
    else
    {
        cout<<"\nNO DATA TO DISPLAY\n";
    }

    if (i == 1)
    {
        if (last2 != NULL)
        {
            display(last2->next, 0);
        }
        else
        {
            cout<<"\nNO DATA TO DISPLAY"<<endl;
        }
    }
    else if (i == 2)
    {
        if ((last3 != NULL)&(last2 != NULL))
        {
            display(last2->next, 0);
            display(last3->next, 0);
        }
        else
        {
            cout<<"\nNO DATA TO DISPLAY"<<endl;
        }
        
    }
}
void sorter(LinkedList *p1, LinkedList *p2)
{
    LinkedList *k = p1;
    do
    {
        do
        {
            if (p1->num > p2->num)
            {
                int temp = p2->num;
                p2->num = p1->num;
                p1->num = temp;
            }
            p2 = p2->next;
            
        } while (p2 != k);
        
        p1 = p1->next;
        
    } while (p1 != k);
}

void merge()
{
    sorter(last1->next, last1->next);
    sorter(last2->next, last2->next);
    LinkedList *p1 = last1->next;
    LinkedList *p2 = last2->next;
    if ((last1 != NULL)||(last2!=NULL))
    {
        do
        {
            LinkedList *p3,*p4; p3 = new LinkedList;
            p4 = new LinkedList; p3->num = p1->num;
            p4->num = p2->num;
            if ((last1 != NULL)&(last2!=NULL))
            {
                if (last3 == NULL)
                {
                    last3 = p3; p3->next = last3;
                    p4->next = last3->next; last3->next = p4; last3 = p4;
                }
                else
                {
                    p3->next = last3->next; last3->next = p3; last3 = p3;
                    p4->next = last3->next; last3->next = p4; last3 = p4;
                }
            }
            else if (last1 == NULL)
            {
                if (last3 == NULL)
                {
                    last3 = p4; p4->next = last3;
                }
                else
                {
                    p4->next = last3->next; last3->next = p4; last3 = p4;
                }
            }
            else if (last2 == NULL)
            {
                 if (last3 == NULL)
                {
                    last3 = p3; p3->next = last3;
                }
                else
                {
                    p3->next = last3->next; last3->next = p3; last3 = p3;
                }
            }
            p1 = p1->next; p2 = p2->next;
        } while ((p1 != last1->next)|(p2!=last2->next));
    }
    else
    {
        cout<<"\nBoth lists are Empty"<<endl;
    }
}
void opt()
{
    cout<<"\n1- Create 1st linked list"<<endl
        <<"2- Create 2nd linked list"<<endl
        <<"3- Display data of list"<<endl
        <<"4- Merge Two created linked Lists"<<endl
        <<"0- Terminate the Program"<<endl;

    cout<<"\nEnter your desired task No: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout<<"\n1st linked list Creation Method\n";
        createList(1, intArr1, 5);
        opt(); break;

    case 2:
        cout<<"\n2nd linked list Creation Method\n";
        createList(2, intArr2, 5);
        opt(); break;

    case 3:
        cout<<"\nData Display Method\n";
        cout<<"-1 to display 1st Linked List\n"
            <<"-2 to display 2nd Linked List"<<endl
            <<"-3 to display Merged Linked List"<<endl
            <<"-4 to display All Linked Lists"<<endl;
        cout<<"Enter Choice: ";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            display(last1->next, 0);
        }
        else if(ch == 2)
        {
            display(last2->next, 0);
        }
        else if(ch == 3)
        {
            display(last3->next, 0);
        }
        else if (ch == 4)
        {
            display(last1->next, 2);
        }
        else
        {
            cout<<"\nINVALID CHOICE TRY AGAIN!!"<<endl;
        }
        opt();
        break;

    case 4:
        cout<<"\nMerge Two linked List\n";
        merge(); opt(); break;

    case 0:
        cout<<"\nProcess Terminated Successfully\n";
        break;

    default:
        cout<<"\nInvalid Input Entered try Again!!\n";
        opt(); break;
    }
}
int main()
{
    opt();
    return 0;
}
