/*Name:Ameya Dhake
 *Roll no.: 23121
 *Batch: E9
 *Subject:DSAL
 *Assignment no.:6
 *TBT
 */
#include <iostream>
using namespace std;
class ThreadedBinaryTree;
class N
{
	N *l,*r;
	int data;
	bool rt,lt;
public:
	N()
	{
		data=0;
		l=NULL;
		r=NULL;
		rt=lt=0;
	}
	N(int d)
	{
		l=NULL;
		r=NULL;
		rt=lt=0;
		data=d;
	}
	friend class ThreadedBinaryTree;
};
class ThreadedBinaryTree
{
     N *root; //Temporary node
     public:
     ThreadedBinaryTree() //Temporary node initialization
     {
    	 root=new N(65739);
    	 root->l=root->r=root;
    	 root->rt=1; //child
    	 root->lt=0; //threaded connection
     }
     void create();
     void insert(int data);
     N *inordsuc(N *);
     void inorder();
     N *preordsuc(N *c);
     void preorder();
};
void ThreadedBinaryTree::preorder()
{
	N *c=root->l;
	while(c!=root)
    {
        cout<<" "<<c->data;
        c=preordsuc(c);
    }
}
N *ThreadedBinaryTree::preordsuc(N *c)
{
	if(c->lt==1)
    {
    	return c->l;
    }
    while(c->rt==0)
    {
        c=c->r;
    }
    return c->r;
}
void ThreadedBinaryTree::inorder()
{
    N *c=root->l;
    while(c->lt==1)
        c=c->l;
    while(c!=root)
    {
        cout<<" "<<c->data;
        c=inordsuc(c);
    }
}
N* ThreadedBinaryTree::inordsuc(N *c)
{
    if(c->rt==0)
        return c->r;
    else
        c=c->r;
    while(c->lt==1)
    {
        c=c->l;
    }
    return c;
}
void ThreadedBinaryTree::create()
{
    int n;
    cout<<"\nHow many no. of nodes do you want to insert: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int info;
         cout<<"\nPlease enter the data to be inserted: ";
         cin>>info;
         insert(info);
    }
}
void ThreadedBinaryTree::insert(int data)
{
    if(root->l==root&&root->r==root) //when there is no node
    {
        N *p=new N(data);
        p->l=root->l;
        p->lt=root->lt; //0
        p->rt=0;
        p->r=root->r;
        root->l=p;
        root->lt=1;
        cout<<"\nInsertion started successfully.\n Data inserted is:"<<data<<endl;
        return;
     }
     N *curr;//new node;
     curr=root->l; //first node inserted in the tree
	 while(1)
	 {
		 int ch;
		 cout<<"Press 1:Insert on left \nPress 2:Insert on right\nEnter your choice:"<<endl;
		 cin>>ch;
		 if(ch==2)   //For insertion on right
		 {
			 if(curr->rt==0)
			 {
				 N *p=new N(data);
				 p->r=curr->r;
				 p->l=curr;
				 p->rt=p->lt=0;
				 curr->r=p;
				 curr->rt=1;
				 cout<<data<<" is inserted on the right successfully. "<<endl;
				 return;
			 }
			 else
				 curr=curr->r;
		 }
		 if(ch==1) //For insertion on left
		 {
			  if(curr->lt==0)
			  {
				  N *p=new N(data);
				  p->l=curr->l;
				  p->r=curr;
				  p->lt=p->rt=0;
				  curr->l=p;
				  curr->lt=1;
				  cout<<data<<" is inserted on the left successfully. "<<endl;
				  return;
			   }
			 else
				 curr=curr->l;
		 }
	 }
}
int main()
{
	ThreadedBinaryTree ob;
	int v,ch;
	cout<<"***Threaded Binary Tree***\n";
	cout<<"\nCreating Tree\n";
	ob.create();
	do
	{
		cout<<"\nTBT operations\n";
		cout<<"1.Insert \n2.Preorder traversal\n3.Inorder traversal\n4.Exit"<<endl;
		cout<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter data you want to insert: "<<endl;
				cin>>v;
				ob.insert(v);
				break;
			case 2:
				cout<<"\nPreorder traversal is: ";
				ob.preorder();
				break;
			case 3:
				cout<<"\nInorder traversal is: ";
				ob.inorder();
				break;
			case 4:
				cout<<"===Thank you for using TBT===\n";
				cout<<"---------Program Terminated---------";
				exit(0);
			default:
				cout<<"\nInvalid Input\n";
		}

	}while(ch!=0);
	return 0;
}
/*Ouput:
 * ***Threaded Binary Tree***

Creating Tree

How many no. of nodes do you want to insert: 3

Please enter the data to be inserted: 23

Insertion started successfully.
 Data inserted is:23

Please enter the data to be inserted: 12
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
2
12 is inserted on the right successfully.

Please enter the data to be inserted: 14
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
1
14 is inserted on the left successfully.

TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:2

Preorder traversal is:  23 14 12
TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:3

Inorder traversal is:  14 23 12
TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:1

Enter data you want to insert:
67
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
1
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
2
67 is inserted on the right successfully.

TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:1

Enter data you want to insert:
89
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
2
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
1
89 is inserted on the left successfully.

TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:1

Enter data you want to insert:
34
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
2
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
1
Press 1:Insert on left
Press 2:Insert on right
Enter your choice:
2
34 is inserted on the right successfully.

TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:2

Preorder traversal is:  23 14 67 12 89 34
TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:3

Inorder traversal is:  14 67 23 89 34 12
TBT operations
1.Insert
2.Preorder traversal
3.Inorder traversal
4.Exit
Enter Your Choice:4
===Thank you for using TBT===
---------Program Terminated---------
 */
