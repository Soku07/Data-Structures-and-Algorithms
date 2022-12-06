// Name :: Soham Kulkarni
// Rno  :: 23145

#include<iostream>
using namespace std;
typedef struct Tree_Node
{
    int data;
    Tree_Node* left;
    Tree_Node* right;
};
typedef struct Node
{
    Tree_Node* data;
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
class Bin_Tree 
{
    private:
    Tree_Node* Root;
    Tree_Node* MakeNode();// Creates a leaf Node.
    public:
    Bin_Tree();
    void AddNode();
    void Pre_order();
};
Bin_Tree :: Bin_Tree()
{
    Root = NULL;
}
Tree_Node* Bin_Tree :: MakeNode()
{
    Tree_Node* T;
    T = new(Tree_Node);
    T->left = NULL;
    T->right = NULL;
    cout<<"Enter data :: "<<endl;
    cin>>T->data;
    return T;
}
void Bin_Tree :: AddNode()
{   
    Tree_Node* T = Root;
    if(T != NULL)
    {   
        int choice;
        do
        {
            cout<<"Enter :: 1.Add Node at left\t2.Add node at right"<<endl;
            cin>>choice;
            if(choice == 1) // add to left
            {
                if(T->left == NULL)
                {
                    T->left = MakeNode();
                    break;
                }
                else
                {
                    T = T->left;
                }

            }
            else
            {
                if(T->right == NULL)
                {
                    T->right = MakeNode();
                    break;
                }
                else
                {
                    T = T->right;

                }
            }
        } while (true);
        
    }
    else
    {
        Root = MakeNode();
        
    }
}
void Bin_Tree ::Pre_order()
{
    Tree_Node* temp;stack_sll pointer_stack;
    if(Root == NULL)
    {
        cout<<"Empty Tree"<<endl;
    }
    else
    {   
        temp = Root;
        do
        {
            
            while (temp != NULL)
            {
                cout<<temp->data<<"\t";
                if(temp->right != NULL)
                {
                pointer_stack.push(temp->right);
                // pointer_stack.Display();
                }
                temp = temp->left;
              
            }
            if(pointer_stack.Top != NULL)
             {   
                temp = pointer_stack.Top->data;
                pointer_stack.pop();
            }
            
        } while (temp != NULL || pointer_stack.Top != NULL);
        
    }
}
int main()
{
    Bin_Tree sweet_tree;int choice;
    
    do
    {   
        cout<<"Enter :: 0.End\t1.AddNode\t2.Display Tree (PREORDER)"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0: break;
            case 1: sweet_tree.AddNode();
                    break;
            case 2: sweet_tree.Pre_order();
                    break;
            default: break;
        }
    } while (choice != 0);
    return 0;
}