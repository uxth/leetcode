/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (42.74%)
 * Likes:    547
 * Dislikes: 8
 * Total Accepted:    18.4K
 * Total Submissions: 42.9K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In
 * one step, you can move up, down, left or right from and to an empty cell.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m-1, n-1) given that you can eliminate at most k
 * obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,0,0],
 * [1,1,0],
 * ⁠[0,0,0],
 * [0,1,1],
 * ⁠[0,0,0]], 
 * k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10. 
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,1,1],
 * [1,1,1],
 * [1,0,0]], 
 * k = 1
 * Output: -1
 * Explanation: 
 * We need to eliminate at least two obstacles to find such a walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * grid.length == m
 * grid[0].length == n
 * 1 <= m, n <= 40
 * 1 <= k <= m*n
 * grid[i][j] == 0 or 1
 * grid[0][0] == grid[m-1][n-1] == 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][0][0] = grid[0][0] ? -1 : 0;
        for(int i=1; i<m; ++i) dp[0][i][0] = grid[i][0] ? -1 : dp[0][i-1][0]+1;
        for(int j=1; j<n; ++j) dp[0][0][j] = grid[0][j] ? -1 : dp[0][0][j-1]+1;
        for(int i=1; i<m; ++i) for(int j=1; j<n; ++j) dp[0][i][j] = grid[i][j] ? -1 : min(dp[0][i-1][j], dp[0][i][j-1]) + 1;

        for(int l=1; l<=k; ++l)
        {
            for(int i=1; i<m; ++i)
            {
                if(grid[i][0])
                {
                    dp[l][i][0] = l>0? dp[l-1][i-1][0] + 1 : grid[i-1]
                }
                else
                {
                    
                }
                
            }
        }
    }
};
// @lc code=end

