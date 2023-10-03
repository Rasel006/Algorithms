#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited(100);
vector<int> cc;
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : graph[parent])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i= 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i<=n;i++)
    {
        if(!visited[i])
        {
            cc.push_back(i);
            dfs(i);
        }
    }
    cout << cc.size() << endl;
    return 0;
}