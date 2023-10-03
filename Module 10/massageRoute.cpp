//PB: https://cses.fi/problemset/task/1667

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
vector<int> prnt(N, -1);
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    level[src] = 0;
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
                prnt[child] = parent;
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
        int  u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    // if()
    //else
    cout << level[n] + 1 << endl;

    int current = n;
    vector<int> path;
    while(current != -1)
    {
        path.push_back(current);
        current = prnt[current];
    }

    reverse(path.begin(), path.end());
    
    for(auto p : path) cout << p << " ";
    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> graph[N];
vector<bool> visited(N);
vector<int> level(N);
vector<int> prnt(N, -1);
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
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
                prnt[child] = parent;
                
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
    if(visited[n])
    {
        cout << level[n] + 1 << endl;
        vector<int>path;
        int cur = n;
        while(cur != -1)
        {
            path.push_back(cur);
            cur = prnt[cur];
        }
        reverse(path.begin(), path.end());
        for(auto x : path) cout << x << " ";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}

*/