/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 *
 * https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
 *
 * algorithms
 * Hard (61.17%)
 * Likes:    326
 * Dislikes: 19
 * Total Accepted:    10.7K
 * Total Submissions: 17.5K
 * Testcase Example:  '1'
 *
 * You have a grid of size n x 3 and you want to paint each cell of the grid
 * with exactly one of the three colours: Red, Yellow or Green while making
 * sure that no two adjacent cells have the same colour (i.e no two cells that
 * share vertical or horizontal sides have the same colour).
 * 
 * You are given n the number of rows of the grid.
 * 
 * Return the number of ways you can paint this grid. As the answer may grow
 * large, the answer must be computed modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 12
 * Explanation: There are 12 possible way to paint the grid as shown:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 54
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: 246
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 7
 * Output: 106494
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 5000
 * Output: 30228214
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * grid[i].length == 3
 * 1 <= n <= 5000
 * 
 */

// @lc code=start
class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        vector<long> dp{6, 6};
        for(int i=1; i<n;++i)
        {
            long same = (dp[0] * 3 + dp[1] * 2) % mod;
            long diff = (dp[0] * 2 + dp[1] * 2) % mod;
            dp[0] = same;
            dp[1] = diff;
        }
        return (dp[0] + dp[1]) % mod;
    }
};
// @lc code=end

