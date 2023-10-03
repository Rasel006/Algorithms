#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[100];
bool visited[100];
int depth[100];
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : adjList[parent])
    {
        if(!visited[child])
        {
            depth[child] = depth[parent] + 1;
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }
    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "Depth- " << i << depth[i] << endl;
    }
    return 0;
}