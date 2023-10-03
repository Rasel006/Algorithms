#include <bits/stdc++.h>
using namespace std;
// create the class
class Edges
{
public:
    int u;
    int v;
    int w;

    Edges(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edges a, Edges b){
    return a.w < b.w;
}

// Create the DSU 
const int N = 1e5+5;
int parent[N];
int SizeOfparent[N];

void Union_Set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        SizeOfparent[i] = 1;
    }
    
}

int Union_Find(int node){
    if(node == parent[node]) return node;

    return parent[node] = Union_Find(parent[node]);
}

void Union(int a, int b){
    int leaderA = Union_Find(a);
    int leaderB = Union_Find(b);

    if(leaderA != leaderB){
        if (SizeOfparent[leaderA] >= SizeOfparent[leaderB])
        {
            parent[leaderB] = leaderA;
            SizeOfparent[leaderA] += SizeOfparent[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            SizeOfparent[leaderB] += SizeOfparent[leaderA];
        }
    }
}
int main()
{
    // Take input
    int n, e;
    cin >> n >> e;

    vector<Edges>Graph_Edges;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Graph_Edges.push_back(Edges(u, v, w));
    }
    Union_Set(n);
    sort(Graph_Edges.begin(), Graph_Edges.end(), cmp);
    vector<Edges>Answer;
    for (auto &&i : Graph_Edges)
    {
        int leaderA = Union_Find(i.u);
        int leaderB = Union_Find(i.v);
        if(leaderA == leaderB) continue;
        Answer.push_back(i);
        Union(i.u,i.v);
    }
    
    for (auto &&ed : Answer)
    {
        cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }
    

    return 0;
}