#include<iostream>
#include<string.h>
#include "methods.cpp"
using namespace std;
static char operators[] = {'-','+','/','*','^'};
bool isoperator(char x)
{
    for(int i = 0; i<5;i++)
    {
        if(x == operators[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{   
    string postfix_exp;stack_sll Tree_stack;Bin_Tree expression_tree;Tree_Node* Temp;// These are the variables required for the program
    cout<<"Enter Postfix expression :: "<<endl;
    getline(cin, postfix_exp);
    int l = postfix_exp.length();
    for(int i = 0;i < l;i++)
    {
        if(!isoperator(postfix_exp[i]))
        {   
            Tree_stack.push(expression_tree.MakeNode(postfix_exp[i]));
            // Tree_stack.Display();.
        }
        else
        {   
            Temp = expression_tree.MakeNode(postfix_exp[i]);
            Temp->right = Tree_stack.Top->data;
            Tree_stack.pop();
            // Tree_stack.Display();
            Temp->left = Tree_stack.Top->data;
            Tree_stack.pop();
            // Tree_stack.Display();
            Tree_stack.push(Temp);
            // Tree_stack.Display();
        }
    }
    ;
    expression_tree.change_Root(Tree_stack.Top->data);

    // Tree_stack.Display();
    cout<<"Displaying Inorder form of the created expression tree :: "<<endl;
    expression_tree.Inorder();
    cout<<"\nDisplaying Preorder form of the created expression tree :: "<<endl;
    expression_tree.Pre_order();
    cout<<endl;
    cout<<"Displaying Postorder traversal of the created expression tree :: "<<endl;
    expression_tree.Postorder(Tree_stack.Top->data);
    Tree_stack.pop();
    cout<<"\nEND OF PRG"<<endl;
    return 0;
}