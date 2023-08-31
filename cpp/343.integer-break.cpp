/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (50.36%)
 * Likes:    1094
 * Dislikes: 228
 * Total Accepted:    110.5K
 * Total Submissions: 219.4K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1; dp[2] = 1;
        for(int i = 3; i<=n; ++i)
        {
            for(int j=i-1; j>=i-j; --j)
            {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end

