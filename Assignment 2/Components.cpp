#include<bits/stdc++.h>

using namespace std;

const int n=1e3+5;

vector<int>adj[n];
bool visited[n];

void dfs(int x,int &cnt)
{
    visited[x]=true;
    cnt++;

    for(int y:adj[x])
    {
        if(visited[y])
        {
            continue;
        };

        dfs(y,cnt);
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
        adj[y].push_back(x);
    };

    int count=0;
    vector<int>cmp;

    for(int i=0;i<=1000;i++)
    {
        if(visited[i])
        {
            continue;
        }
        count=0;

        dfs(i,count);

        if(count>1)
        {
            cmp.push_back(count);
        }
    }
    sort(cmp.begin(),cmp.end());

    for(int size : cmp)
    {
        cout<<size<<" ";
    }
    return 0;
}
