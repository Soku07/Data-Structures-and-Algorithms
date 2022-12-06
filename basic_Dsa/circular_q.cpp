#include <iostream>
using namespace std;
struct patient
{
    string name;
    int age;
    int id;
};
class Cir_q
{
    private:
    struct patient p[5];
    int f,r;
    
    public:
    bool empty;
    Cir_q();
    void enque();
    void deque();
    void display();
    bool isfull();
};
Cir_q :: Cir_q()
{
    empty = true;
    f = -1;
    r = -1;
}
bool Cir_q :: isfull()
{
    if((r+1)%5 == f && empty == false)
    {
        return true;
    }
    return false;
}
void Cir_q :: enque()
{
    if(!isfull())
    {
        if(empty == true)
        {   
            // cout<<"Empty changed to false bcoz we are adding the element"<<endl;
            empty = false;
        }
        if(f == -1 && r == -1)
        {
            f = 0;
        }
        r = (r+1)%5;
        cout<<"Enter patient details ::"<<endl;
        cout<<"Enter name :: ";
        cin>>p[r].name;
        cout<<"\nEnter age :: ";
        cin>>p[r].age;
        cout<<"\nEnter patient id :: ";
        cin>>p[r].id;

        cout<<"Following entry is added in the queue :: "<<endl;
        cout<<"Name :: "<<p[r].name<<"\tAge :: "<<p[r].age<<"\tId :: "<<p[r].id<<endl;
}
else
{
    cout<<"Queue is full!!";
}
}

void Cir_q :: deque()
{   
    // cout<<"empty = "<<empty;
    if(empty == false)
    {   if(f == r)
        {
            empty = true;
        }
        cout<<"Deleting \n"<<"Name :: "<<p[f].name<<"\tAge :: "<<p[f].age<<"Id :: "<<p[f].id<<endl;
        f = (f+1)%5;
    }
    else{
        cout<<"Queue is empty!!"<<endl;
    }
}
void Cir_q :: display()
{   

    
    if(empty == true)
    {
        cout<<"Nothing to display!! "<<endl;
    }
    else{
    int i = f;
    cout<<"*******************************************"<<endl;
    cout<<"f = "<<f<<"\tr = "<<r<<endl;
    cout<<"Displaying patient database :: \n(from f = "<<f<<"to r = "<<r<<endl;

    while(i<=r)
    { 
        cout<<"Name :: "<<p[i].name<<"\tAge :: "<<p[i].age<<"Id :: "<<p[i].id<<endl;
          if(i == r)
        {
            break;
        }
        i = (i+1)%5;
    }
    cout<<"*******************************************"<<endl;
    }
}

int main()
{   
    int choice;
    Cir_q qclass;
    // cout<<"empty = "<<qclass.empty<<endl;
    do
    {
        cout<<"Enter :: 0. End\t1. Enque\t2.Deque\t3.Display :: ";  
        cin>>choice;
        switch(choice)
        {
            case 0:break;
            case 1:
                    // cout<<"empty = "<<qclass.empty<<endl;
                    qclass.enque();
                    break;
            case 2:
                    // cout<<"empty = "<<qclass.empty<<endl;
                    qclass.deque();

                    break;
            case 3:qclass.display();
                    break;
        }
    } while (choice!=0);
    
    return 0;
}