#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+ 5;
vector<pair<int,int>> v[N];
int dis[N];
bool visited[N];

void Dijktra_naive(int s){
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({dis[s],s});

    while (!pq.empty())
    {
        auto parent = pq.top().second;
        auto parentcost = pq.top().first;
         pq.pop();
        if(visited[parent]) continue;
        visited[parent] = true;
        for (auto &&i : v[parent])
        {
            auto child = i.second;
            auto weight = i.first;
            if(dis[child] > parentcost + weight){
                dis[child] = parentcost + weight;
                pq.push({dis[child], child});
            }
            
        }
        

        
    }
        
}
int main(){

     int n, e; cin >> n >> e; 
     while(e--){
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({w,b});
        v[b].push_back({w,a});
     }

     for (int i = 1; i <=n; i++)
     {
        dis[i] = INT_MAX;
     }
     

     Dijktra_naive(1);


     for (int i = 1; i <= n; i++)
     {
        cout <<"Distance Of " << i << " : " << dis[i] << endl;
     }
     
    return 0;
}