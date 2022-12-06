#include "graph_matrix.cpp"
void Graph :: Prim()
{   
    int TotWei = 0;
    int cost[10],known[10],prev[10];
    int current = 1,Totv = 0;
    for(int i = 2;i<=v;i++)
    {
        cost[i] = 32767;
        known[i] = 0;
        prev[i] = 0;
    }
    known[1] = 1;cost[1] = 0;prev[1] = -1;
    cout<<"Process:: "<<endl;
    while(Totv != v)
    {   

        for(int i = 1;i<=v;i++)
        {
            if(adjMatrix[current][i] > 0 && adjMatrix[current][i] < cost[i] && known[i] == 0)
            {
                cost[i] = adjMatrix[current][i];
                prev[i] = current;
            }
        }
        current = select(cost,known);
        
        Totv += 1;

    }
    cout<<"OUTPUT ::"<<endl;
    cout<<"Start vertex :: "<<1<<endl;
    cout<<"Following re the edges in the MST :: "<<endl;
    for(int i = 2;i<=v;i++)
    {
        cout<<"("<<prev[i]<<", "<<i<<")"<<"\t";
        TotWei += cost[i];
    }
    cout<<"\nTotal weight of the MST :: "<<TotWei;
}
