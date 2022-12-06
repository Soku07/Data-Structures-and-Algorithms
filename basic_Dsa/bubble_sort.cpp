#include<iostream>
using namespace std;
void Accept(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
}
void Display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }

    
}
void Sort(int size, int arr[])
{   int temp;
    for(int i = 1;i<size;i++)
    {
        for(int k=0; k<(size - i);k++)
        {
            if(arr[k+1]<arr[k])
            {
                arr[k+1] = temp;
                arr[k+1] = arr[k];
                arr[k] = temp;

            }
        }
    }
    Display(size, arr);
}
int main()
{
    int n;
    cout<<"Enter nymber of elements - ";
    cin>>n;
    int array[n];
    Accept(n, array);
    Sort(n, array);
    Display(n,array);
    
    return 0;
}