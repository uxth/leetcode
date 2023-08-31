/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (54.42%)
 * Likes:    3480
 * Dislikes: 65
 * Total Accepted:    452.4K
 * Total Submissions: 824.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int j=1;j<n;++j) dp[0][j] = min(dp[0][j], dp[0][j-1]+grid[0][j]);
        for(int i=1;i<m;++i) dp[i][0] = min(dp[i][0], dp[i-1][0]+grid[i][0]);
        for(int i=1;i<m;++i) for(int j=1;j<n;++j)
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+grid[i][j]);
        return dp.back().back();
    }
};
// @lc code=end

