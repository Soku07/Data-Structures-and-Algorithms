#include<iostream>
#include "structure.h"
using namespace std;

class stack_sll
{
    public:
    Node* Top;
    stack_sll();
    void push(Tree_Node*);
    void pop();
    void Display();
};

stack_sll :: stack_sll()
{
    Top = NULL;
}

void stack_sll :: push(Tree_Node* T)
{
    Node* N;
    N = new(Node);
    N->next = Top;
    N->data = T;
    Top = N;
}

void stack_sll :: pop()
{   Node* N = Top;
    if(Top != NULL)
    {
    Top = Top->next;
    }
    else
    {
        Top = NULL;
    }
    delete N;
}

void stack_sll :: Display()
{   
    Node* T = Top;
    cout<<"Displaying stack from the top :: "<<endl;
    while(T != NULL)
    {
        cout<<T->data<<endl;
        T = T->next;
    }
}