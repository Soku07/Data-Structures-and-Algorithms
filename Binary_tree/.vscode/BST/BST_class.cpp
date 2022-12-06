#include <iostream>
#include "stack_sll.cpp"

using namespace std;
class BinST
{
    public:
    TreeNode* Root;
    TreeNode* MakeNode(int);

    BinST();
    TreeNode* Insert();
    void Inorder();
    TreeNode* Search();
    void Delete();
    int Height(TreeNode*);
    bool balanceF(TreeNode* T)
    {
        int f = Height(T->left) - Height(T->right);
        if(f>=-1 && f<=1)
        {
            return true;
        }
        return false;
    }
    void RotLeft(TreeNode*,TreeNode*);
    void ROTRight(TreeNode*, TreeNode*);
    void InsertAVL();
};

BinST :: BinST()
{
    Root = NULL;
}
TreeNode* BinST :: MakeNode(int x)
{
    TreeNode* T;
    T = new(TreeNode);
    T->left = NULL;
    T->right = NULL;
    T->data = x;
}

TreeNode* BinST :: Insert()
{
    TreeNode* T = Root;int x;
    cout<<"Enter Data :: "<<endl;
    cin>>x;
    if(Root == NULL)
    {
        Root = MakeNode(x);
        return Root;
    }
    else
    {
        while(true)
        {
            if(x > T->data)
            {
                if(T->right == NULL)
                {
                    T->right = MakeNode(x);
                    return T->right;
                    break;
                }
                else
                {
                    T = T->right;
                }
            }
            else if(x < T->data)
            {
                if(T->left == NULL)
                {
                    T->left = MakeNode(x);
                    return T->left;
                    break;
                }
                else
                {
                    T = T->left;
                }                
            }
            else
            {   
                cout<<"Duplication not allowed!"<<endl;
                break;
            }
        }

    }
}

void BinST ::Inorder()
{
    if(Root == NULL)
    {
        cout<<"EMPTY TREE!!"<<endl;
    }
    else
    {
        TreeNode* T = Root;
        stack_sll pointer_stack;
        do
        {
            while(T != NULL)
            {
                pointer_stack.push(T);
                T = T->left;
            }
            if(pointer_stack.Top != NULL)
            {
                T = pointer_stack.Top->data;
                pointer_stack.pop();
                cout<<T->data<<"\t";
                T = T->right;
            }
        } while (T != NULL || pointer_stack.Top != NULL);
        
    }
}
TreeNode* BinST :: Search()
{   
    int x;//,i = 1;
    TreeNode* Temp = Root;
    cout<<"Enter data to search :: "<<endl;
    cin>>x;

    while(Temp != NULL)
    {
    // cout<<"Inside while "<<i<<endl;
    if(Temp->data == x)
    {   
        cout<<"Node :: Data ->"<<" "<<x<<" is sucessfully found"<<endl;
        // cout<<"Inside equal case"<<i<<endl;
        break;
        return Temp;
    }
    else if(x > Temp->data)
    {   
        // cout<<"Inside greater case"<<i<<endl;
        Temp = Temp->right;
    }
    else if(x < Temp->data)
    {   
        // cout<<"Inside lesser case"<<i<<endl;
        Temp = Temp->left;
    }
    // i += 1;
    return NULL;
    }
    if(Temp == NULL)
    {
    cout<<"Node with Data -> "<<x<<" is not present in the tree."<<endl;
    }
}
void BinST :: Delete()
{   int x;
    cout<<"Enter data to be deleted from the tree :: "<<endl;
    cin>>x;
    TreeNode* Temp = Root, *Parent = NULL;
    while(Temp!=NULL && Temp->data != x)
    {
        Parent = Temp;
        if(x > Temp->data)
        {
            Temp = Temp->right;
        }
        else if(x < Temp->data)
        {
            Temp = Temp->left;
        }
    }
    if(Temp == NULL)
    {
        cout<<"Data does not exist!"<<endl;
    }
    else if(Temp->left == NULL && Temp->right == NULL)
    {   
        cout<<"Leaf identified"<<endl;
        // cout<<"My parent is "<<Parent->data<<endl;

        if(Temp == Root)
        {
            Root = NULL;
        }
        else if(Parent->left == Temp)
        {   
            cout<<"Left child confirmed"<<endl;
            Parent->left = NULL;
        }
        else
        {   
            cout<<"Right child confirmed"<<endl;
            Parent->right = NULL;
        }
        
        // cout<<"After free :: data in temp is "<<Temp->data;
    }
    else if(Temp->left == NULL || Temp->right == NULL)
    {
        if(Temp == Root)
        {
            if(Temp->left == NULL)
            {
                Root = Temp->right;
            }
            else
            {
                Root = Temp->left;
            }
        }
        else if(Temp->right == NULL)
        {
            if(Parent->right == NULL)
            {
                Parent->left = Temp->left;
            }
            else
            {
                Parent->right = Temp->left;
            }
        }
        else
        {
            if(Parent->right == NULL)
            {
                Parent->left = Temp->right;
            }
            else
            {
                Parent->right = Temp->right;
            }
        }
    }
    free(Temp);
}
int BinST :: Height(TreeNode *subroot)
{   
    int lh = 0,rh = 0;
    if(subroot == NULL)
    {
        return -1;
    }
    else
    {
        lh = Height(subroot->left);
        rh = Height(subroot->right);
    }
    if(lh > rh)
    {
        return lh + 1;
    }
    return rh + 1;
}
void BinST :: RotLeft(TreeNode* wrtNode,TreeNode* prev)
{   TreeNode* Temp;
    if(wrtNode->right != NULL)
    {
    if(wrtNode == Root)
    {
        Temp = Root;
        Root = Root->right;
        if(Root->left != NULL)
        {
            Temp->right = Root->left;
        }
        else{
            Temp->right = NULL;
        }
        Root->left = Temp;
        
    }
    else
    {
        if(wrtNode->data > prev->data)
        {
            prev->right = wrtNode->right;
        }
        else if(wrtNode->data < prev->data)
        {
            prev->left = wrtNode->right;
        }
        Temp = wrtNode;
        wrtNode = wrtNode->right;
        if(wrtNode->left != NULL)
        {
            Temp->right = wrtNode->left;
        }
        else
        {
            Temp->right = NULL;
        }
        wrtNode->left = Temp;
        
    }
    }
    // else
    // {
    //     cout<<"cANNOT ROTATE"<<endl;
    // }
}

void BinST :: ROTRight(TreeNode* wrtNode,TreeNode* prev)
{   TreeNode* Temp;
    if(wrtNode->left != NULL)
    {
    if(wrtNode == Root)
    {
        Temp = Root;
        Root = Root->left;
        if(Root->right != NULL)
        {
            Temp->left = Root->right;
        }
        else{
            Temp->left = NULL;
        }
        Root->right = Temp;
        
    }
    else
    {
        if(wrtNode->data > prev->data)
        {
            prev->right = wrtNode->left;
        }
        else if(wrtNode->data < prev->data)
        {
            prev->left = wrtNode->left;
        }
        Temp = wrtNode;
        wrtNode = wrtNode->left;
        if(wrtNode->right != NULL)
        {
            Temp->left = wrtNode->right;
        }
        else
        {
            Temp->left = NULL;
        }
        wrtNode->right = Temp;
        
    }
    }
    // else
    // {
    //     cout<<"CANNOT ROTATE"<<endl;
    // }
}
void BinST :: InsertAVL()
{
    TreeNode* prev = NULL, *NewNode = Insert(), *FIB = NULL, *FIBprev = NULL,*Temp = Root;char typ[2] = {'/','/'};int i = 0;
    // cout<<"Node created :: "<<NewNode->data<<endl;
    while(Temp != NewNode)
    {
        if(balanceF(Temp) == 0)
        {
            FIB = Temp; FIBprev = prev;
        }
        prev = Temp;
        if(Temp->data < NewNode->data)
        {
            Temp = Temp->right;
        }
        else if(Temp->data > NewNode->data)
        {
            Temp = Temp->left;
        }
    }
    // if(FIB != NULL)
    // {
    //     cout<<"Imbalanced node :: "<<FIB->data<<endl;
    // }
    // else
    // {
    //     cout<<"The tree is happy !"<<endl;
    // }

    
    if(FIB != NULL)
    {
        TreeNode* T = FIB;
        while(T != NewNode)
        {
            if(T->data < NewNode->data)
            {
                typ[i] = 'r'; i += 1;
                T = T->right;
            }
            else if(T->data > NewNode->data)
            {
                typ[i] = 'l';i+=1;
                T = T->left;
            }
        }
    }
    // cout<<"Type of imbalance :: "<<typ<<endl;
    if(typ[0] == 'l' && typ[1] == 'l')
    {
        ROTRight(FIB,FIBprev);
        cout<<"Imbalance ll was detected at "<<FIB->data<<" and was restored by rotating "<<FIB->data<<" to right"<<endl;
        // cout<<"Root of subtree /tree :: "<<Root->data<<endl;
    }
    else if(typ[0] == 'r' && typ[1] == 'r')
    {
        RotLeft(FIB,FIBprev);
        cout<<"Imbalance rr was detected at "<<FIB->data<<" and was restored by rotating "<<FIB->data<<" to left"<<endl;
    }
    else if(typ[0] == 'l' && typ[1] == 'r')
    {
        RotLeft(prev,FIB);
        ROTRight(FIB,FIBprev);
        cout<<"Imbalance lr was detected and restored."<<endl;
        cout<<"Operations performed to restore balance :: "<<prev->data<<" moved left and then right rotn wrt "<<FIB->data<<endl;

    }
    else if(typ[0] == 'r' && typ[1] == 'l')
    {
        ROTRight(prev,FIB);
        RotLeft(FIB,FIBprev);
        cout<<"Imbalance rl was detected and restored."<<endl;
        cout<<"Operations performed to restore balance :: "<<prev->data<<" moved right and then left rotn wrt "<<FIB->data<<endl;
    }
}