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

void dfs(int i,int j)
{
    if(!isValid(i,j))
    {
        return;
    }

    if(a[i][j]=='-')
        return;

    if(vis[i][j])
        return;

    vis[i][j]=true;

    for(pII vpir:ds)
    {
        int cI=vpir.first;
        int cJ=vpir.second;

        dfs(i+cI, j+cJ);
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

    int qI,uI,qJ,uJ;
    cin>>qI>>qJ>>uI>>uJ;
    dfs(qI,qJ);

    if(vis[uI][uJ])
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}