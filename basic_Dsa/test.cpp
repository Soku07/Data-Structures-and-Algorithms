#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * right;
    struct node * left;
    int l,r;
};
node * getnode(int x)
{
    struct node * temp;
    temp=new(node);
    temp->data=x;
    temp->left=temp;
    temp->right=temp;
    temp->l=1;
    temp->r=1;
    return temp;
}
class tbt
{
    public:
    struct node  * head;
    struct node * root;
    void create(node * p,node * m);
    node * insert(node * , int k);
};
    void tbt::create(node * he ,node * ro)
    {
     head=getnode(999);
     int x;
     cout<<"Data to be entered into root"<<endl;
     cin>>x;
     root=getnode(x);
     head->left=root;
     head->left=0;
     root->right=head;
     root->left=head;
    }
    struct node * tbt::insert(node * head , int k)
    {
       struct  node * p;
       p=new(node);
        struct node  * n;
        n=new(node);
        if(head==NULL)
        {
            cout<<"Root is empty"<<endl;
        }
        else
        {
            p=head;
            // cout<<"DATA present in root is "<<p->data<<endl;
            if(k<p->data)
            {
                if(p->l=1)
                {
                    n=getnode(k);
                    n->right=p;
                    p->l=0;
                }
                else
                {
                  p=p->left;
                }
            }
            if(k>p->data)
            {
                if(p->r=1)
                {
                   n=getnode(k);
                   n->left=p;
                   p->r=0;
                }
                else
                {
                    p=p->right;
                }
            }
        }
        return head;
    }
    void inorder(node * p)
    {
        if(p!=NULL)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
int main()
{
    tbt obj;
    node * h;
    h=new(node);
    node * r;
    r=new(node);
    obj.create(h,r);
    int ch;
    do
    {
        cout<<"ENTER CHOICE"<<endl;
        cin>>ch;
       switch (ch)
       {
       case 1:
            { 
                int x;
                cout<<"Enter data"<<endl;
                cin>>x;
                h=obj.insert(r,x);
            }
           break;
       case 2:
       {
        cout<<"EXIT"<<endl;
       }
       break;
       default:
       cout<<"INVALID"<<endl;
           break;
       }
    } while (ch!=2);
    r=h;
    inorder(r);
    return 0;
}