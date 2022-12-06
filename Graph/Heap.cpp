#include<iostream>
using namespace std;

class Heap
{
    private:
    int array[20],size;
    void Heapify(int[],int,int);void Swap(int[],int,int);
    public:
    Heap()
    {
        size = 0;
    }
    Heap(int n)
    {
        size = n;
    }
    void Display();
    void Getsize()
    {
        cout<<"Enter size of the input array :: "<<endl;
        cin>>size;
        cout<<"ENter Array elements :: "<<endl;
        for(int i = 0;i<size;i++)
        {
            cin>>array[i];
        }
    }
    void Heap_Sort();
};
void Swap(int arr[],int index1,int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
void Heap :: Heapify(int arr[],int n,int root)
{
    int left = 2*root + 1;int right = 2*root +2;int largest = root;
    if(left<n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right<n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        Heapify(arr,n,largest);
    }
}
void Heap :: Heap_Sort()
{
    for(int i = size/2 - 1;i>=0;i--)
    {
        Heapify(array,size,i);
    }
    for(int i = size-1;i>=0;i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        Heapify(array,i,0);
    }
}
void Heap :: Display()
{
    for(int i = 0;i<size;i++)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    Heap h;
    h.Getsize();
    h.Heap_Sort();
    cout<<"Displaying sorted array :: "<<endl;
    h.Display();
    return 0;
}