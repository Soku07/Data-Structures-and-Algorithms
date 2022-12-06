#include<iostream>
using namespace std;
void Accept(int n, int arr[])
{
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void Display(int n, int arr[])
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<", ";
    }..
}
void Insertion_Sort(int s1, int s2, int arr1[], int arr2[],int arr[])
{
    int i = 0,j = 0,k;

    for(k = 0;k<s1 + s2;k++)
    {
        if(j < s2)
        {
            if(arr1[i]>=arr2[j])
            {
                arr[k] = arr2[j];
                j += 1;
                // break;
            }
            else
            {
                arr[k] = arr1[i];
                i += 1;
                // break;
            }
        }
        else{
            arr[k] = arr1[i];
            i += 1;
        }
    }
}
int main()
{   int size1, size2,temp;
    cout<<"Enter size of array 1 :"<<endl;
    cin>>size1;
    cout<<"Enter size of array 2 :"<<endl;
    cin>>size2;
    int  array[size1+size2];
    if(size1<size2)
    {
        temp = size1;
        size1 = size2;
        size2 = temp;
    }
    int array1[size1], array2[size2];
    if(temp<size1)

    {  
        cout<<"Enter first array of "<<size2<<" elements - "<<endl;
        Accept(size2,array2);
        cout<<"Enter second array of "<<size1<<" elements - "<<endl;
        Accept(size1,array1);
    }
    else{
        cout<<"Enter first array of "<<size1<<" elements - "<<endl;
        Accept(size1,array1);
        cout<<"Enter second array of "<<size2<<" elements - "<<endl;
        Accept(size2,array2);
    }
    
    
    Insertion_Sort(size1, size2, array1, array2, array );
    cout<<"Displaying sorted array - "<<endl;
    Display(size1+size2,array);
    return 0;
}