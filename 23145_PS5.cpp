//Name :: Soham Kulkarni
//Rno  :: 23145
//Problem stmt :: Create expression tree and perform recursive and nonrecursive preorder traversal
#include<iostream>
#include<string.h>
using namespace std;

typedef struct Tree_Node // Data structure for Tree Node
{ 
    char data;
    Tree_Node* left;
    Tree_Node* right;
};
typedef struct Node // Data structure for Node required for singly linked list
{
    Tree_Node* data;
    Node* next;

};
class stack_sll
{
    public:
    Node* Top; 
    stack_sll();
    void push(Tree_Node*);
    void pop();
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

class BinTree
{
    private:
    Tree_Node* Root;
    public:
    BinTree()
    {
        Root = NULL;
    }
    Tree_Node* MakeNode(char x)
    {
        Tree_Node* Temp = new(Tree_Node);
        Temp->data = x;
        Temp->left = NULL;
        Temp->right = NULL;
        return Temp;
    }
    void ChangeRoot(Tree_Node* address)
    {
        Root = address;
    }
    void Preorder_Recur(Tree_Node* root)
    {
        if(root != NULL)
        {
            cout<<root->data<<"\t";
            Preorder_Recur(root->left);
            Preorder_Recur(root->right);
        }
    }
    void Preorder_NonRecur()
    {
        Tree_Node* Temp = Root;stack_sll pointer_stack;
        do
        {
            while(Temp != NULL)
            {
                cout<<Temp->data<<"\t";
                if(Temp ->right != NULL)
                {
                    pointer_stack.push(Temp->right);
                }
                Temp = Temp->left;
            }
            if(pointer_stack.Top != NULL)
            {
                Temp = pointer_stack.Top->data;
                pointer_stack.pop();
            }        
        }while(Temp != NULL || pointer_stack.Top != NULL);  
        cout<<endl;      
    }
};
bool isoperator(char x)
{
    if(x == '^' || x == '*' || x == '/' || x == '-' || x == '+')
    {
        return true;
    }
    return false;
}
int main()
{   
    stack_sll Treestack; BinTree exp_tree;Tree_Node* Temp;
    string postfix_exp;int choice;
    cout<<"Enter Postfix exp :: "<<endl;
    getline(cin, postfix_exp);
    int l = postfix_exp.length();
    for(int i = 0; i<l;i++)
    {   
        Temp = exp_tree.MakeNode(postfix_exp[i]);
        if(isoperator(postfix_exp[i]))
        {
            Temp->right = Treestack.Top->data;
            Treestack.pop();
            Temp->left = Treestack.Top->data;
            Treestack.pop();
            Treestack.push(Temp);
        }
        else
        {
            Treestack.push(Temp);
        }

    }
    exp_tree.ChangeRoot(Treestack.Top->data);
    // Treestack.pop();
    cout<<"Recursive Preorder Traversal :: "<<endl;
    exp_tree.Preorder_Recur(Treestack.Top->data);
    cout<<endl;
     cout<<" Non Recursive Preorder Traversal :: "<<endl;
    exp_tree.Preorder_NonRecur();
    cout<<"End of prg"<<endl;
    return 0;
}

//Output :: 
// Enter Postfix exp :: 
//abc-*ef+gh-/+
//Recursive Preorder Traversal :: 
//+       *       a       -       b       c       /       +       e       f       -       g       h
// Non Recursive Preorder Traversal ::
//+       *       a       -       b       c       /       +       e       f       -       g       h
//End of prg

