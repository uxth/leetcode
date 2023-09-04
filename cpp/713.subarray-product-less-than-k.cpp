/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int res = 0;
        for(int right = 0, left = 0, prod = 1; right<nums.size(); ++right){
            prod *= nums[right];
            while(prod >= k) prod /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end

