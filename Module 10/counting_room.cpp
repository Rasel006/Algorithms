//**********PB: https://cses.fi/problemset/task/1192

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3 + 5;
vector<string> graph;
int visited[N][N];
// vector<pii> direction = 
// {make_pair(0, -1), make_pair(0, 1), 
// make_pair(-1, 0), make_pair(1, 0)};
int n , m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{
    if(!isValid(i, j)) return;
    if(visited[i][j]) return;
    if(graph[i][j] == '#') return;

    visited[i][j] = true;
    // for(auto d : direction)
    // {
    //     dfs(i+d.first, j + d.second);
    // }
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}
int main()
{
   
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        graph.push_back(x);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(graph[i][j] == '#') continue;
            if(visited[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}