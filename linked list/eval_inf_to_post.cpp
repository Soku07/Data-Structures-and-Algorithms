#include<iostream>
#include<string.h>
using namespace std;
typedef struct Node
{
    float data;
    Node* next;
    Node* back;
};

class stack_sll 
{
    private:
    Node* Head;//Node* prev_top;
    public:
    Node* Top;
    stack_sll();
    ~stack_sll();
    void push(float);
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
void stack_sll :: push(float n)
{   
    Node* T;
    if(Head == NULL)
    {
        T = new(Node);
        Head = T;
        T->data = n;
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
        T->data = n;
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

float operation(float num1, float num2, char op)
{   
    // cout<<op<<endl;
    if(op == '^')
    {
        float r = 1 ;
        for(int i = 0; i<int(num1);i++)
        {
            r *= num2;
        }
        return int(r);
    }

    else if(op == '*')
    {   
        // cout<<"Multiplying :: "<<endl;
        return num2 * num1;
    }
    else if(op == '/')
    {   
        // cout<<"Dividing :: "<<endl;
        return num2 / num1;
    }
    else if(op == '-')
    {   
        // cout<<"Subtracting :: "<<endl;
        return num2 - num1;
    }
    else if(op == '+')
    {   
        // cout<<"Adding :: "<<endl;
        return num2 + num1;
    }
}
static float operator_precedence[] = {'-', '+', '/', '*', '^'}; 
bool isoperator(char key)  //returns false if the key is not an operator 
{
    for(int i = 0; i<5;i++)
    {   
        if(key == ' ')
        {
            return false;
        }
        else if(operator_precedence[i] == key)
        {
            return true;
        }
       
    }
    return false;
}
int main()
{   
    string postfix_exp;stack_sll operand_stack;string str = "";
    cout<<"-----------------------IMPORTANT------------------------------------"<<endl;
    cout<<"|Rules :: ********USE A SPACE AFTER EVERY DISTINCT ENTITY******\n|eg :: 13 11 789 * + 78 -\n|(do not use a space after last character of your postfix expression!!!)"<<endl;
    cout<<"-----------------------IMPORTANT------------------------------------"<<endl;
    cout<<"Enter postfix expression :: "<<endl;
    getline(cin, postfix_exp);
    float r; int i = 0;int c = postfix_exp.length();float n1;float n2;
    while (i < c)
    {
        if(!isoperator(postfix_exp[i]))
        {
            if(postfix_exp[i] == ' ')
            {   
                // cout<<"str is :: \t "<<str<<endl;
                r = stof(str);
                operand_stack.push(r);
                str = "";
                i += 1;
                // cout<<"Postfix["<<i<<"] :: \t"<<postfix_exp[i]<<endl;
            }
            else
            {
                str += postfix_exp[i];
                i += 1;
            }

        }
        else
        {
            n1 = operand_stack.Top->data;
            operand_stack.pop();
            n2 = operand_stack.Top->data;
            operand_stack.pop();
            r = operation(n1,n2,postfix_exp[i]);
            // cout<<n1<<postfix_exp[i]<<n2<<" = "<<r<<endl;
            operand_stack.push(r);
            i += 2;
        }
    }
    cout<<"**************************OUTPUT**************************"<<endl;
    cout<<"Enterred Postfix expression :: "<<postfix_exp<<endl;
    cout<<"Result :: "<<operand_stack.Top->data<<endl;
    cout<<"**************************OUTPUT**************************"<<endl;
    operand_stack.pop();
    operand_stack.~stack_sll();
    return 0;
}