/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (63.33%)
 * Likes:    475
 * Dislikes: 113
 * Total Accepted:    15.6K
 * Total Submissions: 24.6K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alex and Lee continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alex and Lee play optimally, return the maximum number of stones
 * Alex can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alex takes one pile at the beginning, Lee takes two piles,
 * then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total.
 * If Alex takes two piles at the beginning, then Lee can take all three piles
 * left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since
 * it's larger. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10 ^ 4
 * 
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<int>& sum, int m, int p, vector<vector<int>>& dp)
    {
        if(p+2*m >= sum.size()) return sum[p];
        if(dp[p][m]) return dp[p][m];
        for(int i=1; i<=2*m; ++i)
            dp[p][m] = max(dp[p][m], sum[p] - dfs(sum, max(i,m), p+i, dp));
        return dp[p][m];
    }
    int stoneGameII(vector<int>& piles) {
        if(piles.empty()) return 0;
        int n = piles.size();
        vector<int> sum(piles);
        for(int i=n-2; i>=0; --i) sum[i]+=sum[i+1];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return dfs(sum, 1, 0, dp);
    }
};
// @lc code=end

