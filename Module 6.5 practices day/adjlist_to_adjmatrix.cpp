#include<bits/stdc++.h>
using namespace std;
vector<int>adjList[100];
int adjMat[100][100];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int val : adjList[i])
        {
            adjMat[i][val] = 1;
        }
    }
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}