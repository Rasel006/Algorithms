#include<bits/stdc++.h>
const int N = 1e5 + 7;
vector<pair<int,int>>Graph_List[N];
bool visited[N];
vector<int>dist(N,INT_MAX);
void dijkstra_Main(int src){
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty()){
        int parent = pq.top().second;
        int parentCost = pq.top().first;
        pq.pop();

        if(visited[parent]) continue;
        visited[parent] = true;

        for(auto && ChildPair : Graph_List[parent]){
            int childNode = ChildPair.second;
            int childCost = ChildPair.first;

            if(dist[childNode] > parentCost + childCost){
                dist[childNode] = parentCost + childCost;
                pq.push({dist[childNode], childNode});
            }
        }
    }

}
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges,int source) {
        
        for(auto && i : edge){
            Graph_List[i[0]].push_back({i[2],i[1]});
            Graph_List[i[1]].push_back({i[2],i[0]});

        }

  dijkstra_Main(source);
  vector<int> path;
  for(int i = 0; i < vertices; i++){
      path.push_back(dist[i]);
  }
  
    
  return path; 
}