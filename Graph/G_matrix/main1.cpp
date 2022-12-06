// #include "Prim.cpp"
#include "Dijkstra_algo.cpp"
int main()
{   
    Graph g;
    g.getv();
    g.CreateGraph();
     g.CheckInput();
    // g.DisplayGraph();
    // g.Prim();
   
    cout<<endl;
    g.Dijkstra();
    cout<<"\nEnd of prg"<<endl;
    return 0;
}