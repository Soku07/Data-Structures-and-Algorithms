#include<iostream>
#include<string.h>
using namespace std;
typedef struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    bool Lthread;
    bool Rthread;
};

class TBT
{   private:
    TreeNode* Head,*Root; 
    TreeNode* MakeNode();
    public:
    TBT();
    void AddNode();
    void Inorder();
    void Preorder();
};

TreeNode* TBT :: MakeNode() 
{
    TreeNode* T = new(TreeNode);
    T->left = NULL;T->right = NULL;
    T->Lthread = true;T->Rthread = true;
    cout<<"Enter Data :: "<<endl;
    cin>>T->data;
    return T;
}
TBT :: TBT()
{
    Root = NULL;
    Head = new(TreeNode);
    Head->left = Head;Head->right = Head;
    Head->Lthread = true; Head->Rthread = true;
    Head->data = '$';
}
void TBT :: AddNode()
{   
    TreeNode* Temp,*Parent = Root;
    if(Root == NULL)
    {
        Root = MakeNode();
        Root->left = Head;
        Root->right = Head;
        Head->left = Root;
        Head->Lthread = false;
        cout<<"Root "<<Root->data<<"is created succesfully!"<<endl;
    }
    else
    {   int choice;
        while(true)
        {   cout<<"Currently at "<<Parent->data<<endl;
            cout<<"0.Cancel\t1.Add to left\t2.Add to right"<<endl;
            cin>>choice;
            if(choice == 0)
            {
                break;
            }
            else if(choice == 1) // left
            {
                if(Parent->Lthread == true)
                {
                    Temp = MakeNode();
                    Temp->left = Parent->left;
                    Temp->right = Parent;
                    Parent->left = Temp;
                    Parent->Lthread = false;
                    cout<<"Node "<<Temp->data<<" is succesfully added to the left of "<<Parent->data<<endl;
                    break;
                }
                else
                {
                    Parent = Parent->left;
                }
            }
            else if(choice == 2)
            {
                if(Parent->Rthread == true)
                {
                    Temp = MakeNode();
                    Temp->right = Parent->right;
                    Temp->left = Parent;
                    Parent->right = Temp;
                    Parent->Rthread = false;
                    cout<<"Node "<<Temp->data<<" is succesfully added to the right of "<<Parent->data<<endl;
                    break;
                }
                else
                {
                    Parent = Parent->right;
                }
            }
        }
    }
}

void TBT :: Inorder()
{
    TreeNode* Temp = Root;
    if(Root == NULL)
    {
        cout<<"EMPTY TREE"<<endl;
    }
    else
    {
        while(Temp->Lthread != true)
        {
            Temp = Temp->left;
        }

        while(Temp != Head)
        {
            cout<<Temp->data<<"\t";
            if(Temp->Rthread == true)
            {   
                Temp = Temp->right;
                // cout<<Temp->data<<"\t";
            }
            else
            {
                Temp = Temp->right;// reached c
                while(Temp->Lthread != true)
                {
                    Temp = Temp->left;
                }
            }
        }
    }
}

void TBT :: Preorder()
{
    TreeNode * Temp = Root;
    if(Root == NULL)
    {
        cout<<"EMPTY TREE!!"<<endl;
    }
    else
    {
        while(Temp->Lthread != true)
        {
            cout<<Temp->data<<"\t";
            Temp = Temp->left;
        }
        cout<<Temp->data<<"\t";
        while(Temp->right != Head)
        {
            if(Temp->Rthread == true)
            {
                Temp = Temp->right;
                Temp = Temp->right;
                // cout<<Temp->data<<"\t";
            }
            else
            {   
                Temp = Temp->left;
                while(Temp->Lthread != true)
                {
                    Temp = Temp->left;
                    cout<<Temp->data<<"\t";
                }
            }
            cout<<Temp->data<<"\t";
        }
    }
}