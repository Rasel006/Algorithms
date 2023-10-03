#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[100];
bool visited[100];
int height[100];
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : adjList[parent])
    {
        if(!visited[child])
        {
            
            dfs(child);
            height[parent] = max(height[parent], height[child] + 1);
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
    int target;
    cin >> target;
    dfs(1);
    cout << "height of " << target << " = " << height[target];
    return 0;
}