#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int>pII;

const long long int n=1e3+5;
vector<pII>a[n];
vector<bool>vis(n,false);
vector<long long int>ds(n,INT_MAX);

void dijk(long long int s)
{
    priority_queue<pII,vector<pII>,greater<pII>>pq;
    ds[s]=0;
    pq.push({ds[s],s});

    while(!pq.empty())
    {
        long long int tNode=pq.top().second;
        long long int tCost=pq.top().first;
        pq.pop();
        vis[tNode]=true;

        for(pII vpir:a[tNode])
        {
            long long int p=vpir.second;
            long long int q=vpir.first;

            if(vis[p])
                continue;

            if(tCost+q<ds[p])
            {
                ds[p]=tCost+q;
                pq.push({ds[p],p});
            }
        }
    }
};

int main()
{
    long long int b,c;
    cin>>b>>c;

    for(long long int i=0;i<c;i++)
    {
        long long int t,p,q;
        cin>>t>>p>>q;
        a[t].push_back({q,p});
    
    }

    long long int f,g;
    cin>>f>>g;

    dijk(f);

    while(g--)
    {
        long long int e,q;
        cin>>e>>q;

        if(e>1000)
        {
            cout<<"NO";
            continue;
        }
        if(ds[e]<=q)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}