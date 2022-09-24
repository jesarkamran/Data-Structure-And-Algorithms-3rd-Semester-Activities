#include <iostream>
#include <string>
using namespace std;

struct Stack
{
    int size,top = -1;
    int *intArr;
};

Stack *p = new Stack;
void push()
{
    for (int i = 0; i < p->size; i++)
    {
        if (p->top >= -1)
        {
            p->top++;
            cout<<"Enter id to push into the Stack: ";
            cin>>p->intArr[p->top];
        }
        else if (p->top == p->size-1)
        {
            cout<<"\nCant push values Further into the STACK"<<endl;
        }
    }
}
int pop()
{
    int num = p->intArr[p->top];
    p->top--; return num;
}
void checkPalindrome()
{
    string st1="", st2="";
    for (int i = 0; i <= p->top; i++)
    {
        string str = to_string(p->intArr[i]);
        st1 += str;
    }

    for (int i = p->top; i >= 0; i--)
    {
        string str = to_string(p->intArr[i]);
        st2 += str;
    }

    if (st1 == st2)
    {
        cout<<"\nStack is Palindrome"<<endl;
    }
    else
    {
        cout<<"\nStack is not Palindrome"<<endl;
    }
    
    
}
void display()
{
    cout<<"\nData in Stack: ";
    for (int i = 0; i <= p->top; i++)
    {
        cout<<p->intArr[i]<<" ";
    }
    
}
void opt()
{
    cout<<"\n***MENUE***"<<endl
    <<"\n1- Push a number in Stack"<<endl
    <<"2- Pop a number from Stack"<<endl
    <<"3- Display Data of Stack"<<endl
    <<"4- Check Palindrome"<<endl
    <<"0- Terminate the Process"<<endl;

    cout<<"\nEnter your choice: ";
    int choice; cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\nPUSH A VALUE INTO THE STACK METHOD"<<endl;
        push(); opt(); break;
    
    case 2:
        cout<<"\nPOP A VALUE OUT OF THE STACK METHOD"<<endl;
        cout<<"Id poped out from the Stack: "<<pop()<<endl; opt(); break;
    
    case 3:
        cout<<"\nDISPLAY OF DATA IN THE STACK METHOD"<<endl;
        display(); opt(); break;
    
    case 4:
        cout<<"\nCHECK STACK IS PALINDROME OR NOT METHOD"<<endl;
        checkPalindrome(); opt(); break;

    case 0:
        cout<<"\nProcess Terminated Successfully"<<endl;
        break;
    
    default:
        cout<<"\nINVALID CHOICE TRY AGAIN!!"<<endl;
        opt(); break;
    }
}
void setSize()
{
    cout<<"Enter size of Array: ";
    cin>>p->size;
    p->intArr = new int[p->size];
}
int main()
{
    setSize();
    opt();
    return 0;
}
