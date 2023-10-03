#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
// Create graph list for input
const int N = 1e5 + 5;
vector<pii> graph_List[N];
bool visited[N];

// Create the class for the priority_queue
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
// Create the custorm sort function
class Cmp
{
public:
    bool operator()(Edges a, Edges b)
    {

        return a.w > b.w;
    }
};

// Create the Prims Algorithm
void PrimsAlog(int s)
{
    // Create priority_queue for the main algo
    priority_queue<Edges, vector<Edges>, Cmp> pq;
    pq.push(Edges(s, s, 0));
    vector<Edges> ed_list;
    while (!pq.empty())
    {
        Edges parent = pq.top();
        int v = parent.v;
        pq.pop();
        
        if(visited[v]) continue;
        visited[v] = true;
        ed_list.push_back(parent);
        
        for (auto &&e : graph_List[v])
        {
            pii child = e;
            if(!visited[e.first]){
              pq.push(Edges(v,child.first,child.second));  
            }

        }
        
    }
    ed_list.erase(ed_list.begin());
    for (auto &&i : ed_list)
    {
        cout << i.u << " " << i.v << " " << i.w  << endl;
    }
    
}
int main()
{

    // Take input
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph_List[u].push_back({v, w});
        graph_List[v].push_back({u, w});
    }

    PrimsAlog(1);

    return 0;
}