/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 *
 * https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/
 *
 * algorithms
 * Hard (55.28%)
 * Likes:    1758
 * Dislikes: 92
 * Total Accepted:    65.2K
 * Total Submissions: 103.9K
 * Testcase Example:  '["A..","AAA","..."]\n3'
 *
 * Given a rectangular pizza represented as a rows x cols matrix containing the
 * following characters: 'A' (an apple) and '.' (empty cell) and given the
 * integer k. You have to cut the pizza into k pieces using k-1 cuts. 
 * 
 * For each cut you choose the direction: vertical or horizontal, then you
 * choose a cut position at the cell boundary and cut the pizza into two
 * pieces. If you cut the pizza vertically, give the left part of the pizza to
 * a person. If you cut the pizza horizontally, give the upper part of the
 * pizza to a person. Give the last piece of pizza to the last person.
 * 
 * Return the number of ways of cutting the pizza such that each piece contains
 * at least one apple. Since the answer can be a huge number, return this
 * modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: pizza = ["A..","AAA","..."], k = 3
 * Output: 3 
 * Explanation: The figure above shows the three ways to cut the pizza. Note
 * that pieces must contain at least one apple.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pizza = ["A..","AA.","..."], k = 3
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pizza = ["A..","A..","..."], k = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= rows, cols <= 50
 * rows == pizza.length
 * cols == pizza[i].length
 * 1 <= k <= 10
 * pizza consists of characters 'A' and '.' only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        int mod = 1e9+7;
        vector<vector<int>> cnt(m+1, vector<int>(n+1));
        for(int i=m-1; i>=0; --i){
            int s = 0;
            for(int j=n-1; j>=0; --j){
                s += pizza[i][j] == 'A';
                cnt[i][j] = cnt[i+1][j] + s;
            }
        }
        vector<vector<vector<long>>> dp(m+1, vector<vector<long>>(n+1, vector<long>(k+1)));
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                dp[i][j][1] = cnt[i][j] > 0;
                for(int t=2; t<=k; ++t){
                    for(int ii=i+1; ii < m; ++ii){
                        if(cnt[i][j] == cnt[ii][j]) continue;
                        if(cnt[ii][j] == 0) break;
                        dp[i][j][t] = (dp[i][j][t] + dp[ii][j][t-1]) % mod;
                    }
                    for(int jj=j+1; jj<n; ++jj){
                        if(cnt[i][j] == cnt[i][jj]) continue;
                        if(cnt[i][jj] == 0) break;
                        dp[i][j][t] = (dp[i][j][t] + dp[i][jj][t-1]) % mod;
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
// @lc code=end

