#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pII;

const int n=1e2+10;
vector<vector<int>>a(n);

bool vis[n][n];
int dis[n][n];

int x,y;
vector<pII>des={{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool isValid(int i,int j)
{
    return (i>=0 && i<x && j>=0 && j<y);
}

void bfs(int i,int j)
{
    queue<pII>q;
    q.push({i,j});
    vis[i][j]=true;
    dis[i][j]=0;

    while(!q.empty())
    {
        pII tpair=q.front();
        int pI=tpair.first;
        int pJ=tpair.second;
        q.pop();

        for(pII p:des)
        {
            int cI=p.first+pI;
            int cJ=p.second+pJ;

            if(!isValid(cI,cJ))
            { 
                continue;
            }
            if (vis[cI][cJ])
                continue;

            vis[cI][cJ]=true;
            q.push({cI,cJ});
            dis[cI][cJ]=dis[pI][pJ]+1;
        }
    }
};

int main()
{
    int f;
    cin>>f;

    while(f--)
    {
        cin>>x>>y;
        int qI,qJ,uI,uJ;
        cin>>qI>>qJ>>uI>>uJ;
        bfs(qI,qJ);
        if(vis[uI][uJ])
        {
            cout<<dis[uI][uJ]<<endl;
        }
        else
        {
            cout<<-1<<endl;
        };
        memset(vis,false,sizeof vis);
        memset(dis,0,sizeof dis);
    }

    return 0;
}