#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* next;
};

class sll
{   private:
    Node* Head;Node* curr;
    public:
    sll();
    ~sll();
    void Add_Node();
    void Add_inbw_Node();
    void Display();
    void del_node();
};

sll :: sll()
{
    Head = NULL;
}
sll :: ~sll()
{
    Node* T;Node* N;
    T = Head;
    do
    {   N = T->next;
        delete T;
    } while (T->next == NULL);
    delete N;
}
void sll :: Add_Node()
{   
    Node* T;//static Node* curr; // curr is the latest node added. It is helpfull to add the node at the end of the list , instead of traverisng the list again and agin
    
    if(Head == NULL)
    {
    T = new(Node);
    cout<<"Enter a Num - "<<endl;
    cin>>T->data;
    Head = T;
    T->next = NULL;
    curr = T;
    // cout<<"Adress of first node is "<<Top<<endl;
    // cout<<"Curr.data - "<<Top->data<<"\tcurr.next = "<<Top->next<<endl;
    }
    else
    {
        T = new(Node);
        cout<<"Enter a Num - "<<endl;
        cin>>T->data;
        T->next = NULL;
        // cout<<"Next pointer of this new node is = "<<T->next<<endl;
        // cout<<"Curr.data - "<<curr->data<<"\tcurr.next = "<<curr->next<<endl;
        curr->next = T; // Adding address of this new node in the "next" pointer of previous element which was then current.
        curr = T;       // now , address of this new node will be stored in the current.
    }
    cout<<"Current is - "<<curr->data<<"\tAdress stored in curr pointer is "<<curr<<"\t Address in the node is "<<curr->next<<endl;

}

void sll :: Display()
{
    Node* Temp;
    Temp = Head;
    cout<<"Displaying the linked list - "<<endl;
    while(Temp!= NULL)
    {
        cout<<"data :: "<<Temp->data<<endl;
        Temp = Temp->next;
    }
}

int main()
{
    sll l1;
    int choice;
    do
    {
        cout<<"Enter :: 0. End \t 1. Add node\t2.Display"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0: l1.~sll();
                break;
        case 1: l1.Add_Node();
            break;
        case 2: l1.Display();
            break;
        
        default:
            break;
        }
    } while (choice != 0);
    return 0;
    
}