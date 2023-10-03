//bfs with tree  and graph
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];
int level[100];
void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    level[src] = 0;
    while(!qu.empty())
    {
        //pop a node frome the queue and insert 
        //unvisited neighbors of that node in the queue
        int parent = qu.front();
        qu.pop();
        cout << "Visiting node - " << parent << endl;
        //Section-1: A node is being processed
        for(int child : adj[parent])
        {   
            //Section-2: Child is being processed
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
                //Section-3: Child is being processed
            }
        }
        //Section-4: Same as Section-1
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    //inputting Graph
    for( int  i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "Node - " << i << " Level : " << level[i] << endl;
    }
    return 0;
}