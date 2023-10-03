#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
vector<vector<int>>tList;
vector<int>ccList;
void dfs(int parent)
{
    visited[parent] = true;
    ccList.push_back(parent);
    for(int child : adj[parent])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
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
    int cc = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            tList.push_back(ccList);
            ccList.clear();
            cc++;
        }
    }
    cout << "Total Connected Components : " << cc << endl;
    for(int i = 0; i < tList.size(); i++)
    {
        cout << "Components -> " << i + 1 << " : ";
        for(int j = 0; j < tList[i].size(); j++)
        {
            cout << tList[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}