#include<iostream>
#include "TBT_class.cpp"
using namespace std;

int main()
{   
    TBT ThreadTree;int choice;
    do 
    {
        cout<<"Enter :: 0.End\t1.AddNode\t2.Display Tree(INORDER)\t3.PREORDER "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0: 
            break;
        case 1: ThreadTree.AddNode();
                break;
        case 2: cout<<"Displaying INORDER traversal of the tree"<<endl;
                ThreadTree.Inorder();
                cout<<endl;
                break;
        case 3 : cout<<"Displaying PREORDER TRAVERSAL OF THE TREE"<<endl;
                 ThreadTree.Preorder();
                 cout<<endl;
                 break;
        default:cout<<"Wrong choice, Enterring the while loop again."<<endl;
            break;
        }
    }while(choice != 0);
    return 0;
}