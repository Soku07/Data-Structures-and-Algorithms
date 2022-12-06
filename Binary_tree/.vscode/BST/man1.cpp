#include<iostream>
#include "BST_class.cpp"
using namespace std;

int main()
{
    BinST BStree;int choice;
    do
    {
        cout<<"Enter :: 0.End\t1.Insert NODE in AVL tree\t2.Display\t3.Insert 5 elements in the AVL Tree\t4.Search\t5.Delete"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0 : break;
            case 1 : 
                    BStree.InsertAVL();
                     break;
            case 2 : BStree.Inorder();
                     cout<<endl;
                     break;
            case 3 : for(int i = 0;i<5;i++)
                    {
                        BStree.InsertAVL();

                    }
                    break;
            case 4 : BStree.Search();
                     break;       
            case 5 : BStree.Delete();

                     break;
            
            default : cout<<"Enter valid choice!!"<<endl;
                      break;
        }

    }while(choice != 0);

    cout<<"\nEND of prg"<<endl;
    return 0;
}