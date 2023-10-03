
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dis(n + 1);
    
    for(int i = 1; i <= n; i++){
        dis[i] = 100000000;
    }

    dis[src] = 0;
    
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
                dis[v] = min(dis[v], dis[u] + w);

        }
    }
    return  dis;
}