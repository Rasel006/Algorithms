//dfs with tree
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    //section-1: actions just after entering a node u
    visited[u] = true;
    // cout << "Visited Node: " << u << endl;
    for(int v: adj[u])
    {
        //section-2: 
        //actions before entering a new(unvisited) neighbor
        if(visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        // if(height[v] + 1 > height[u])
        //     height[u] = height[v] + 1;
        height[u] = max(height[u], height[v] + 1);
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
    // cout << "Visited Array" << endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << " - " << "Status: " << visited[i] << endl;
    // }
    for(int i = 1; i <= n; i++)
    {
        cout << "Depth of Node " << i << " : " << depth[i] << endl;
    }
    cout  << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "Hight of Node " << i << " : " << height[i] << endl;
    }
    return 0;
}