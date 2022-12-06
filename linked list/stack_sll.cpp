#include<iostream>

using namespace std;
typedef struct Node
{
    int data;
    Node* next;
    Node* back;
};

class stack_sll 
{
    private:
    Node* Head;Node* Top;//Node* prev_top;
    public:
    stack_sll();
    ~stack_sll();
    void push();
    void pop();
    void Display();
};
stack_sll :: stack_sll()
{
    Head = NULL;
    //prev_top = NULL;
    Top = NULL;

}
stack_sll :: ~stack_sll()
{
    Node* T;Node* N;
    T = Head;
    do
    {   N = T->next;
        delete T;
    } while (T->next == NULL);
    delete N;
}
void stack_sll :: push()
{   
    Node* T;
    if(Head == NULL)
    {
        T = new(Node);
        Head = T;
        cout<<"Enter data :: "<<endl;
        cin>>T->data;
        T->next = NULL;
        T->back = NULL;
        Top = T;
    }
    else
    {
        T = new(Node);
        Top->next = T;
        T->next = NULL;
        T->back = Top;
        cout<<"Enter data :: "<<endl;
        cin>>T->data;
        // prev_top = Top;
        Top = T;
    }
}

void stack_sll :: pop()
{   
    Node* T;
    if(Top->back != NULL)
    {
    T = Top;
    Top = T->back;
    Top->next = NULL;
    delete T;
    }
    else
    {
        delete Top;
        Head = NULL;
        // cout<<"Popped out the very first element. Now linked list is empty!!"<<endl;
    }
}
void stack_sll :: Display()
{
    Node* T;
    T = Head;
    cout<<"*************************************************"<<endl;
    if(T != NULL)
    {
    
    do
    {
        cout<<"Data :: "<<T->data<<endl;;
        T = T->next;
    } while (T != NULL);
    // cout<<"Top is "<<Top->data<<endl;
    }
    else{
        cout<<"Stack is empty."<<endl;
    }
    cout<<"*************************************************"<<endl;
}

int main()
{   
   stack_sll cool_stack;
   int choice;
   do
   {
       cout<<"Enter :: 0. End\t1. Push\t2. Pop\t3. Display "<<endl;
       cin>>choice;
       switch (choice)
       {
       case 0:cool_stack.~stack_sll();
           break;
       case 1:  cool_stack.push();
                break;
        case 2: cool_stack.pop();
                break;
        case 3: cool_stack.Display();
                break;
       default:
           break;
       }
       
   } while (choice != 0);
    
    return 0;
}