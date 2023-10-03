class Solution {
public:
   vector<vector<bool>> visited{350, vector<bool>(350, false)};
    vector<pair<int, int> > direction = {{0, -1}, {0, 1}, {-1, 0}, {1 , 0}};

    bool  isValid(int i,int j, int n , int m){
            return(i >=0 && i < n && j >= 0 && j < m);
    }


    // void DFS(int i, int j, int n,int m,vector<vector<char>>grid){
    //     if(visited[i][j]) return;
    //     if(isValid(i, j, n,m)&& !visited[i][j] && grid[i][j] != '0'){
    //         for(auto && d : direction){
    //             visited[i+d.first][j+d.second] = true;
    //             cout << i + d.first << " " << j + d.second;
    //             DFS(i, j, n,m,grid);
    //         }
    //     }
    // }


void BFS(int si, int sj, int n , int m,vector<vector<char>>grid){
    queue<pair<int,int>>q;
    q.push({si, sj});
    visited[si][sj] = true;

    while(!q.empty()){
        pair<int, int> Unpair = q.front();
        q.pop();
        int i = Unpair.first;
        int j = Unpair.second;
        
        for(auto && d : direction){
            int ni = i + d.first;
            int nj = j + d.second;
        if(isValid(ni,nj, n,m) && !visited[ni][nj] && grid[ni][nj] != '0')
        {
                q.push({ni, nj});
                visited[ni][nj] = true;
        }
    }
    }
}



    int numIslands(vector<vector<char>>& grid) {
    int size = grid.size();
    int countofJ= grid[0].size();

    // for(int i = 0; i < size; i++){
    //     for(auto && i : grid[i]){
    //         countofJ++;
    //     }
    // }
    // countofJ /= size; 

    int cnt = 0;
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < countofJ; j++){
            if(!visited[i][j] && grid[i][j] != '0'){
                // DFS(i, j, size, countofJ, grid);
                BFS(i, j, size,countofJ,grid);
                cnt++;
            }
        }
    }


    return cnt;

    }
};