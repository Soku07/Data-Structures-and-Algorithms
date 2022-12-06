#include<iostream>
#include "methods.cpp"
using namespace std;
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