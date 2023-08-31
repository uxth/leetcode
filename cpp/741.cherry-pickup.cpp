/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 *
 * https://leetcode.com/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (34.87%)
 * Likes:    1435
 * Dislikes: 89
 * Total Accepted:    34.1K
 * Total Submissions: 97.5K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * You are given an n x n grid representing a field of cherries, each cell is
 * one of three possible integers.
 * 
 * 
 * 0 means the cell is empty, so you can pass through,
 * 1 means the cell contains a cherry that you can pick up and pass through,
 * or
 * -1 means the cell contains a thorn that blocks your way.
 * 
 * 
 * Return the maximum number of cherries you can collect by following the rules
 * below:
 * 
 * 
 * Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right
 * or down through valid path cells (cells with value 0 or 1).
 * After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up
 * through valid path cells.
 * When passing through a path cell containing a cherry, you pick it up, and
 * the cell becomes an empty cell 0.
 * If there is no valid path between (0, 0) and (n - 1, n - 1), then no
 * cherries can be collected.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
 * Output: 5
 * Explanation: The player started at (0, 0) and went down, down, right right
 * to reach (2, 2).
 * 4 cherries were picked up during this single trip, and the matrix becomes
 * [[0,1,-1],[0,0,-1],[0,0,0]].
 * Then, the player went left, up, up, left to return home, picking up one more
 * cherry.
 * The total number of cherries picked up is 5, and this is the maximum
 * possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 50
 * grid[i][j] is -1, 0, or 1.
 * grid[0][0] != -1
 * grid[n - 1][n - 1] != -1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int bottomupdp(vector<vector<int>>& grid) {
        int n = grid.size(), mx = 2 * n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        for (int k = 1; k < mx; ++k) {
            for (int i = n - 1; i >= 0; --i) {
                for (int p = n - 1; p >= 0; --p) {
                    int j = k - i, q = k - p;
                    if (j < 0 || j >= n || q < 0 || q >= n || grid[i][j] < 0 || grid[p][q] < 0) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }
        return max(dp[n - 1][n - 1], 0);
    }


    
    int dfs(vector<vector<int>> &grid, int r1, int c1, int r2, int c2, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        if(r1<0 || r1>=n || r2<0 || r2>=n || c1<0 || c1>=n || c2<0 || c2>=n || 
           grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];
        
        int maxCherries = r1 == r2 && c1 == c2 ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        
        maxCherries += max({dfs(grid, r1, c1+1, r2, c2+1, dp),
                           dfs(grid, r1, c1+1, r2+1, c2, dp),
                           dfs(grid, r1+1, c1, r2, c2+1, dp),
                           dfs(grid, r1+1, c1, r2+1, c2, dp)});
        
        dp[r1][c1][r2] = maxCherries;
        return maxCherries;
    }
    
    int topdowndp(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        int ans = dfs(grid, 0, 0, 0, 0, dp);

        return max(ans, 0);
    }

    int cherryPickup(vector<vector<int>>& grid)
    {
        // return topdowndp(grid);
        return bottomupdp(grid);
    }
};
// @lc code=end

