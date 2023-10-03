https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        long long int n =  nums.size() * (nums.size() + 1) / 2;
      
        for(int i = 0; i < nums.size(); i++){
            n -= nums[i];
        }

        return n;
        
    }
};