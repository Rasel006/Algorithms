#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5 + 9;
vector<Pii> Graph_List[N];
bool visited[N];

class Edges{
    public:
    int u;
    int v;
    int w;

    Edges(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class cmp{
    public:

    bool operator()(Edges a, Edges b){
        return a.w > b.w;
    }
};
// Create the Algorithm 
void Prims_Algorithm(int s, int n){
    priority_queue<Edges, vector<Edges>,cmp> pq;
    pq.push(Edges(s,s,0));
    int cnt =  0;
    vector<Edges> roadOfEdge;

    while (!pq.empty())
    {
        Edges parent = pq.top();
        pq.pop();

        int v = parent.v;
        if(visited[v]) continue;
        visited[v] = true;
        roadOfEdge.push_back(parent);
        cnt++;

        for (auto &&child : Graph_List[v])
        {
            if(!visited[child.first]){
                pq.push(Edges(v,child.first,child.second));
            }
        }
        
    }
    roadOfEdge.erase(roadOfEdge.begin());
    long long sum = 0;
    for (auto &&ed : roadOfEdge)
    {
        sum += (long long)(ed.w);
    }
    if(cnt == n){
        cout << sum << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    
    
}

int main(){
    
    // Take input 
    int n, e; cin >> n >> e;
     
     while (e--)
     {
        int u, v, w;
        cin >> u >> v >> w;

        Graph_List[u].push_back({v,w});
        Graph_List[v].push_back({u,w});
     }

     Prims_Algorithm(1, n);
     
     

    return 0;
}