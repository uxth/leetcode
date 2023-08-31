/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 *
 * https://leetcode.com/problems/valid-permutations-for-di-sequence/description/
 *
 * algorithms
 * Hard (49.62%)
 * Likes:    287
 * Dislikes: 28
 * Total Accepted:    5.9K
 * Total Submissions: 11.8K
 * Testcase Example:  '"DID"'
 *
 * We are given S, a length n string of characters from the set {'D', 'I'}.
 * (These letters stand for "decreasing" and "increasing".)
 * 
 * A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0,
 * 1, ..., n}, such that for all i:
 * 
 * 
 * If S[i] == 'D', then P[i] > P[i+1], and;
 * If S[i] == 'I', then P[i] < P[i+1].
 * 
 * 
 * How many valid permutations are there?  Since the answer may be large,
 * return your answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "DID"
 * Output: 5
 * Explanation: 
 * The 5 valid permutations of (0, 1, 2, 3) are:
 * (1, 0, 3, 2)
 * (2, 0, 3, 1)
 * (2, 1, 3, 0)
 * (3, 0, 2, 1)
 * (3, 1, 2, 0)
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * S consists only of characters from the set {'D', 'I'}.
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size(), m = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
                if(S[i-1] == 'D')
                    for(int k = j; k <= i-1; k++)
                        dp[i][j] = dp[i][j]%m + dp[i-1][k]%m;
                else
                    for(int k = 0; k <= j-1; k++)
                        dp[i][j] = dp[i][j]%m + dp[i-1][k]%m;
        int res = 0;
        for(int i = 0; i <= n; i++)
            res = res%m + dp[n][i]%m;
        return res%m;
    }
};
// @lc code=end

