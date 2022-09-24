/* DOUBLY LINKED LIST  QUESTION 2 
SP21-BCS-033 KAMRAN JESAR
*/
#include <iostream>
using namespace std;
void opt();
struct Subjects
{
    int sub_id;
    float marks;
    Subjects *next_Sub = NULL;
};
struct Student
{
    int id; float gpa;
    Student *next = NULL;
    Student *prev = NULL;
    Subjects *last_Sub = NULL;
};
Student *first = NULL, *last = NULL;
Student* input_Getter()
{
    Student *curr = new Student;
    cout<<"Enter id of Student: ";
    cin>>curr->id;
    cout<<"Enter GPA of Student: ";
    cin>>curr->gpa; cout<<"\n";
    return curr;
}
void insert_Start()
{
    Student *curr = input_Getter();
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

void insert_End()
{
    Student *curr = input_Getter();
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr; curr->prev = last;last = curr;
    }
}

void insert_Before_Specific()
{
    cout<<"Enter specific id to Insert before it: ";
    int key; cin>>key;
    if (first != NULL)
    {
        if (first->id == key)
        {
            insert_Start();
        }
        else
        {
            Student *curr = input_Getter();
            if (last->id == key)
            {
                last->prev->next = curr; curr->prev = last->prev;
                last->prev = curr; curr->next = last;
            }
            else
            {
                Student *p = first->next;
                while ((p->id != key)&(p != last))
                {
                    p = p->next;
                }
                if (p->id == key)
                {
                    p->prev->next = curr; curr->prev = p->prev;
                    p->prev = curr; curr->next = p;
                }
                else
                {
                    cout<<"\nDATA not found\n";
                }   
            }   
        } 
    }
    else
    {
        cout<<"\nThere is No data to Search give ID\n";
    }
}

void insert_After_Specific()
{
    cout<<"Enter specific id to Insert After it: ";
    int key; cin>>key;
    if (first != NULL)
    {
        if (last->id == key)
        {
            insert_End();
        }
        else
        {
            Student *curr = input_Getter();
            if (first->id == key)
            {
                first->next->prev = curr; curr->prev = first;
                curr->next = first->next; first->next = curr;
            }
            else
            {
                Student *p = first->next;
                while ((p->id != key)&(p != last))
                {
                    p = p->next;
                }
                if (p->id == key)
                {
                    p->next->prev = curr; curr->prev = p;
                    curr->next = p->next; p->next = curr;
                }
                else
                {
                    cout<<"\nDATA not found\n";
                }   
            }   
        }
    }
    else
    {
        cout<<"\nThere is No data to Search give ID\n";
    }
    
}
void delete_Start()
{
    if (first != NULL)
    {   
        if (first->next != NULL)
        {
            Student *p = first;
            first->next->prev = NULL; first = p->next;
            delete p;
        }
        else
        {
            first = NULL;
            delete first;
        }
        
    }
    else
    {
        cout<<"\nNO DATA TO DELETE\n";
    }
}

void delete_End()
{
    if (first != NULL)
    {
        Student *p = last; last = last->prev;
        last->next = NULL; delete p;
    }
    else
    {
        cout<<"\nNO DATA TO DELETE\n";
    }
}

void delete_Before_Specific()
{
    if (first != NULL)
    {    
        if (first != last)
        {
            cout<<"Enter specfic ID to delete before it: ";
            int key; cin>>key;
            if (first->id == key)
            {
                cout<<"There is no data before first node";
            }
            else if (last->id == key)
            {
                Student *p = last->prev;
                p->prev->next = last; last->prev = p->prev;
                delete p;
            }
            
            else
            {        
                Student *p = first->next;
                while ((p->id!=key)&(p != p->prev))
                {
                    p = p->next;
                }
                if (p->id == key)
                {
                    Student *d = p->prev;
                    d->prev->next = p; p->prev = d->prev;
                    delete d;
                }
                else
                {
                    cout<<"\nID not found\n";
                }   
            }
        }
        else
        {
            cout<<"\nThere is only one item in the linked list\n";
            cout<<"can't delete before or after \n";
            cout<<"\nIf you wanna delete the only one element\n";
            cout<<"Then Enter 1 else 0 to go back to main menu";
            int pref; cin>>pref;
            if (pref == 1)
            {
                delete first, last;
            }
            else if (pref == 0)
            {
                
            }
            else
            {
                cout<<"\nInvalid Entry going back to main menu.....\n";
            }
            
        }
    }
    else
    {
        cout<<"\nNO DATA TO DELETE\n";
    }
}

void delete_After_Specific()
{
    if (first != NULL)
    {    
        if (first != last)
        {
            cout<<"Enter specfic ID to delete After it: ";
            int key; cin>>key;
            if (first->id == key)
            {
                Student *p = first->next;
                p->next->prev = first; first->next = p->next;
                delete p;
            }
            else if (last->id == key)
            {
                cout<<"There is no data After last node";
            }
            
            else
            {        
                Student *p = first->next;
                while ((p->id!=key)&(p != p->prev))
                {
                    p = p->next;
                }
                if (p->id == key)
                {
                    Student *d = p->next;
                    d->next->prev = p; p->next = d->next;
                    delete d;
                }
                else
                {
                    cout<<"\nID not found\n";
                }   
            }
        }
        else
        {
            cout<<"\nThere is only one item in the linked list\n";
            cout<<"can't delete before or after \n";
            cout<<"\nIf you wanna delete the only one element\n Then Enter 1 else 0 to go back to main menu";
            int pref; cin>>pref;
            if (pref == 1)
            {
                delete first, last;
            }
            else if (pref == 0)
            {
                
            }
            else
            {
                cout<<"\nInvalid Entry going back to main menu.....\n";
            }
            
        }
    }
    else
    {
        cout<<"\nNO DATA TO DELETE\n";
    }
}
void delete_Specific()
{
    cout<<"Enter specfic ID to delete it: ";
    int key; cin>>key;
    if (first != NULL)
    {    
        if (first->id == key)
        {
            delete_Start();
        }
        else if (last->id == key)
        {
            delete_End();
        }
        
        else
        {        
            Student *p = first->next;
            while ((p->id!=key)&(p != last))
            {
                p = p->next;
            }
            if (p->id == key)
            {
                p->prev->next = p->next; p->next->prev = p->prev;
                delete p;
            }
            else
            {
                cout<<"\nID not found\n";
            }   
        }
    }
    else
    {
        cout<<"\nNO DATA TO DELETE\n";
    }
}
void display()
{
    if (first != NULL)
    {
        Student *p = first;
        while (p!=NULL)
        {
            cout<<"\nStudent Id: "<<p->id<<"\n";
            cout<<"Student GPA: "<<p->gpa<<"\n";
            p = p->next;
        }
    }
    else
    {
        cout<<"No Data to Display";
    }
}
Subjects* input_Getter_Subjects()
{
    Subjects *curr = new Subjects;
    cout<<"Enter Subject Id: ";
    cin>>curr->sub_id;
    cout<<"Enter marks of Student: ";
    cin>>curr->marks;
    return curr;
}
void insert_Start_Subjects(Student *node_Pointer)
{
    Subjects *curr = input_Getter_Subjects();
    if (node_Pointer->last_Sub == NULL)
    {
        node_Pointer->last_Sub = curr;
        node_Pointer->last_Sub->next_Sub = curr;
    }
    else
    {
        curr->next_Sub = node_Pointer->last_Sub->next_Sub; node_Pointer->last_Sub->next_Sub = curr;
    }
    
}
void insert_End_Subjects(Student *node_Pointer)
{
    Subjects *curr = input_Getter_Subjects();
    if (node_Pointer->last_Sub == NULL)
    {
        node_Pointer->last_Sub = curr;
        node_Pointer->last_Sub->next_Sub = curr;
    }
    else
    {
        curr->next_Sub = node_Pointer->last_Sub->next_Sub; 
        node_Pointer->last_Sub->next_Sub = curr;
        node_Pointer->last_Sub = curr;
    }
}
void insert_Before_Specific_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        cout<<"Enter Specific ID where you want to \nEnter data before it: ";
        int key; cin>>key;
        if (node_Pointer->last_Sub->next_Sub->sub_id == key)
        {
            insert_Start_Subjects(node_Pointer);
        }
        else
        {
            Subjects *p = node_Pointer->last_Sub->next_Sub;
            while ((p->next_Sub->sub_id != key)&(p != node_Pointer->last_Sub))
            {
                p = p->next_Sub;
            }
            if (p->next_Sub->sub_id == key)
            {           
                Subjects *curr = input_Getter_Subjects();
                curr->next_Sub = p->next_Sub; p->next_Sub = curr;
            }
            else
            {
                cout<<"ID NOT FOUND!!";
            }

        }
    }
    else
    {
        cout<<"\nList is empty cant insert before or after\n";
        cout<<"If you want insert\nThen Enter 1 else 0 to go back: ";
        int pref; cin>>pref;
        if (pref == 1)
        {
            insert_Start_Subjects(node_Pointer);
        }
        else if (pref == 0)
        {
        
        }
        else
        {
            cout<<"Invalid entry going back to main menu....";
        }
    }
    
}
void insert_After_Specific_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        cout<<"Enter Specific ID where you want to \nEnter data After it: ";
        int key; cin>>key;
        if (node_Pointer->last_Sub->sub_id == key)
        {
            insert_End_Subjects(node_Pointer);
        }
        else
        {
            Subjects *p = node_Pointer->last_Sub->next_Sub;
            while ((p->sub_id != key)&(p != node_Pointer->last_Sub))
            {
                p = p->next_Sub;
            }
            if (p->sub_id == key)
            {           
                Subjects *curr = input_Getter_Subjects();
                curr->next_Sub = p->next_Sub; p->next_Sub = curr;
            }
            else
            {
                cout<<"\nID not found\n";
            }  
        }
    }
    else
    {
        cout<<"\nList is empty cant insert before or after\n";
        cout<<"If you want insert\nThen Enter 1 else 0 to go back: ";
        int pref; cin>>pref;
        if (pref == 1)
        {
            insert_Start_Subjects(node_Pointer);
        }
        else if (pref == 0)
        {
        
        }
        else
        {
            cout<<"Invalid entry going back to main menu";
        }
    }
}
void delete_Start_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        Subjects *p = node_Pointer->last_Sub->next_Sub;
        node_Pointer->last_Sub->next_Sub = p->next_Sub;
        delete p;
    }
    else
    {
        cout<<"\nNo Data to Delete\n";
    }
    
}
void delete_End_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        Subjects *p = node_Pointer->last_Sub->next_Sub;
        while (p->next_Sub != node_Pointer->last_Sub)
        {
            p = p->next_Sub;
        }
        Subjects *d = p->next_Sub;
        p->next_Sub = d->next_Sub;
        node_Pointer->last_Sub = p;
        delete d;
    }
    else
    {
        cout<<"\nNo Data to Delete\n";
    }    
}
void delete_Before_Specific_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        cout<<"Enter Specific id to Delete before it: ";
        int key; cin>>key;
        if (node_Pointer->last_Sub->next_Sub->sub_id ==key)
        {
            cout<<"\nNo Data to delete before first Node\n";
        }
        else
        {

            Subjects *p = node_Pointer->last_Sub->next_Sub->next_Sub;
            while ((p->next_Sub->next_Sub->sub_id != key)&(p != node_Pointer->last_Sub->next_Sub))
            {            
                p = p->next_Sub;
            }
            if (p->next_Sub->next_Sub->sub_id == key)
            {
                Subjects *d = p->next_Sub;
                p->next_Sub = d->next_Sub;
                delete d;
            }
            else
            {
                cout<<"\nID not Found\n";
            }
        }
    }
    else
    {
        cout<<"\nNo Data To Delete\n";
    }
    
}
void delete_After_Specific_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        cout<<"Enter Specific id to Delete After it: ";
        int key; cin>>key;
        if (node_Pointer->last_Sub->sub_id ==key)
        {
            cout<<"\nNo Data to delete after last node\n";
        }
        else
        {

            Subjects *p = node_Pointer->last_Sub->next_Sub;
            while ((p->sub_id != key)&(p != node_Pointer->last_Sub))
            {            
                p = p->next_Sub;
            }
            if (p->sub_id == key)
            {
                Subjects *d = p->next_Sub;
                p->next_Sub = d->next_Sub;
                delete d;
            }
            else
            {
                cout<<"\nID not Found\n";
            }
        }
    }
    else
    {
        cout<<"\nNo Data To Delete\n";
    }
}
void delete_Specific_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL)
    {
        cout<<"Enter Specific id to Delete it: ";
        int key; cin>>key;
        if (node_Pointer->last_Sub->next_Sub->sub_id ==key)
        {
            delete_Start_Subjects(node_Pointer);
        }
        
        else if (node_Pointer->last_Sub->sub_id ==key)
        {
            delete_End_Subjects(node_Pointer);
        }
        else
        {

            Subjects *p = node_Pointer->last_Sub->next_Sub->next_Sub;
            while ((p->next_Sub->sub_id != key)&(p != node_Pointer->last_Sub))
            {            
                p = p->next_Sub;
            }
            if (p->sub_id == key)
            {
                Subjects *d = p->next_Sub;
                p->next_Sub = d->next_Sub;
                delete d;
            }
            else
            {
                cout<<"\nID not Found\n";
            }
        }
    }
    else
    {
        cout<<"\nNo Data To Delete\n";
    }
}
void display_Subjects(Student *node_Pointer)
{
    if (node_Pointer->last_Sub != NULL){
        Subjects *p = node_Pointer->last_Sub->next_Sub;
        while (p != node_Pointer->last_Sub)
        {
            cout<<"\nStudent Id: "<<p->sub_id<<"\n";
            cout<<"Student Marks: "<<p->marks<<"\n";
            p = p->next_Sub;
        }
        cout<<"\nStudent Id: "<<p->sub_id<<"\n";
        cout<<"Student Marks: "<<p->marks<<"\n";
    }
    else
    {
        cout<<"\nNo Data Display\n";
    }
}
Student* get_Node()
{
    if (first != NULL)
    {
        cout<<"Enter id of which subjects Data you want to access: ";
        int key; cin>>key;
        if (first->id == key)
        {
            return first;
        }
        else if (last->id == key)
        {
            return last;
        }
        else
        {
            Student *p = first->next;
            while ((p->id!=key)&(p!=last))
            {
                p = p->next;
            }
            if (p->id == key)
            {
                return p;
            }
            else
            {
                cout<<"\nData Not Found\n";
            }
        }
    }
    else
    {
        cout<<"\nList is EMPTY!!\n";
    }
    return NULL;
}
void opt_Subjects(Student *node_Pointer)
{
    cout<<"\n\tSUBJECT DATA MENU\n";
    cout<<"\nEnter 1 to Insert at Start\n";
    cout<<"Enter 2 to Insert at End\n";
    cout<<"Enter 3 to Insert Before Specific\n";
    cout<<"Enter 4 to Insert After Specific\n";
    cout<<"Enter 5 to Delete at Start\n";
    cout<<"Enter 6 to Delete at End\n";
    cout<<"Enter 7 to Delete Before Specific\n";
    cout<<"Enter 8 to Delete After Specific\n";
    cout<<"Enter 9 to Delete Specific\n";
    cout<<"Enter 10 to Display Data\n";
    cout<<"Enter 0 to go back to STUDENT MENU\n";

    cout<<"\nEnter your desired task choice: ";
    int choice; cin>>choice;

    if (choice != 0)
    {
        if (node_Pointer!=NULL)
        {
            switch (choice)
            {
            case 1:
                cout<<"\nINSERTION AT START METHOD\n";
                insert_Start_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 2:
                cout<<"\nINSERTION AT END METHOD\n";
                insert_End_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 3:
                cout<<"\nINSERTION BEFORE SPECIFIC METHOD\n";
                insert_Before_Specific_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 4:
                cout<<"\nINSERTION AFTER SPECIFIC METHOD\n";
                insert_After_Specific_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 5:
                cout<<"\nDELETION AT START METHOD\n";
                delete_Start_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 6:
                cout<<"\nDELETION AT END METHOD\n";
                delete_End_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 7:
                cout<<"\nDELETION BEFORE SPECIFIC METHOD\n";
                delete_Before_Specific_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 8:
                cout<<"\nDELETION AFTER SPECIFIC METHOD\n";
                delete_After_Specific_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 9:
                cout<<"\nDELETE  SPECIFIC METHOD\n";
                delete_Specific_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            
            case 10:
                cout<<"\nDISPLAY OF DATA IN SUBJECT\n";
                display_Subjects(node_Pointer); opt_Subjects(node_Pointer); break;
            default:
                cout<<"\nINVALID CHOICE ENTERED\n";
                opt_Subjects(node_Pointer); break;
            }
        }
        else
        {
            cout<<"\nID you entered of Student Not Found!! going back to MAIN MENU\n";
            opt();
        }
    }
    else
    {
        opt();
    }
}

void opt()
{
    cout<<"\nEnter 1 to insert at Start\n";
    cout<<"Enter 2 to insert at End\n";
    cout<<"Enter 3 to insert before Specific\n";
    cout<<"Enter 4 to insert after Specific\n";
    cout<<"Enter 5 to Delete at Start\n";
    cout<<"Enter 6 to Delete at End\n";
    cout<<"Enter 7 to Delete before Specific\n";
    cout<<"Enter 8 to Delete after Specific\n";
    cout<<"Enter 9 to Delete a Specific\n";
    cout<<"Enter 10 to MENU of SUBJECT DATA\n";
    cout<<"Enter 11 to Display of STUDENT ID and GPA\n";
    cout<<"Enter 0 to Quit\n";

    cout<<"\nEnter choice of your Desired Task: ";
    int choice; cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\nINSERTION AT START METHOD\n";
        insert_Start(); opt(); break;
    
    case 2:
        cout<<"\nINSERTION AT END METHOD\n";
        insert_End(); opt(); break;
    
    case 3:
        cout<<"\nINSERTION BEFORE SPECIFIC METHOD\n";
        insert_Before_Specific(); opt(); break;
    
    case 4:
        cout<<"\nINSERTION AFTER SPECIFIC METHOD\n";
        insert_After_Specific(); opt(); break;
    
    case 5:
        cout<<"\nDELETION AT START METHOD\n";
        delete_Start(); opt(); break;
    
    case 6:
        cout<<"\nDELETION AT END METHOD\n";
        delete_End(); opt(); break;
    
    case 7:
        cout<<"\nDELETION BEFORE SPECIFIC METHOD\n";
        delete_Before_Specific(); opt(); break;
    
    case 8:
        cout<<"\nDELETION AFTER SPECIFIC METHOD\n";
        delete_After_Specific(); opt(); break;
    
    case 9:
        cout<<"\nDELETE  SPECIFIC METHOD\n";
        delete_Specific(); opt(); break;
    
    case 10:
        Student *node_Pointer;
        node_Pointer = get_Node();
        opt_Subjects(node_Pointer); break;

    case 11:
        cout<<"\nDISPLAY OF DATA IN STUDENT\n";
        display(); opt(); break;
    
    case 0:
        cout<<"\nPROCESS TERMINATED SUCCESSFULLY\n";
        break;
    
    default:
        cout<<"\nINVALID ENTRY TRY AGAIN!!!\n";
        opt(); break;
    }
}
int main()
{
    opt(); return 0;
}
