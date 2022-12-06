//---------------------------------------------------------N.K-------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};
int main(){
    int num, e, src;
    cout<<"Enter number of Vertices : (first vertex is denoted by 0)"<<endl;
    cin>>num;
    vector<Edge*> edges;
    cout<<"Enter number of edges :: "<<endl;
    cin>>e;
    for(int i = 0; i < e; i++){
        Edge* temp = new(Edge);
        cout<<"Enter Source :: "<<endl;
        cin>>temp->u;
        cout<<"Enter Destination :: "<<endl;
        cin>>temp->v;
        cout<<"Enter Weight :: "<<endl;
        cin>>temp->w;
        edges.push_back(temp);
    }
    
    vector<int> distance;
    int inf = 32767;
    for(int i = 0; i < num; i++){
        distance.push_back(inf);
    }
    cout<<"Enter Source :: "<<endl;
    cin>>src;
    distance[src] = 0;
    for(int i = 1; i <=num-1; i++){
        for(int j = 0; j<e; j++){
            if(distance[edges[j]->u] + edges[j]->w < distance[edges[j]->v]){
                distance[edges[j]->v] = distance[edges[j]->u] + edges[j]->w;
            }
        }
    }
    cout<<"distance array :: "<<endl;
    for(int i = 0; i < distance.size(); i++){
        cout<<distance[i]<<", ";
    }
    return 0;
}