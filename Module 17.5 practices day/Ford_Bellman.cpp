#include<bits/stdc++.h>
using namespace std;
// Create a class for controll The edges 
class Edges_Group{
    public:
    int u;
    int v;
    int w;

    Edges_Group(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    
    // Take input 
    vector<Edges_Group> Graph_Egdes;
     int n, e; 
     cin >> n >> e;

     while (e--)
     {
        int u, v, w;
        cin >> u >> v >> w;

        Edges_Group edge(u, v, w);
        Graph_Egdes.push_back(edge);
     }
     int Distance[n+1];
     for (int i = 0; i <= n; i++)
     {
        Distance[i] = 30000;
     }
     
    Distance[1] = 0;
    for(int i = 1; i <= n; i++){
       for (int j = 0; j < Graph_Egdes.size(); j++)
       {
          Edges_Group Single_Edge = Graph_Egdes[j];
            int u = Single_Edge.u;
            int v = Single_Edge.v;
            int w = Single_Edge.w;
            
            if(Distance[u] < 30000 && Distance[u] + w <= Distance[v]){
                Distance[v] = Distance[u] + w;
            }
       }
    }
        
        for (int i = 1; i <= n; i++)
        {
            cout << Distance[i] << " ";
        }
        

    return 0;
}