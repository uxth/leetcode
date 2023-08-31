/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (35.07%)
 * Likes:    583
 * Dislikes: 136
 * Total Accepted:    30.1K
 * Total Submissions: 85.2K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i0, int j0) {
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<vector<uint>>> dp(2, vector<vector<uint>>(m, vector<uint>(n, 0)));
        auto paths = [&](int k, int i, int j) { return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k % 2][i][j]; };
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k%2][i][j]=0;
                    for(auto& d : dir)
                        dp[k%2][i][j] = (dp[k%2][i][j] + paths(k-1, i+d[0], j+d[1])) % 1000000007;
                }
            }
        }
        return dp[N%2][i0][j0];
    }
};
// @lc code=end
// 2\n2\n3\n0\n0
