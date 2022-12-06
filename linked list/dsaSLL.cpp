// singly linked list

#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
}Node;

class SLL{
    Node *HEAD;
public:
    SLL();
    //~SLL();
void create();
void display();
};

SLL::SLL()
{
    HEAD = NULL;
}
void SLL::create()
{
    int i;
    Node *T, *P;
    T = new(Node);
    cout<<"Enter new value: ";
    cin>> T->data;
    T->next = NULL;
    HEAD = T;
    
    for (i=0;i<2;i++)
    {
        P = new(Node);
        cout<<"Enter new value: ";
        cin>>P->data;
        P->next = NULL;
        T->next = P;
        T=P;
    }

}
void SLL::display(){
    Node *Temp;
    Temp = HEAD;
    while(Temp!=NULL)
    {
        cout<<"Value "<<Temp->data<<"\t";
        Temp = Temp->next;
    }
}

int main()
{
    SLL L1;
    L1.create();
    L1.display();
    return 0;
}