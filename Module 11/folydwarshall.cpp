#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int d[N][N];
int n, m;
void dist_init()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
                d[i][j] = INF;
        }
    }
}
void print_matrix()
{
     for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(d[i][j] == INF) cout << 'X' << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
void floyd_warshall()
{
    for(int k = 1; k <= n; k++) //allowing nodes
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main()
{
   
    cin >> n >> m;

    dist_init();

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        //d[v][u] = w;
    }
    cout <<" Befor algo: " << endl;
    print_matrix();

    floyd_warshall();
    cout <<" after algo: " << endl;
    floyd_warshall();
    print_matrix();
    return 0;
}