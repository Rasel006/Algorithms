#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pII;

int main()
{
    int N;
    cin>>N;

    priority_queue<pII,vector<pII>,greater<pII>>pq;

    while(N--)
    {
        int x,y;
        
        cin>>x>>y;
        pq.push({x,y});
    };

    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;

        pq.pop();
    }

    return 0;
}