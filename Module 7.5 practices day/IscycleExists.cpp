#define OR ||
#define AND &&
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited(100);
bool dfs(int parent, int pp = -1)
{
    bool isCycleExits = false;
    visited[parent] = true;
    for(int child : graph[parent])
    {
        if(child == pp) continue;
        if(visited[child]) return true;
        isCycleExits = isCycleExits OR dfs(child, parent);
    } 
    return isCycleExits;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {
        int u, v;
        cin>> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool isCycleExits = false;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        isCycleExits = isCycleExits OR dfs(i);
    }
    isCycleExits ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}