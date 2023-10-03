#include<bits/stdc++.h>
using namespace std;
const int n=1e5+5;

vector<int>parent(n,-1);
vector<int>parent_lev(n,0);

int Dsu_lead(int Node)
{
    while(parent[Node]!=-1)

    {
        Node=parent[Node];
    };

    return Node;
};

void Dsu_uni(int x,int y)
{
    int leadX=Dsu_lead(x);
    int leadY=Dsu_lead(y);

    if(leadX!=leadY)
    {
        if(parent_lev[leadX]>parent_lev[leadY])
        {
            parent[leadY]=leadX;
        }
        else if(parent_lev[leadY]>parent_lev[leadX])
        {
            parent[leadX]=leadY;
        }
        else
        {
            parent[leadY]=leadX;
            parent_lev[leadX]++;
        }
    }
};

int cunt=0;

int main(){

    int p,q;

    cin>>p>>q;

    while(q--)
    {
        int x, y;
        cin>>x>>y;

        int leadX=Dsu_lead(x);
        int leadY=Dsu_lead(y);

        if(leadX==leadY)
        {
            cunt++;
        }
        else
        {
            Dsu_uni(x,y);
        }
    }

    cout<<cunt;

    return 0;
}