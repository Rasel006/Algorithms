//**********PB: https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> graph;
int visited[N][N];
int level[N][N];
pii prnt[N][N];
int n , m;
vector<pii> direction = 
{make_pair(0, -1), make_pair(0, 1), 
 make_pair(-1, 0), make_pair(1, 0)};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pii> qu;
    qu.push(make_pair(si, sj));
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!qu.empty())
    {
        pii parent = qu.front();
        int i = parent.first;
        int j = parent.second; 
        qu.pop();

        for(auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if(isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != '#')
            {
                qu.push(make_pair(ni, nj));
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                prnt[ni][nj] = make_pair(i, j);
            }

        }

        
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for(int j = 0; j < m; j++)
        {
            if(x[j] == 'A')
                si = i, sj = j;
            if(x[j] == 'B')
                di = i, dj = j;
        }
        graph.push_back(x);
    }
    
    bfs(si, sj);

    if(level[di][dj] !=  0)
    {
        cout << "YES\n";
        cout << level[di][dj] << endl;
    }
    else
    {
        cout << "NO\n";
    }
    vector<pii> path;
    pii cur = make_pair(di, dj);
    while(!(cur.first ==si && cur.second == sj))
    {
        path.push_back(cur);
        cur = prnt[cur.first][cur.second];
    }
    path.push_back(make_pair(si, sj));
    reverse(path.begin(), path.end());
    // for(auto p : path) cout << p.first << " " << p.second << endl;
    for(int i = 1; i < path.size(); i++)
    {
        //path[i-1] = path[i];
        if(path[i-1].first == path[i].first)
        {
            if(path[i-1].second == path[i].second - 1)
            {
                cout << "R";
            }
            else cout << "L";
        }
        else
        {
            if(path[i-1].first == path[i].first - 1)
            {
                cout << "D";
            }
            else cout << "U";
        }
    }
    return 0;
}