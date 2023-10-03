#include<bits/stdc++.h>
using namespace std;
// Crate the Edes and sort custom func 
class Edges{
    public:
    int u,v,w;
    Edges(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edges a, Edges b){
    return a.w < b.w;
}
// Create Union Funcitons 
const int N = 1e5+7;
int parent[N];
int parentSize[N];

void Union_Set(int n){
    for (int i = 0; i <=n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
    
}

int Union_Find(int node){
    if(node == parent[node]) return node;
    
    return parent[node] = Union_Find(parent[node]);
}

void Union_Func(int a, int b){
    int leaderA = Union_Find(a);
    int leaderB = Union_Find(b);

    if(leaderA != leaderB){
        if(parentSize[leaderA] >= parentSize[leaderB]){
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else{
             parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main(){
    
    int n, e; cin >> n >> e;
    Union_Set(n);
    vector<Edges> Graph_Edges;
    while (e--)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        Graph_Edges.push_back(Edges(u,v,w)); 
    }

    sort(Graph_Edges.begin(),Graph_Edges.end(),cmp);
    vector<Edges>spanning_Tree;
    for (auto &&i : Graph_Edges)
    {
        int LeaderA = Union_Find(i.u);
        int LeaderB = Union_Find(i.v);

        if(LeaderA == LeaderB) continue;
        spanning_Tree.push_back(i);
        
        Union_Func(i.u, i.v);
    }
    
    long long sum = 0;
    
    for (auto &&ed : spanning_Tree)
    {
        sum += (long long)(ed.w);
    }
    cout << sum <<endl;

     

    return 0;
}