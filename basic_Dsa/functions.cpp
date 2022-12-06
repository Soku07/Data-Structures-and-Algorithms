#include<iostream>
using namespace std;
void swap(int a, int b)
{
    int temp = b;
    b = a;
    a = temp;
}
void swapPointer(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void swapReference(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}
int main()
// Call by value 
{   int a,b;
    cout<<"Enter a and b";
    cin>>a>>b;
    cout<<"Value of a is "<<a<<" And value of b is "<<b<<endl;
    swap(a,b);
    cout<<"By using call by value - ";
    cout<<"Value of a is "<<a<<" And value of b is "<<b<<endl;
    // Call by pointer ref
    swapPointer(&a, &b);
    cout<<"By using call by pointer reference - ";
    cout<<"Value of a is "<<a<<" And value of b is "<<b<<endl;
    swapReference(a, b);
    cout<<"By using call by reference - ";
    cout<<"Value of a is "<<a<<" And value of b is "<<b<<endl;


    return 0;
}


