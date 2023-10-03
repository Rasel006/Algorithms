#include<bits/stdc++.h>
using namespace std;

const int n=1e3+5;

vector<int>adj[n];
bool visited[n];
vector<int>road;

void bfs(int x,int k)
{
    queue<int>q;
    q.push(x);
    visited[x]=true;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int y:adj[x])
        {
            if(y== k)
            {
                road.push_back(x);
            }

            if(visited[y])
            {
                continue;
            };

            q.push(y);
            visited[y]=true;
        }
    }
};

int main(){
    int p,t;
    cin>>p>>t;

    for(int i=0;i<t;i++)
    {
        int x,y;
        cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int k;
    cin>>k;

    for(int i=0;i<=20;i++)
    {
        if(visited[i])
        {
            continue;
        };

        bfs(i,k);
    }
        cout<<road.size();

    return 0;
}