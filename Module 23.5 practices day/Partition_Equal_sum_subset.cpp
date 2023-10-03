class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;

        for(int i = 0; i < n; i++){
            s += nums[i];
        }
        if(s % 2 == 0){
        s /= 2;
        bool dp[n + 1][s + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= s; j++){
                if(i, j == 0){
                    dp[i][j] = true;
                    continue;
                }
                if(i == 0){
                    dp[i][j] = false;
                    continue;
                }

                if(j >= nums[i - 1]){
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
                return dp[n][s];
    }
    else{
        return false;
    }
        // return dp[n][s];
    }
};