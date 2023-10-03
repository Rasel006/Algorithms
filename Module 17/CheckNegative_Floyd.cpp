#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int u;
    int v;
    int w;
    edge (int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    
    vector<edge> v;
   int n, e; cin >> n >> e;

   while (e--)
   {
        int a, b, w;
        cin >> a >> b >> w;
        edge ed(a, b, w);
        v.push_back(ed);
   }
    vector<int> dis(n+1);

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    
   for(int i = 1; i < n  ; i++){
        for (int j = 0; j < v.size(); j++)
        {
          edge edges = v[j];

          int u = edges.u;
          int v = edges.v;
          int w = edges.w;

          if(dis[u] + w <= dis[v]){
            dis[v] = dis[u] + w;
          }
        }
   }

    bool cycle = false;
        for (int j = 0; j < v.size(); j++)
        {
          edge edges = v[j];

          int u = edges.u;
          int v = edges.v;
          int w = edges.w;

          if(dis[u] + w < dis[v]){
            cycle = true;
            break;
            dis[v] = dis[u] + w;
          }
   }

  if(cycle) cout << "Cycle Detected";
 else{
      for (int i = 1; i <= n; i++)
   {
    cout << " Distance of " << i << " : " << dis[i] <<endl; 
   }
    }
   
     

    return 0;
}