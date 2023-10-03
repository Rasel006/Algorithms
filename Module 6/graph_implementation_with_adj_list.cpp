#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int, int>> adj[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "List - " << i << " : ";
        for(auto j : adj[i])
        {
           cout << "(" << j.first << ", " << j.second << ")" << ",";
        }
        cout << endl;
    }
    return 0;
}

/*
  the undirected graph figure
         8
    1----------------2
    |      15       .|
  9 |      .         | 11
    |.               |
    3----------------4
            17
*/