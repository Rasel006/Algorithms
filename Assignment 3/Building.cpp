#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>PI;
const int N=1e5+9;

vector<PI>graphlist[N];
bool vis[N];

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

class comp
{
    public:

        bool operator()(edg p,edg q)
        {
            return p.w>q.w;
        }
};

void PrimsAlgorithm(int t, int e)
{
    priority_queue<edg, vector<edg>,comp>pq;
    pq.push(edg(t,t,0));
    int cunt=0;
    vector<edg>Edge;

    while(!pq.empty())
    {
        edg parent=pq.top();
        pq.pop();

        int y=parent.y;
        if(vis[y])
        {
        continue;
        }
        vis[y]=true;

        Edge.push_back(parent);
        cunt++;

        for(auto &&child : graphlist[y])
        {
            if(!vis[child.first])
            {
                pq.push(edg(y,child.first,child.second));
            }
        }
        
    }
    Edge.erase(Edge.begin());

    long long sum=0;

    for(auto &&ed:Edge)
    {
        sum+=(long long)(ed.w);
    }
    if(cunt==e)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    
    
}

int main()
{
    
    int n,e;

    cin>>n>>e;
     
     while (e--)
     {
        int x,y,w;
        cin>>x>>y>>w;

        graphlist[x].push_back({y,w});
        graphlist[y].push_back({x,w});
     }

     PrimsAlgorithm(1,n);
     
     

    return 0;
}