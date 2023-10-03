class Solution {
public:
   // private :
    
    vector<vector<bool>> visited{1000, vector<bool>(1000, false)};

    bool isValid(int i, int j, int row, int col){
        return (i >= 0 && i < row && j >= 0 && j < col);

    }
    vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void BFS(int si, int sj,int row, int col, vector<vector<int>> grid1, vector<vector<int>> grid2,int &flag){
        queue<pair<int, int>> q;
        q.push({si, sj});
        visited[si][sj] = true;

        while(!q.empty()){
            pair<int, int> Unpair = q.front();
            q.pop();

            int i = Unpair.first;
            int j = Unpair.second;

            for(auto && dir : direction){
                int ni = i + dir.first;
                int nj = j + dir.second;
            
                if(isValid(ni, nj, row, col) && !visited[ni][nj] && grid2[ni][nj] == 1 && grid1[ni][nj] == 0){
                    flag  = 0;
                    grid2[ni][nj] = 2;
                    return;
                }
                if(isValid(ni, nj, row, col) && !visited[ni][nj] && grid1[ni][nj] == grid2[ni][nj]){
                    q.push({ni, nj});
                    grid2[ni][nj] = 2;
                    visited[ni][nj] = true;
                }
            }
        }

    }

        void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int &flag){
        if(i>=0 and j>=0 and i<grid2.size() and j<grid2[0].size()and grid2[i][j]==1){
            grid2[i][j] = 2;

            if(grid1[i][j]==0) flag = 0;

            dfs(grid1,grid2,i,j+1,flag);
            dfs(grid1,grid2,i,j-1,flag);
            dfs(grid1,grid2,i+1,j,flag);
            dfs(grid1,grid2,i-1,j,flag);
        }
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size();
        int col = grid2[0].size();
        int cnt = 0;
        for(int i = 0; i< row; i++){
            for(int j = 0; j < col; j++){
                if(grid2[i][j] == 1&&grid1[i][j] == grid2[i][j]){
                    int flag = 1;
                    // BFS(i, j,row, col, grid1, grid2,flag);
                    dfs(grid1, grid2,i,j,flag);
                    cnt += flag;
                }
            }
        } 
        return cnt;
    }

 

};