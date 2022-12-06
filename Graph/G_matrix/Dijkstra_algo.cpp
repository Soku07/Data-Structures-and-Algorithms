#include "graph_matrix.cpp"
#include "stack_sll.cpp"
const int infinity = 32767;
void Graph :: Dijkstra() 
{
    int source, u, Known[10],Distance[10],prev[10],totv = 1;
    cout<<"Enter Source :: ";
    cin>>source;cout<<endl;
    
    for(int i = 1;i<=v;i++) // Initialising the values
    {   
        if(i != source)
        {
            Distance[i] = infinity;
            Known[i] = 0;
            prev[i] = 0;
        }
        else
        {
            Known[source] = 1;Distance[source] = 0;prev[source] = -1;u = source;
        }
    }
    cout<<"Starting vertex :: "<<source<<endl; // Input :: The vertex from which shortest distance to other vertices would be calculated
    while(totv != v)
    {
        for(int i = 1;i<=v;i++)
        {   
            if(adjMatrix[u][i] > 0 && Known[i] == 0)
            {   
                if((Distance[u] + adjMatrix[u][i]) < Distance[i])
                {
                    Distance[i] = Distance[u] + adjMatrix[u][i];
                    prev[i] = u;
                }
            }
        }
        u = select(Distance,Known); // To select the minimum distance edge whose vertices are not known yet
        //Displaying :: 
        cout<<"------------------------------------"<<endl;
        if(Distance[u] == infinity)
        {
            cout<<"Path - "<<source<<"->"<<u<<" does not exist!"<<endl;
        }
        else
        {   int j = u;stack_sll st;
            cout<<"Path :: "<<source<<" to "<<u<<" :: ";
            while(j != source)
            {
                j = prev[j];
                st.push(j);
            }
            st.Display();cout<<u<<endl;
            cout<<"Shortest Distance to reach "<<u<<" :: "<<Distance[u]<<endl;
            cout<<"------------------------------------"<<endl;
        }
        totv += 1;
    }
}