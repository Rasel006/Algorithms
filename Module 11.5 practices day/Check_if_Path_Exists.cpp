#include <bits/stdc++.h>

// Create the important variables 
const int N = 1e5+10;
vector<int> Graph_List[N];
bool visited[N];
// Start the DFS  
void DFS(int i){
    visited[i]= true;
    for(auto && v : Graph_List[i]){
            if(visited[v]) continue;
            DFS(v);
    }

}

bool checkPathExists(int v, int e, int source, int destination, vector<vector<int>> &edges) 
{
    for(int i = 0; i< N; i++){
        Graph_List[i].clear();
        visited[i] = false;
    }
    for (int i = 0; i < e; i++) {
            Graph_List[edges[i][0]].push_back(edges[i][1]);
    }
    
    // Call the DFS  
    DFS(source);

    
    // Return the result 
   return visited[destination];
}