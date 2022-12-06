#include "class_Bintree.cpp"
Bin_Tree :: Bin_Tree()
{
    Root = NULL;
}
Tree_Node* Bin_Tree :: MakeNode(char x)
{
    Tree_Node* T;
    T = new(Tree_Node);
    T->left = NULL;
    T->right = NULL;
    T->data = x;
    return T;
}
void Bin_Tree :: AddNode(int a, char y)
{   
    Tree_Node* T = Root;
    if(T != NULL)
    {   
        do
        {

            if(a == 1) // add to left
            {
                if(T->left == NULL)
                {
                    T->left = MakeNode(y);
                    break;
                }
                else
                {
                    T = T->left;
                }

            }
            else if(a==2)
            {
                if(T->right == NULL)
                {
                    T->right = MakeNode(y);
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
        Root = MakeNode(y);
        
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
        pointer_stack.~stack_sll();
    }
}
void Bin_Tree :: change_Root(Tree_Node* t)
{
    Root = t;
}
void Bin_Tree :: Inorder()
{
    Tree_Node* temp; stack_sll pointer_stack;
    if(Root == NULL)
    {
        cout<<"Tree is empty"<<endl;
    }
    else
        
    {   
        temp = Root;
        do
        {
                    
        while(temp != NULL)
        {   
            pointer_stack.push(temp);
            // pointer_stack.Display();
            temp = temp->left;
        }
        if (pointer_stack.Top != NULL)
        {
            temp = pointer_stack.Top->data;
            pointer_stack.pop();
            // pointer_stack.Display();
            cout<<temp->data<<"\t";
            temp = temp->right;
        }
        
        } while (temp != NULL || pointer_stack.Top != NULL);
        // cout<<"Hello bef"<<endl;
        delete temp;
        // cout<<"Hello after delete temp"<<endl;
    }
    // cout<<"Hello outside else"<<endl;
}
void Bin_Tree :: Postorder(Tree_Node* root)
{
    if(root!= NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<"\t";
    }
}