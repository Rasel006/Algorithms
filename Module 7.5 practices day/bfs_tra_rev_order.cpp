#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited(100);
stack<int> bfs(int src)
{
    stack<int> result;
    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        result.push(parent);
        for(int child : graph[parent])
        {
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
            }
        }
    }

    return result;
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
    stack<int> r = bfs(1);
    while(!r.empty())
    {
        cout << r.top() << " ";
        r.pop();
    }
    return 0;
}