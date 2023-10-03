#include<bits/stdc++.h>
using namespace std;

const int n=1e5+5;

vector<int>adj[n];
bool visited[n];

int level[n];

void bfs(int a)
{
    queue<int>q;
    q.push(a);
    
    visited[a]=true;
    level[a]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v:adj[u])
        {
            if(visited[v])
            {
                continue;
            };

            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
        }
    }
};

int main()
{
    int p,t;
    cin>>p>>t;

    for(int i=0;i<t;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0);
    int j;
    cin>>j;

    if(j==0)
    {
        cout<<0;
    }
    else
    {
        vector<int>a;

        for(int i=0; i<=p;i++)
        {
            if(level[i]==j)
            {
                a.push_back(i);
            }
        }

        if(a.empty())
        {
            cout<<-1;
        }
        else
        {
            for(int v:a)
            {
                cout<<v<<" ";
            }
        }
    }

    return 0;
}