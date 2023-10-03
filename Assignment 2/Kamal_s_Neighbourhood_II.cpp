#include<bits/stdc++.h>
using namespace std;

const int n=1e3+5;

vector<int>adj[n];
bool visited[n];

int cnt=0;

void dfs(int x,int k)
{
    visited[x]=true;

    if (x!=k)
    {
        cnt++;
    }
    for(int y:adj[x])
    {
        if(visited[y])
        {
            continue;
        }

        dfs(y,k);
    }
}

int main(){
    int p,t;
    cin>>p>>t;

    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
    }
    int k;
    cin>>k;

    for(int i=0;i<20;i++)
    {
        if(visited[i])
        {
            continue;
        };

        if(i==k)
        {
            dfs(i,k);
        }
    }
    cout<<cnt;

    return 0;
}