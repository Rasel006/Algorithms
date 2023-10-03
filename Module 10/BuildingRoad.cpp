//Problem Link : https://cses.fi/problemset/task/1666/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
vector<bool> visited(N);
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
    for(int i = 0; i < m; i++)
    {
        int  u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> leaders;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            leaders.push_back(i);
            dfs(i);
        }
    }
    //Printing leaders of every connected components
    // for(auto l : leaders) cout << l << " ";

    //Number of edges for making all components to 1 component
    // Number of edges = leaders - 1;
    cout << leaders.size() - 1 << endl;

    //new connected vertices
    for(int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }
    return 0;
}