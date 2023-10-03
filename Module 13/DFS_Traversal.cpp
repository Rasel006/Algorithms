#include<bits/stdc++.h>
using namespace std;
// Create the Adjacyncy List 
const int N = 1e5+ 3;
vector<int> graph_List[N];
bool visited[N];

// Make the dfs function
void DFS(int src){
    visited[src] = true;
    cout << src << endl;
    for (auto &&v :graph_List[src])
    {
        if(visited[v]) continue;;
            DFS(v); 
    }
}  


int main(){
    int n, e; cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2; cin >> v1 >> v2;
        graph_List[v1].push_back(v2); 
        graph_List[v2].push_back(v1); 
    }
    
    DFS(1);
    return 0;
}