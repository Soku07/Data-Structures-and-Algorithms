#include<iostream>
using namespace std;
// void displayArray(int arr[])
// {
//     for(int i = 1;i<=6;i++)
//     {
//         cout<<arr[i]<<"\t";
//     }
//     cout<<endl;
// }
class Graph
{
    private:
    int v,e;
    int select(int c[],int k[])
    {   
        int min = 32767,ver;
        for(int i =2;i<=v;i++)
        {
            if(c[i]<=min && k[i] == 0)
            {
                min = c[i];
                ver = i;
            }
        }
        
        k[ver] = 1;
        return ver;
    }
    int adjMatrix[10][10];
    public:
    Graph()
    {
        v = 7;e = 11;
        for(int i = 1 ; i<=10;i++)
        {
            for(int j = 1;j<=10;j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void getv()
    {
        cout<<"Enter no. of vertices :: "<<endl;
        cin>>v;
        cout<<"Enter no. of edges :: "<<endl;
        cin>>e;
    }
    void CreateGraph();
    void DisplayGraph();
    void Prim();
    void Dijkstra();
    void CheckInput()
    {
        cout<<"CHecking input :: "<<endl;
    for(int i = 1;i<=v;i++)
    {
        for(int j = 1;j<=v;j++)
        {
            cout<<adjMatrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    }
};
void Graph :: CreateGraph()
{   
    int s,d,w;
    //custom input :: 

    cout<<"Creating edges :: (Enter appropriate source and destination.)"<<endl;
    for(int i = 1;i <= e;i++)
    {
        cout<<"Enter Source :: "<<endl;
        cin>>s;
        cout<<"Enter Destination :: "<<endl;
        cin>>d;
        cout<<"Enter Weight :: "<<endl;
        cin>>w;
        adjMatrix[s][d] = w;
        adjMatrix[d][s] = w;
    }   
// Input graph 1 :: 
//    adjMatrix[1][2] = 9;adjMatrix[1][3] = 1;
//    adjMatrix[2][1] = 9;adjMatrix[2][3] = 5;adjMatrix[2][4] = 19;adjMatrix[2][5] = 17;
//    adjMatrix[3][1] = 1;adjMatrix[3][2] = 5;adjMatrix[3][5] = 13;
//    adjMatrix[4][2] = 19;adjMatrix[4][5] = 25;adjMatrix[4][6] = 2;
//    adjMatrix[5][2] = 17;adjMatrix[5][3] = 13;adjMatrix[5][4] = 25;adjMatrix[5][6] = 14;adjMatrix[5][7] = 21;
//    adjMatrix[6][4] = 2;adjMatrix[6][5] = 14;adjMatrix[6][7] = 8;
//    adjMatrix[7][5] = 21;adjMatrix[7][6] = 8;

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
