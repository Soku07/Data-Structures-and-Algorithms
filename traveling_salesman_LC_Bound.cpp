
#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int N = 100;
  

int final_path[N+1];
bool visited[N];
int final_res = INT_MAX;

void copyToFinal(int curr_path[],int n)
{
    for (int i=0; i<n; i++)
        final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
}

int firstMin(int adj[N][N], int i,int n)
{
    int min = INT_MAX;
    for (int k=0; k<n; k++)
        if (adj[i][k]<min && i != k)
            min = adj[i][k];
    return min;
}
  

int secondMin(int adj[N][N], int i,int n)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j<n; j++)
    {
        if (i == j)
            continue;
  
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second &&
                 adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}
  

void TSPRec(int adj[N][N], int curr_bound, int curr_weight,
            int level, int curr_path[],int n)
{

    if (level==n)
    {

        if (adj[curr_path[level-1]][curr_path[0]] != 0)
        {

            int curr_res = curr_weight +
                    adj[curr_path[level-1]][curr_path[0]];
  

            if (curr_res < final_res)
            {
                copyToFinal(curr_path,n);
                final_res = curr_res;
            }
        }
        return;
    }
  

    for (int i=0; i<n; i++)
    {

        if (adj[curr_path[level-1]][i] != 0 &&
            visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level-1]][i];
  

            if (level==1)
              curr_bound -= ((firstMin(adj, curr_path[level-1],n) +
                             firstMin(adj, i, n))/2);
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1],n) +
                             firstMin(adj, i, n))/2);
  

            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;
  
                
                TSPRec(adj, curr_bound, curr_weight, level+1,
                       curr_path,n);
            }
  

            curr_weight -= adj[curr_path[level-1]][i];
            curr_bound = temp;
  

            memset(visited, false, sizeof(visited));
            for (int j=0; j<=level-1; j++)
                visited[curr_path[j]] = true;
        }
    }
}
  

void TSP(int adj[N][N],int n)
{
    int curr_path[N+1];
  

    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
  

    for (int i=0; i<n; i++)
        curr_bound += (firstMin(adj, i,n) +
                       secondMin(adj, i,n));
  

    curr_bound = (curr_bound&1)? curr_bound/2 + 1 :
                                 curr_bound/2;
  

    visited[0] = true;
    curr_path[0] = 0;
  

    TSPRec(adj, curr_bound, 0, 1, curr_path,n);
}
  
// Driver code
int main()
{
    //Adjacency matrix for the given graph
    int n;
    int adj[N][N];

    cout<<"Enter the number of vetices"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter the from "<<i+1<<"to "<<j+1<<endl;
            cin>>adj[i][j];
        }
    }
  
    TSP(adj,n);
  
    printf("Minimum cost : %d\n", final_res);
    printf("Path Taken : ");
    for (int i=0; i<=n; i++)
        printf("%d ", final_path[i]);
    
    cout<<endl;
    return 0;
}

/*
Enter the number of vetices
4
Enter the from 1to 1
0
Enter the from 1to 2
10
Enter the from 1to 3
15
Enter the from 1to 4
20
Enter the from 2to 1
10
Enter the from 2to 2
0
Enter the from 2to 3
35
Enter the from 2to 4
25
Enter the from 3to 1
15
Enter the from 3to 2
35
Enter the from 3to 3
0
Enter the from 3to 4
30
Enter the from 4to 1
20
Enter the from 4to 2
25
Enter the from 4to 3
30
Enter the from 4to 4
0
Minimum cost : 80
Path Taken : 0 1 3 2 0
*/