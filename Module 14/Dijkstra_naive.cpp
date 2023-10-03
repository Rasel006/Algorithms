#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+ 5;
vector<pair<int,int>> v[N];
int dis[N];

void Dijktra_naive(int s){
    queue<int> q;
    q.push(s);
    dis[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (auto &&i : v[parent])
        {
            auto child = i.second;
            auto weight = i.first;

            if(dis[child] > dis[parent] + weight){
                dis[child] = dis[parent] + weight;
                q.push(child);
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
        cout <<"Distance of " << i << " : " << dis[i] << endl;
     }
     
    return 0;
}