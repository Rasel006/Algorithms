#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const long long int infi=1e18;
vector<long long int>ds(N,infi);

class edg
{
    public:
        int x,y,w;
        edg(int x,int y,int w)
        {
            this->x=x;
            this->y=y;
            this->w=w;
        }
};

// const int N=1e3+10;
// const long long int infi=1e18;
// vector<long long int>ds(N,infi
int main()
{
    int p,q;
    cin>>p>>q;

    vector<edg>edge;

    for (int i=0;i<q;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edge.push_back(edg(x,y,w));
    }
    int s;
    cin>>s;
    ds[s]=0;
    for(int i=1;i<=p-1;i++)
    {
        for(int j=0;j<edge.size();j++)
        {
            edg ed=edge[j];
            int x=ed.x;
            int y=ed.y;
            int w=ed.w;

            if(ds[x]<infi && ds[y]>ds[x]+w)
            {
                ds[y]=ds[x]+w;
            };
        }
    };

    bool Cycle=false;

    for(int j=0;j<edge.size();j++)
    {
        edg ed= edge[j];
        int x=ed.x;
        int y=ed.y;
        int w=ed.w;

        if(ds[x]<infi && ds[y] > ds[x]+w)
        {
            Cycle=true;
            break;
        };
    }

    if(Cycle)
    {
        cout<<"Negative Cycle Detected"<<endl;
    }
    else
    {
        int k;
        cin >>k;
        while(k--)
        {
            int g;
            cin>>g;

            if(ds[g]==infi)
            {
                cout<<"Not Possible"<<endl;
            }
            else
            {
                cout<<ds[g]<<endl;
            }
        }
    }

    return 0;
}