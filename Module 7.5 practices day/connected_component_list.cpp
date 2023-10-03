#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<bool> visited(100);
vector<vector<int>> ccList;
vector<int> l;
void dfs(int parent)
{
    visited[parent] = true;
    l.push_back(parent);
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
    int cc = 0;
    for(int i = 1; i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ccList.push_back(l);
            l.clear();
            cc++;
        }
    }
    cout << cc << endl;
    for(int i = 0; i < ccList.size(); i++)
    {
        cout << "Component " << i+1 << " : ";
        for(int j = 0; j < ccList[i].size(); j++)
        {
            cout << ccList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}