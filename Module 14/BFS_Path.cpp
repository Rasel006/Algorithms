#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int dis[N];
bool vis[N];
int parr[N];
vector<int> Graph_list[N];

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    parr[s] = -1;
    vis[s] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i : Graph_list[parent])
        {
            if (vis[i])
                continue;
            q.push(i);
            dis[i] = dis[parent] + 1;
            parr[i] = parent;
            vis[i] = true;
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        Graph_list[a].push_back(b);
        Graph_list[b].push_back(a);
    }
    int d; cin >> d;
   ;
    BFS(1);
    if(vis[d]){
        vector<int> path;
        int current = d;

        while (current != -1)
        {
            path.push_back(current);
            current = parr[current];
        }
        reverse(path.begin(), path.end());

        for (auto &&i : path)
        {
            cout << i << " ";
        }
        
        
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}