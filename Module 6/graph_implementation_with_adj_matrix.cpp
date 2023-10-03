#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjmat[N][N];
int main()
{
    int n, m; // n = number of nodes in graph
    //m = number of edges in graph
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w; // u, v denoting the connection between two nodes with a edge
        //W is denoting the weight of edges
        cin >> u >> v >> w;
        // adjmat[u][v] = 1; // this single line for directed graph
        // adjmat[v][u] = 1; // previous and this line for undirected graph

        // this snippet for weighted graph
        adjmat[u][v] = w;
        adjmat[v][u] = w;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << adjmat[i][j] << " ";
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