#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct node 
{
char data;

struct node * left;
struct node * right;
struct node * next;
};
struct node * top=NULL;



void push(node* p)
{
  struct node * temp;
    
    temp=p;
    temp->next=top;
    top=temp;
}
struct node * pop()
{
    struct node * temp=new (node);
    if(top==NULL)
    {
        cout<<"EMPTY STACK"<<endl;
    }
    else
    {
    temp=top;
    top=top->next;
    temp->next=NULL;
    return temp;
    free(temp);
    }
}
struct node * exptree(string s)
{
    for(int i=0 ; i<s.length() ; i++)
    {
        struct node * temp;
      char ch=s.at(i);
      if((ch>='a' && ch<='z'))
      {
         temp=new(node);
         temp->data=ch;
         temp->left=NULL;
         temp->right=NULL;
         push(temp);
      }    
      else
      {
          temp=new(node);
          temp->data=ch;
          temp->right=pop();
          temp->left=pop();
          push(temp);
      }   
    }
    return pop();
}
void postorder(node *t)
{
if(t!=NULL)
{

postorder(t->left);
postorder(t->right);
cout<<t->data<<" ";
}
}
void inorder(node* t)
{
    if(t != NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

int  main()
{
struct node * root;
root=new(node);
string k;
cout<<"Enter postfix string "<<endl;
cin>>k;
root=exptree(k);
postorder(root);
cout<<"\n";
inorder(root);
    return 0;
}