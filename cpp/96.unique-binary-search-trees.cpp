/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n<=0)return 0;
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; ++i){
            for(int j=0; j<i; ++j){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp.back();
    }
};
// @lc code=end

