class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector <pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        queue<pair<int,int>> q; 
        for(int i = 0; i < row; i++){
            for(int j = 0; j< col; j++){
                if(grid[i][j] == 1)q.push({i, j});
            }
        }

        if(q.empty() || q.size() == row * col) return -1;

        int levels = -1;
        while(!q.empty()){
            levels++;
            int s = q.size();
            while(s--){
                pair<int, int> Unpair = q.front();
                q.pop();
                int i = Unpair.first;
                int j = Unpair.second;

            for(auto dir : direction){
                int ni = i + dir.first;
                int nj = j + dir.second;

                if(ni<0 or nj<0 or ni>=grid.size() or nj>=grid[0].size() or grid[ni][nj]==1){
                    continue;
                }
                q.push({ni,nj});
                grid[ni][nj] = 1;
                }
              }
            }
        return levels;
        
    }
};