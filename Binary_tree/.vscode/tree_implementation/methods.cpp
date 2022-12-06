#include "class_Bintree.cpp"
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
        int choice;;
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
// void Bin_Tree :: Inorder()
// {
    
// }