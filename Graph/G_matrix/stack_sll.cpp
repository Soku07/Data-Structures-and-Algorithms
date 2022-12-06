#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* next;
};
class stack_sll
{
    public:
    Node* Top;
    stack_sll();
    void push(int);
    void pop();
    void Display();
    // ~stack_sll();
};

stack_sll :: stack_sll()
{
    Top = NULL;
}
// stack_sll :: ~stack_sll()
// {
//     Node* Temp = Top,*N;
//     while(Top->next != NULL)
//     {   
//         N = Temp;
//         Top = Temp->next;
//         free(N);
//     }
//     free(Temp);
// }
void stack_sll :: push(int T)
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
    while(T != NULL)
    {
        cout<<T->data<<"->";
        T = T->next;
        pop();
    }
}
