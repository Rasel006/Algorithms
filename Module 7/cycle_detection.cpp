#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
bool dfs(int parent, int pp = -1)
{
    bool isCycleExists = false;
    visited[parent] = true;
    for(int child : adj[parent])
    {
        if(child == pp) continue; // is neighbor == childs parent?
        if(visited[child]) return true;
        isCycleExists = isCycleExists || dfs(child, parent); // decession from whole graph
    }
    return isCycleExists;
}
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(int child : adj[parent])
        {   
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for( int  i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //This section is for 1 component graph
    /*dfs(1) == true ? cout <<"Cycle Detected"<< endl : cout << 
    "Cycles Not Detectd" << endl;*/

    //This section is for multiple component graph
    bool isCycle = false;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i])continue;
        isCycle = isCycle || dfs(1);
    }
    isCycle == true ? cout <<"Cycle Detected"<< endl : cout << 
    "Cycles Not Detectd" << endl;
    return 0;
}