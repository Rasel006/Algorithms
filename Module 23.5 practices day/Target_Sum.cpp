
class Solution {
public:
    // const int N = 1e3+3;
    int dp[1003][1003];
    int choiceCount(int n, int s,vector<int>nums){
        //  Base case 
        if(n == 0){
            if(s == 0) return 1;
            else return 0;
        }
        if(dp[n][s] != -1) return dp[n][s];

        if(s >= nums[n - 1]){
            return dp[n][s] = choiceCount(n - 1, s - nums[n - 1], nums) + choiceCount(n - 1, s, nums);
        }
        else{
            return dp[n][s] = choiceCount(n - 1, s, nums);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
     int n = nums.size();
      int sum = 0;
     for(int i = 0; i < n;i++){
        sum+= nums[i];
     }
     int tsum = (target + sum) / 2;

     for(int i = 0; i <= n; i++){
         for(int j = 0; j <= tsum; j++){
             dp[i][j] = -1;
         }
     }
    
      choiceCount(n, tsum, nums);
     return dp[n][tsum];   
    }
};