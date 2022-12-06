#include<iostream>
using namespace std;
struct patient{
    char name[20];
    int age;
};

class Queue
{   private:
    struct patient p[10];
    int  front, rear;
    public:
    void enqueue();
    void dequeue();
    bool isfull();
    bool isempty();
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void Display()
     {   int i = rear + 1;
      
        
        while(i <= front) 
        {
            cout<<"Patient ["<<i +1<<"] \t name = "<<p[i].name<<"\t\t age = "<<p[i].age<<"\ti  = "<<i<<"\t del end = "<<rear<<"\tinsertion end = "<<front<<endl;
            i += 1;
        }
    }
};

bool Queue :: isfull()
{
    if(front == 9)
    {
        return true;
    }
    return false;
}

bool Queue :: isempty()
{
    if(front == rear)
    {
        return true;
    }
    return false;
}

void Queue :: enqueue()
{
    if(!isfull())
    {   struct patient temp;
        front += 1;
        cout<<"Enter the element to add -\nEnter patient name -  ";
        cin>>temp.name;
        cout<<"Enter patient age - ";
        cin>>temp.age;
        p[front] = temp;
        cout<<"Displaying array after addition of element - "<<endl;
        Display();
    }
    else{
        cout<<"Size limit of database is 10. No more entries allowed!"<<endl;
    }
}
void Queue :: dequeue()
{
    if(!isempty()){
        rear += 1;
        Display();
    }
    else
    {
        cout<<"queue is empty"<<endl;
    }

}
int main()
{
    Queue qclass;
    int choice = -1;
    while(true)
  {
    cout<<"Operations - \n 0)end\t1)Enqueue\t2)Dequeue : ";
    cin>>choice;
    if(choice == 0)
    {
        break;
    }
    switch(choice)
    {
        case 1:
        qclass.enqueue();
        break;  
        case 2:
        qclass.dequeue();
        break;
    }
      
  }
     return 0;
}