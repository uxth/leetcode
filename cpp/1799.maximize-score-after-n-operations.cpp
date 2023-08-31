/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& dp, int mask, int step){
        if(step == 0) return 0;
        if(dp[mask]) return dp[mask];
        for(int i=0; i<nums.size(); ++i){
            if(!(mask & (1<<i))) continue;
            for(int j=i+1; j<nums.size(); ++j){
                if(!(mask & (1<<j))) continue;
                dp[mask] = max(dp[mask], step*gcd(nums[i], nums[j]) + dfs(nums, dp, mask ^ (1<<i) ^ (1<<j), step-1));
            }
        }
        
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<nums.size());
        return dfs(nums, dp, (1<<nums.size())-1, nums.size()/2);

    }
};
// @lc code=end

