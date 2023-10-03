https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0] > 0) return nums.size();
        if(nums[nums.size() - 1] < 0) return nums.size();
        
        int neg = 0;
        int pos = 0;
        int l = 0;
        int r = nums.size() -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] < 0) {
                neg = mid + 1;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = 0;
        r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > 0) {
                pos = nums.size() - mid;
             r = mid - 1;   
            }
            else  l = mid + 1;

        }
        cout << neg << " "<< pos;
        return max(neg, pos);
    }
};