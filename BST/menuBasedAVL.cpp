#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *root = NULL;

void preOrderDisplay(Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preOrderDisplay(p->left);
        preOrderDisplay(p->right);
    }
}

//THIS METHOD WILL HELP ME FIND THE HEIGHT OF EVERY NEW NODE THAT I WILL INSERT
//THIS IS BEING CALLED IN BALANCE FACTOR METHOD WHICH WILL CALL IT ACCORDING TO FUNCTIONALITY

int heightOfAVL(Node *p){
    if(p==NULL){
        return 0;
    }
    return max(heightOfAVL(p->left), heightOfAVL(p->right)) + 1;
}

//THIS METHOD I MAY CALL AS THE ONE OF THE FATHER OF ALL OF THESE METHODS WHICH I HAVE DEFINED BELOW
//THIS ONE IS NOT COMPLEX BUT DUE TO THIS METHOD COMPARISON FUNCTIONALITY I AM ABLE TO FIND THE HEIGHT
// BALANCE FACTOR OF EVERY NEW NODE THAT I AM INSERTING
int balanceFactor(Node *p){
    if (p==NULL){
        return -1;
    }else{
        return (heightOfAVL(p->left) - heightOfAVL(p->right));
    }
}

//THIS METHOD WORKS SAME AS LIKE MEE THAT IS OPPOSITE OF EVERY THING
//BY IT'S NAME IT IS RIGHT ROTATE BUT IT IS BEING CALLED WHEN I NEED TO LEFT-LEFT ROTATE THE NODES
//

Node* rightRotate(Node *y) {

    //INITIALLY I HAVE SETTED UP THE VALUES IN THESE POINTERS
    Node* x = y -> left;
    Node* nullCheckerNode = x -> right;

    // AFTER THAT I HAD PERFORMED THE ROTATION
    x -> right = y;
    y -> left = nullCheckerNode;

    return x;
}

Node* leftRotate(Node * x) {
    Node* y = x -> right;
    Node* nullCheckerNode = y -> left;

    // Perform rotation
    y -> left = x;
    x -> right = nullCheckerNode;

    return y;
}
Node* insert(Node *p,Node *newNode){
    if (p==NULL){
        p = newNode;
        cout<<"Value Inserted Deepak \n";
        return p;
    }else if(newNode->data < p->data){
        p->left = insert(p->left,newNode);
    }else if(newNode->data > p->data){
        p->right = insert(p->right,newNode);
    }else{
        cout<<"Can't Insert Duplicate  Values";
    }

    int bf = balanceFactor(p);

    //Checking for LL Rotations
    if(bf > 1 && newNode->data < p->left->data){
        return rightRotate(p);
    }
    //Checking for RR Rotations
    if(bf < -1 && newNode->data > p->right->data){
        return leftRotate(p);
    }
    //Checking for LR Rotations
    if(bf > 1 && newNode->data > p->left->data){
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }
    //Checking for RL Rotations
    if(bf < -1 && newNode->data < p->right->data){
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
    //In the end I am going to return the pointer for the next recursive call
    return p;
}

void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0  -  Exit \n";
    cout<<"1  -  Insert In AVL \n";
    cout<<"2  -  Pre-Order Traversal \n";
    cout<<"3  -  Height of AVL \n";
    cout<<"4  -  Delete In AVL \n";
    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option) {
        case 0:
            break;
        case 1:
            Node *newNode;
            newNode = new Node;
            cout << "Enter Value to Insert: ";
            int num;
            cin >> num;
            newNode->data = num;
            root = insert(root, newNode);
            mainMenu();
            break;
        case 2:
            preOrderDisplay(root);
            mainMenu();
            break;
        case 3:
            cout << "Height of AVL Tree Is: " << heightOfAVL(root) << endl;
            mainMenu();
            break;
        default:
            cout<<"Wrong Option Enter Again";
            mainMenu();
    }

}
int main(){
    mainMenu();
}