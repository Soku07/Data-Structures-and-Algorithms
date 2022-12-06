#include<iostream>
#include<string.h>
using namespace std;
typedef struct Node
{
    char data;
    int weight;
    Node* next;
    Node* back;
};
static char operator_precedence[] = {'-', '+', '/', '*', '^'};
static int index;
static int* address = &index;
int Search(char key)  //returns -2 if the key is not an operator 
{
    for(int i = 0; i<4;i++)
    {
        if(operator_precedence[i] == key)
        {
            *address = i;
            return i;
        }
       
    }
    return -2;
}
class stack_sll 
{
    private:
    Node* Head;
    
    public:
    Node* Top;//Node* prev_top;.
    stack_sll();
    ~stack_sll();
    void push(char c, int* i);
    void pop();
    void Display();
    bool isempty();
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
void stack_sll :: push(char c, int* i)
{   
    Node* T;
    if(Head == NULL)
    {
        T = new(Node);
        Head = T;
        T->data = c;
        T->weight = *i;
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
        T->data = c;
        T->weight = *i;
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
bool stack_sll :: isempty()
{
    if(Head == NULL)
    {
        return true;
    }
    return false;
}

// using namespace std;
int main()
{   
    string infix_exp;
    cout<<"Enter the infix expression :: "<<endl;
    getline(cin, infix_exp);
    string str;stack_sll op_stack;int b = -1;int* brace = &b;
    // int post = 0;
    for(int i = infix_exp.length() - 1; i >= 0 ;i--)
    {
        if(Search(infix_exp[i]) != -2 || infix_exp[i] == '('|| infix_exp[i] == ')')
        {
            if(op_stack.isempty())
            {
                op_stack.push(infix_exp[i], address);
                // op_stack.Display();
            }
            else
            {
                if(infix_exp[i] == ')')
                {   
                     
                    op_stack.push(infix_exp[i], brace);
                    // op_stack.Display();
                }
                else if(op_stack.Top->weight < index)
                {
                    op_stack.push(infix_exp[i], address);
                    // op_stack.Display();
                }
                else if(infix_exp[i] == '(')
                {   
                   
                   while(op_stack.Top->data != '(')
                   {
                       str += op_stack.Top->data;
                       
                       op_stack.pop();
                    //    op_stack.Display();
                   } 
                   op_stack.pop();
                //    op_stack.Display();
                }
                else
                {
                    while(op_stack.Top->data != '(' && op_stack.isempty() == false)
                    {
                        str += op_stack.Top->data;
                        
                        op_stack.pop();
                        // op_stack.Display();
                    }
                    op_stack.push(infix_exp[i], address);
                    // op_stack.Display();
                }
            }
        }
        else
        {
            str += infix_exp[i];
            
        }
    }
    while(op_stack.isempty() == false)
    {   if(op_stack.Top->data != '(' || op_stack.Top->data != ')' )
        {   str += op_stack.Top->data;
            op_stack.pop();
           
        }
        else
        {
            
        
           op_stack.pop();
        }
    }
    cout<<"Enterred infix expression ::\t "<<infix_exp<<endl;
    infix_exp = "";
    for(int k = str.length()-1;k>=0;k--)
    {
        infix_exp += str[k];
    }
    cout<<"prefix form of the enterred exp ::\t "<<infix_exp<<endl;
    op_stack.~stack_sll();
    return 0;
}