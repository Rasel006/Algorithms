//dfs with tree
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    //section-1: actions just after entering a node u
    visited[u] = true;
    cout << "Visited Node: " << u << endl;
    for(int v: adj[u])
    {
        //section-2: 
        //actions before entering a new(unvisited) neighbor
        if(visited[v] == true) continue;
        dfs(v);
        //section-3:
        //actions after exiting a neighbor
    }
    //section-4:
    //actions befor exiting node u
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << "Visited Array" << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " - " << "Status: " << visited[i] << endl;
    }
    /*for(int i = 1; i <= n; i++)
    {
        cout << "List->" << i << " : ";
        for(int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/
    return 0;
}