#include <iostream>
#define MAX_QUEUE 5
#define MAX_SPECIALIZATION 20
using namespace std;

struct hospital_queue{
    string names[MAX_QUEUE];
    int status[MAX_QUEUE];
    int len;
    int spec;

    hospital_queue(){
        len = 0;
        spec = -1;
    }

    hospital_queue(int _spec)
    {
        len = 0;
        spec = _spec;
    }

    bool add_end(string name, int stat)
    {
        if(len == MAX_QUEUE)
            return false;
        
        names[len] = name;
        status[len++] = stat;
        return true;
    }

    bool add_front(string name, int stat)
    {
        if(len == MAX_QUEUE)
            return false;

        for(int i = len - 1; i >= 0; --i)
        {
            names[i + 1] = names[i];
            status[i + 1] = status[i];
        }

        names[0] = name;
        status[0] = stat;
        ++len;
        return true;
    }

    void remove_front()
    {
        if(len == 0)
            cout<<"No patients at the moment . Have rest, Dr\n";
        
        else{
            cout<<names[0]<<" go with the Dr"<<"\n";

            for(int i = 1; i < len; ++i)
            {
                names[i - 1] = names[i];
                status[i - 1] = status[i];
            }
            --len;
        }
        
    }
    
    void print()
    {   
        for(int i = 0; i < len; ++i)
        {
            if(status[i])
                cout<<names[i]<<" urgent\n";
            else    
                cout<<names[i]<<" regular\n";
        }     
    }
};

void add_patients(hospital_queue q[])
{
    cout<<"Enter specialization, name and status: ";
    int spec, status;
    string name;
    cin>>spec>>name>>status;

    bool result;

    if(status)
        result = q[spec - 1].add_front(name, status);

    else 
        result = q[spec - 1].add_end(name, status);

    if(!result)
        cout<<"Sorry we cant add more patients for this specialization\n";
    else
        cout<<"Patient added successfulyy!\n";
}

void print_patients(hospital_queue q[])
{
    for(int i = 0; i < MAX_SPECIALIZATION; ++i)
    {
        if(q[i].len)
        {
            cout<<"There are "<<q[i].len<<" patients in specialization "<<i + 1<<"\n";

            q[i].print();
        }
    }
}

void get_nextPatient(hospital_queue q[])
{
    cout<<"Enter specialization: ";
    int spec;
    cin>>spec;

    q[spec - 1].remove_front();
}


int main()
{
    hospital_queue queues[MAX_SPECIALIZATION];
    
    // initialising spec for particular index of the queues array
    for(int i = 0; i < MAX_SPECIALIZATION; ++i)
        queues[i] = hospital_queue(i);
    
    cout<<"\t\tHOSPITAL SYSTEM V2\n";
    // menu 
    while(true)
    {
        cout<<"\n 1. Add a new Patient\n 2. Print all patients\n 3. Get next Patient\n 4. Exit\n\n Choose an option: ";
        int option;
        cin>>option;

        switch(option)
        {
            case 1: add_patients(queues);
            break;

            case 2: print_patients(queues);
            break;

            case 3: get_nextPatient(queues);
            break;

            case 4: return 0;

            default: cout<<"Invalid option, try again";
        }
        cout<<"\n";
    }
    return 0;
}