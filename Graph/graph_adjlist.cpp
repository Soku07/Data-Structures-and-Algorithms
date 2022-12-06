#include<iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* next;
};
class Graph
{
    private: 
    int v;
    Node* AdjList[10];
    public:
    Graph()
    {
        v = 0;
    }
    void getv()
    {
        cout<<"Enter no of vertices :: "<<endl;
        cin>>v;
    }
    Node* GetNode(int x)
    {
        Node *T = new(Node);
        T->data = x;
        T->next = NULL;
    }
    void Creategraph_AdjL();
    void DisplayGraph();
};
void Graph :: Creategraph_AdjL()
{
    Node* T,*vertex,*Temp;int x;
    for(int i = 0;i < v;i++)
    {
        cout<<"Creating Adjacency list for vertex :: "<<i<<endl;
        vertex = GetNode(i);
        while(true)
        {
            cout<<"Enter adjacent vertices to "<<i<<"\t(enter -1 to break"<<endl;
            cin>>x;
            if(x==-1)
            {
                break;
            }
            else if(vertex->next == NULL)
            {
                T = GetNode(x);
                vertex->next = T;
                Temp = vertex->next;
            }
            else
            {
                T = GetNode(x);
                Temp->next = T;
                Temp = T;
            }
            
        }
        AdjList[i] = vertex;
    }

}
void Graph :: DisplayGraph()
{   Node* Temp;
    for(int i = 0;i<v;i++)
    {
        cout<<"Adjacent vertices to "<<i<<"are :: "<<endl;
        Temp = AdjList[i];
        // Temp = Temp->next;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
            cout<<Temp->data<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    Graph g;
    cout<<"Instance created"<<endl;
    // cout<<"Enter no. of vertices :: "<<endl;
    g.getv();
    cout<<"Creating Adjacency list for vertices 0 - (v-1) :: "<<endl;
    g.Creategraph_AdjL();
    cout<<"Displaying the created graph :: "<<endl;
    g.DisplayGraph();
    cout<<"End of prg"<<endl;
    return 0;
}