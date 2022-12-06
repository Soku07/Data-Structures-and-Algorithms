#include<iostream>
#include "structure.h"
using namespace std;
class stack_sll 
{
    private:
    Node* Head;//Node* prev_top;
    public:
    Node* Top;
    stack_sll();
    ~stack_sll();
    void push(Tree_Node*);
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
void stack_sll :: push(Tree_Node* address)
{   
    Node* T;
    if(Head == NULL)
    {
        T = new(Node);
        Head = T;
        T->data = address;
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
        T->data = address;
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
        Top = NULL;
        // cout<<"Popped out the very first element. Now linked list is empty!!"<<endl;
    }
}