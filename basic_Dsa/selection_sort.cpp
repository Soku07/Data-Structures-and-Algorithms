#include<iostream>
using namespace std;
void Accept(int size, int arr[])
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}
void Display(int size, int arr[])
{
    cout<<"Array is- "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ,";
    }cout<<endl;
}

void Selection_Sort(int size,int arr[])
{   cout<<"Analysing Selection sort - "<<endl;
    cout<<"Expected cmps - "<<(size*(size - 1))/2<<endl;
    int min,flag = 0,cmp = 0,count_min = 0,temp,swap = 0;
    for(int i = 1;i<size;i++)  // This loop is for passes

    {   cout<<"pass "<<i<<endl;
        min = arr[i - 1];
        for(int k = i;k<size;k++)
        {   cmp += 1;
            if(min > arr[k])
            {
                min = arr[k];
                flag = k;
                count_min +=1;
                cout<<"in this pass , min was actually changed - "<<count_min<<" times"<<endl;
            }

        }
        count_min = 0;
           if(flag)
    {
        temp = arr[i-1];
        arr[i-1] = min;
        arr[flag] = temp;
        swap += 1;
        
    }
        cout<<"Swap count - "<<swap<<endl;
        cout<<"Sorted array is - "<<endl;
        Display(size, arr);
    }

}
int main()
{
    int n;
    cout<<"Enter number of elements - "<<endl;
    cin>>n;
    int array[n];
    Accept(n, array);
    Selection_Sort(n, array);
    return 0;
}