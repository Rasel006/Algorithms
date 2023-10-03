#include<bits/stdc++.h>
using namespace std;
// Create a graph and some variables 
const int N = 1e5+15;
vector<int> graph_List[N];
bool visited[N];
 
// Dfs function 
void DFS(int u){
    visited[u] = true;
    for (auto &&v : graph_List[u])
    {
        if(visited[v]) continue;
        DFS(v);
    }
    
}
int main(){
    
    // Take input 
    int n , e;
    cin >> n >> e;
 
    for (int i = 0; i < e; i++)
    {
        int v1, v2; cin >> v1 >> v2;
        graph_List[v1].push_back(v2);
        graph_List[v2].push_back(v1);
    }
    
    // work for the build the road 
    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        leaders.push_back(i);
        DFS(i);
    }
 
    cout << leaders.size() - 1 << endl;
    for (int i = 1; i <= leaders.size() - 1; i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }
    
 
    
    
     
 
    return 0;
}