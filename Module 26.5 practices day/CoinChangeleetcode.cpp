class Solution {
public:
    int coinChange(vector<int>& w, int s) {
        int n = w.size();
        int dp[n + 1][s + 1];

        for(int i = 0; i<= n; i++){
            for(int j = 0; j <= s; j++)
            {
                if(i == 0 && j == 0){
                    dp[i][j] = 0; 
                    continue;
                }
                if(i == 0){
                    dp[i][j] = INT_MAX - 1;
                    continue;
                }

                if(j >= w[i - 1]){
                    dp[i][j] = min(1+dp[i][j - w[i - 1]], dp[i - 1][j]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if(dp[n][s] == INT_MAX - 1){
            return -1;
        }
        else{
            return dp[n][s];
        }
    }
};