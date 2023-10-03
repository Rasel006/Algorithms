#include<bits/stdc++.h>
using namespace std;
const int N = 10e5 + 7;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
vector<int> prnt(N);
void bfs(int src)
{
    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    prnt[src] = -1;
    while(!qu.empty()) //O(V+ E)
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
                prnt[child] = parent;
            }
        }
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i= 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int src, desti;
    cin >> src >> desti;
    bfs(src);
    cout << level[desti] << endl;

    for(int i = 1; i <= n ; i++)
    {
        cout << "Parent of " << i << " "<< prnt[i] << endl;
    }

    vector<int> path;
    int current = desti;
    while(current != -1)
    {
        path.push_back(current);
        current = prnt[current];
    }

    reverse(path.begin(), path.end());
    cout << "Node In Path: ";
    for(int pth : path) cout << pth << " ";
    return 0;
}