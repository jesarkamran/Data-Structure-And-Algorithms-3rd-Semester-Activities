/* Singular Linked List
Kamran Jesar SP21-BCS-033
Careem Management System
*/#include <iostream>
#include <string>
using namespace std;

struct RideData
{
    string riderName;
    int numberOfRides;
    double distanceTravelled;
    double charges;
    RideData *next = NULL;
};
struct CarData
{
    string driverName;
    string carName;
    string regNumber;
    int carType;
    double distanceTravelled;
    CarData *next = NULL;
    RideData *firstOfRide = NULL, *lastOfRide = NULL;
};
CarData *firstOfCar = NULL, *lastOfCar = NULL;

void registerNewCar()
{
    CarData *curr = new CarData;
    cout<<"Enter Driver Name: ";
    cin>>curr->driverName;
    
    cout<<"Enter Car Name: ";
    cin>>curr->carName;

    cout<<"Enter Car Registration Number: ";
    cin>>curr->regNumber;

    cout<<"Enter Car Type (1/2): ";
    cin>>curr->carType;

    cout<<"Enter distance travelled by car in Km: ";
    cin>>curr->distanceTravelled;

    if (firstOfCar == NULL)
    {
        firstOfCar = lastOfCar = curr;
    }
    else
    {
        lastOfCar->next = curr;
        lastOfCar = curr;
    }
    
}
void displayCarData()
{
    CarData *p = firstOfCar;
    while (p != NULL)
    {
        cout<<"\nDriver Name: "<<p->driverName<<endl;
        cout<<"Car Name: "<<p->carName<<endl;
        cout<<"Registration Number: "<<p->regNumber<<endl;
        cout<<"Car Type: "<<p->carType<<endl;
        cout<<"Distance Travelled: "<<p->distanceTravelled<<"km"<<endl;

        p = p->next;
    }
    
}
void displayType2Cars()
{
    CarData *p = firstOfCar;
    while (p != NULL)
    {
        if (p->carType == 2)
        {
            cout<<"\nDriver Name: "<<p->driverName<<endl;
            cout<<"Car Name: "<<p->carName<<endl;
            cout<<"Registration Number: "<<p->regNumber<<endl;
            cout<<"Car Type: "<<p->carType<<endl;
            cout<<"Distance Travelled: "<<p->distanceTravelled<<"km"<<endl;
        }
        p = p->next;
    }
    
}

void addNewRide(CarData *node_Pointer)
{
    RideData *curr = new RideData;
    cout<<"Enter Rider Name: ";
    cin>>curr->riderName;
    
    cout<<"Enter number Rides: ";
    cin>>curr->numberOfRides;

    cout<<"Enter Charges: ";
    cin>>curr->charges;

    cout<<"Enter distance Travelled: ";
    cin>>curr->distanceTravelled;

    if (node_Pointer->firstOfRide == NULL)
    {
        node_Pointer->firstOfRide = node_Pointer->lastOfRide = curr;
    }
    else
    {
        node_Pointer->lastOfRide->next = curr;
        node_Pointer->lastOfRide = curr;
    }
}

void displayRideData(CarData *node_Pointer)
{
    RideData *p = node_Pointer->firstOfRide;
    while (p != NULL)
    {
        cout<<"\nRider Name: "<<p->riderName<<endl;
        cout<<"Number of Rides Booked: "<<p->numberOfRides<<endl;
        cout<<"Charges: "<<p->charges<<endl;
        cout<<"Distance Travelled: "<<p->distanceTravelled<<"km"<<endl;

        p = p->next;
    }
}

int earningOfSpecificCar(CarData *node_Pointer)
{
    RideData *p = node_Pointer->firstOfRide;
    int sum = 0;
    while (p!=NULL)
    {
        sum +=p->charges;
        p = p->next;
    }
    cout<<"Total Earning of Car "<<node_Pointer->carName<<": "<<sum<<endl;
    return sum;
}
void displayEarningAllCars()
{
    CarData *k = firstOfCar;
    int sum = 0;
    while (k != NULL)
    {   
        sum += earningOfSpecificCar(k);
        k = k->next;
    }
    cout<<"Total Earning of All Cars: "<<sum<<endl;
}
CarData* node_Finder()
{
    cout<<"Enter Car Name to find its Ride Details: ";
    string key; cin>>key;   
    CarData *p = firstOfCar;
    if (firstOfCar->carName == key)
    {
        return firstOfCar;
    }
    else if (lastOfCar->carName == key)
    {
        return lastOfCar;
    }
    else
    {
        while (p != NULL)
        {
            if(p->carName == key)
            {
                return p;
            }
        }
    }
    return NULL;
}
void opt()
{
    cout<<"\n1- Register New Car"<<endl<<
          "2- Display Details Of All Registered Cars"<<endl<<
          "3- Display type-2 Cars"<<endl<<
          "4- Add new Ride"<<endl<<
          "5- Display Rides with Detail"<<endl<<
          "6- Total Earning of Specific Car"<<endl<<
          "7- Display Earning of all Car"<<endl<<
          "0- To Terminate the Process"<<endl;

    cout<<"Enter your desired Choice: ";
    int choice; cin>>choice;
    
    //declaring pointer to assign return value
    // of node_finder method
    CarData *pointer; 

    switch (choice)
    {
    case 1:
        cout<<"\nRegister New Car METHOD"<<endl;
        registerNewCar(); opt(); break;
    
    case 2:
        cout<<"\nDisplay of All Registered Cars METHOD"<<endl;
        displayCarData(); opt(); break;

    case 3:
        cout<<"\nDisplay of Type-2 Cars METHOD"<<endl;
        displayType2Cars(); opt(); break;

    case 4:
        cout<<"\nAdd neww Ride METHOD"<<endl;
        pointer = node_Finder();
        if (pointer != NULL)
        {
            addNewRide(pointer); opt();
        }
        else
        {
            cout<<"Data Not Found of Car"<<endl; opt(); 
        }
        break;
    case 5:
        cout<<"\nDisplay Rides with detail METHOD"<<endl;
        pointer = node_Finder();
        if (pointer != NULL)
        {
            displayRideData(pointer); opt();
        }
        else
        {
            cout<<"Data Not Found of Car"<<endl; opt();
        } 
        break;

    case 6:
        cout<<"\nTotal Earning of Specific Car METHOD"<<endl;
        pointer = node_Finder();
        if (pointer != NULL)
        {
            earningOfSpecificCar(pointer); opt();
        }
        else
        {
            cout<<"Data Not Found of Car"<<endl; opt();
        } 
        break;

    case 7:
        cout<<"\nDiplay Earning of All Cars METHOD"<<endl;
        displayEarningAllCars(); opt(); break;

    case 0:
        cout<<"\nProcess Terminated Successfully"<<endl; break;

    default:
        cout<<"\nInValid Choice Entered TRY AGAIN!!"<<endl;
        opt(); break;
    }
}

int main()
{
    opt();
    return 0;
}
