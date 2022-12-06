#include<iostream>
// #include "structure.h"
typedef struct ebox{
    int u,v,weight;
};
using namespace std;
class Graph
{
    private:
    int v,e;
    int adjMatrix[10][10];
    void Heapify(ebox* e_array[],int n,int root) // This function is required in heapsort
    {
        int largest = root,left = 2*root + 1,right = 2*root + 2;
        if(left<n && e_array[left]->weight > e_array[largest]->weight)
        {
            largest = left;
        }
        if(right<n && e_array[right]->weight > e_array[largest]->weight)
        {
            largest = right;
        }
        if(largest != root)
        {
            ebox *Temp;
            Temp = e_array[root];
            e_array[root] = e_array[largest];
            e_array[largest] = Temp;
            Heapify(e_array,n,largest); 
        }

    }
    void Heap_Sort(ebox* e_arr[],int n) // HEap sort is used to sort the edges according to thier weight.
    {
        for(int i = n/2 - 1;i>=0;i--)
        {
            Heapify(e_arr,n,i);
        }
        for(int i = n-1;i>=0;i--)
        {
             ebox *Temp;
            Temp = e_arr[0];
            e_arr[0] = e_arr[i];
            e_arr[i] = Temp;  
            // cout<<"Edgearray["<<i<<"] = "<<e_arr[i]<<"\tu::"<<e_arr[i]->u<<"\tv::"<<e_arr[i]->v<<"\tweight::"<<e_arr[i]->weight<<endl;
            Heapify(e_arr,i,0);       
        }
    }

    public:
    Graph()// for default input, change v,e in the constructor!
    {
        v = 0;e=0;
        for(int i = 1 ; i<=10;i++)
        {
            for(int j = 1;j<=10;j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void getdata() 
    {
        cout<<"Enter no. of vertices :: "<<endl;
        cin>>v;
        cout<<"Enter no. of edges :: "<<endl;
        cin>>e;       
    }
    void CreateGraph();
    void DisplayGraph();
    void CheckInput()
    {
        cout<<"Checking input :: "<<endl;
        for(int i = 1;i<=v;i++)
        {
            for(int j = 1;j<=v;j++)
            {
                cout<<adjMatrix[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    void Kruskal();
};

void Graph :: CreateGraph()
{   
//     int s,d,w;
//     // custom input :: 

//     cout<<"Creating edges :: (Enter appropriate source and destination.)"<<endl;
//     for(int i = 1;i <= e;i++)
//     {
//         cout<<"Enter Source :: "<<endl;
//         cin>>s;
//         cout<<"Enter Destination :: "<<endl;
//         cin>>d;
//         cout<<"Enter Weight :: "<<endl;
//         cin>>w;
//         adjMatrix[s][d] = w;
//         adjMatrix[d][s] = w;
//     }   
// Input graph 1 :: 
   adjMatrix[1][2] = 9;adjMatrix[1][3] = 1;
   adjMatrix[2][1] = 9;adjMatrix[2][3] = 5;adjMatrix[2][4] = 19;adjMatrix[2][5] = 17;
   adjMatrix[3][1] = 1;adjMatrix[3][2] = 5;adjMatrix[3][5] = 13;
   adjMatrix[4][2] = 19;adjMatrix[4][5] = 25;adjMatrix[4][6] = 2;
   adjMatrix[5][2] = 17;adjMatrix[5][3] = 13;adjMatrix[5][4] = 25;adjMatrix[5][6] = 14;adjMatrix[5][7] = 21;
   adjMatrix[6][4] = 2;adjMatrix[6][5] = 14;adjMatrix[6][7] = 8;
   adjMatrix[7][5] = 21;adjMatrix[7][6] = 8;

//Input Graph 2::
// adjMatrix[1][2] = 6;adjMatrix[1][3] = 3;
// adjMatrix[2][1] = 6;adjMatrix[2][3] = 2;adjMatrix[2][4] = 5;
// adjMatrix[3][1] = 3;adjMatrix[3][4] = 3;adjMatrix[3][2] = 2;adjMatrix[3][5] = 4;
// adjMatrix[4][2] = 5;adjMatrix[4][3] = 3;adjMatrix[4][5] = 2;adjMatrix[4][6] = 3;
// adjMatrix[5][3] = 4;adjMatrix[5][4] = 2;adjMatrix[5][6] = 5;
// adjMatrix[6][4] = 3;adjMatrix[6][5] = 5;
}
void Graph :: DisplayGraph()
{
    for(int i = 1; i<=v;i++)
    {
        cout<<"Adjacent vertices to "<<i<<" are :: "<<endl;
        for(int j = 1;j<=v;j++)
        {
            if(adjMatrix[i][j] != 0)
            {
                cout<<j<<"\t";
            }
        }
        cout<<endl;
    }
}
void Graph :: Kruskal()
{
    int known[10],connectivity = 1,index = 0,iss = 0,cost = 0;
    ebox* edge_array[20],*selected[10];
    
    for(int k = 1;k<=v;k++) //Initialising the known array
    {
        known[k] = 0;
    }
    for(int i = 1;i<=v;i++)
    {
        for(int j = 1;j<=v;j++)
        {
            if(adjMatrix[i][j] > 0 && j>i) //j>i is required bcoz the graph is directed. if this condition is skipped, every edge will be chosen twice.
            {
                ebox *T = new(ebox);
                T->u = i;
                T->v = j;
                T->weight = adjMatrix[i][j];
                edge_array[index] = T;
                 index += 1; 
            }
        }
    }

    Heap_Sort(edge_array,index);//Sorted according to weight
  
    for(int i = 0;i<index;i++)
    {
        if(known[edge_array[i]->u] == 0 && known[edge_array[i]->v] == 0) //connectivity is used to maintain the order in which edges and hence vertices were selected.
        {
            known[edge_array[i]->u] = connectivity;known[edge_array[i]->v] = connectivity;
            connectivity += 1;
            selected[iss] = edge_array[i];iss+=1;
            cost += edge_array[i]->weight;
        }
        else if(known[edge_array[i]->u] != 0 && known[edge_array[i]->v] == 0)// if edge is connecting say v1 and v2.Then , v1 should have the known value equivalent to that of v2.
        {
            known[edge_array[i]->v] = known[edge_array[i]->u];
            selected[iss] = edge_array[i];iss+=1;
            cost += edge_array[i]->weight;
        }
        else if(known[edge_array[i]->u] == 0 && known[edge_array[i]->v] != 0)
        {
            known[edge_array[i]->u] = known[edge_array[i]->v];
            selected[iss] = edge_array[i];iss+=1;
            cost += edge_array[i]->weight;
        }
        else if(known[edge_array[i]->u] != 0 && known[edge_array[i]->u] != known[edge_array[i]->v])//This condition is to select an edge that connects the graph which seems disconnected
        {
            for(int k = 1;k<=v;k++) //This loop is required to change the known value.
            {
                if(known[k] == known[edge_array[i]->u])
                {
                    known[k] = known[edge_array[i]->v];
                }
            }
            selected[iss] = edge_array[i];iss+=1;
            cost += edge_array[i]->weight;            
        }
        else if(iss == v-2)
        {
            break;
        }
    }
    cout<<"Cost of MST by Kruskal's Algorithm :: "<<cost<<endl;
    cout<<"Following edges were selected :: "<<endl;
    for(int i = 0;i<iss;i++)
    {
        cout<<selected[i]->u<<"<-->"<<selected[i]->v<<"\tweight :: "<<selected[i]->weight<<endl;
    }
}

int main()
{
    Graph g;
    g.getdata();
    g.CreateGraph();
    g.CheckInput();
    g.Kruskal();
    cout<<"End of program!!"<<endl;
    return 0;
}
//OUTPUT :: 
// Checking input :: 
// 0  9  1  0  0  0  0  
// 9  0  5  19  17  0  0  
// 1  5  0  0  13  0  0  
// 0  19  0  0  25  2  0  
// 0  17  13  25  0  14  21  
// 0  0  0  2  14  0  8  
// 0  0  0  0  21  8  0  
// Cost of MST by Kruskal's Algorithm :: 43
// Following edges were selected :: 
// 1<-->3  weight :: 1
// 4<-->6  weight :: 2
// 2<-->3  weight :: 5
// 6<-->7  weight :: 8
// 3<-->5  weight :: 13
// 5<-->6  weight :: 14
// End of program!!