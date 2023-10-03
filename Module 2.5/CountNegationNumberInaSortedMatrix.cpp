https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++){
            int length = grid[i].size();
            for(int j = 0; j < length; j++){
                if(grid[i][j] < 0){
                    count += length - j;
                    break;
                }
            }
        }
        
        return count;
    }
};