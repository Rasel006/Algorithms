#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pII;

const int n=1e3+5;
vector<vector<char>>a(n);

bool vis[n][n];
int x,y;

vector<pII>ds={{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int i,int j)
{
    return (i>=0 && i<x && j>=0 && j<y);
}

int cunt=0;

void dfs(int i, int j)
{
    if(!isValid(i,j))
    {
        return;
    }
    if(a[i][j]=='-')
        return;

    if(vis[i][j])
        return;
    cunt++;
    vis[i][j]=true;

    for(pII vpir:ds)
    {
        int cI=vpir.first;
        int cJ=vpir.second;

        dfs(i+cI,j+cJ);
    }
};

int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            char k;
            cin>>k;
            a[i].push_back(k);
        }
    }

    int Mn=INT_MAX;

    for(int i=0;i<x;i++)
    {
        for(int j=0; j<y;j++)
        {
            if(a[i][j]=='-')
                continue;

            if(vis[i][j])
                continue;

            dfs(i,j);
            Mn= min(Mn, cunt);
            cunt = 0;
        }
    }

    if(Mn!=INT_MAX)
    {
        cout<<Mn;
    }
    else
    {
        cout<<-1;
    }

    return 0;
}