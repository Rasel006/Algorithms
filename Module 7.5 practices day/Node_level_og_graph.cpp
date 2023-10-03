#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited(100);
vector<int> level(100);
void bfs(int src)
{
    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(int child : graph[parent])
        {
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    int node;
    cin >> node;
    cout << "Level of " << node << " = " << level[node] << endl;
    return 0;
}