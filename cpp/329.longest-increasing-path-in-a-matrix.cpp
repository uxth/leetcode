/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (43.40%)
 * Likes:    2054
 * Dislikes: 38
 * Total Accepted:    153.5K
 * Total Submissions: 353.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int y, int x)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(dp[y][x]) return dp[y][x];
        for(auto& d : dir)
        {
            int yy = y + d.first;
            int xx = x + d.second;
            if(yy<0||xx<0||yy>=m||xx>=n) continue;
            if(matrix[yy][xx] <= matrix[y][x]) continue;
            dp[y][x] = max(dp[y][x], dfs(matrix, dp, yy, xx));
        }
        return ++dp[y][x];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = INT_MIN;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};
// @lc code=end

