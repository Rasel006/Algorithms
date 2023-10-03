//PL: https://leetcode.com/problems/merge-sorted-array/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //vector<int> sorted1;
        for(int i = 0; i < m; i++)
        {
            sorted1.push_back(nums1[i]);
        }

        sorted1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        nums1.resize(m + n);
        int lp = 0, rp = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            if(sorted1[lp] <= nums2[rp])
            {
                nums1[i] = sorted1[lp];
                lp++;
            }
            else
            {
                nums1[i] = nums2[rp];
                rp++;
            }
        }//

        //Another solution
        for(int i = m, j = 0; j < n; i++, j++)
        {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};
