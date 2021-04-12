#include <iostream>
#define LIMIT_SPECIAL 5
#define MAX_PATIENTS 100
#define TOTAL_SPECIAL 20
using namespace std;

int freq_specialization[TOTAL_SPECIAL + 1];
string names[MAX_PATIENTS];
string status[MAX_PATIENTS];    // status: 0 for regular and 1 for urgent


void insert_at_beginning(int special, string name)
{   
    int start_idx = (special - 1) * LIMIT_SPECIAL;

    // queue_idx gives us the index in which the position is empty in the actual specialization array
    int queue_idx  =  start_idx + freq_specialization[special] - 1;

    // shift one to the left
    for(int i = queue_idx; i >= start_idx; --i)
    {
        names[i + 1] = names[i];
        status[i + 1] = status[i];
    }
    
    // adding record
    names[start_idx] = name;
    status[start_idx] = "urgent";
}

void insert_at_end(int special, string name)
{
    int start_idx = (special - 1)*LIMIT_SPECIAL;

    // queue_idx gives us the index in which the position is empty in the actual specialization array
    int queue_idx  =  start_idx + freq_specialization[special] - 1;

    // adding record
    names[queue_idx + 1] = name;  
   status[queue_idx + 1] = "regular";
 }

void add_newPatient()
{
    int special, status;
    string name;
    int stat;

    cout<<"Enter Specialization, Name and Status: ";
    cin>>special>>name>>stat;

    // if specialization count exceeds 5, then dont accept patients;
    if(freq_specialization[special] == LIMIT_SPECIAL)
    {
        cout<<"Sorry we cant add more patients for this specialization";
        return;
    }

    /*
        if(status == 1) insert_at_beginning of the queue
        else insert_normally
    */
    if(status)
        insert_at_beginning(special, name);
    else insert_at_end(special, name);

    ++freq_specialization[special];
}

void print_patients()
{
    for(int i = 1; i <= TOTAL_SPECIAL; ++i)
    {
        if(freq_specialization[i])
        {
            cout<<"There are "<<freq_specialization[i]<<" patients in specialization "<<i<<"\n";
            
            // printing the patients in this specialization
            int start_idx = (i - 1) * LIMIT_SPECIAL;
            int queue_idx  =  start_idx + freq_specialization[i] - 1;

            for(int j = start_idx; j <= queue_idx; ++j)   
                cout<<names[j]<<" "<<status[i]<<"\n"; 
        }
    }
}

void get_nextPatient()
{
    int special;
    cout<<"Enter specialization: ";
    cin>>special;

    if(freq_specialization[special])
    {
        int start_idx = (special - 1) * LIMIT_SPECIAL;
        int queue_idx  =  start_idx + freq_specialization[special] - 1;

        cout<<names[queue_idx]<<" go with the Dr";
    }
    else cout<<"No patients at the moment. Have rest Dr";
}

int main()
{

}