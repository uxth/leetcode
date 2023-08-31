/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (49.87%)
 * Likes:    929
 * Dislikes: 44
 * Total Accepted:    24.6K
 * Total Submissions: 49.3K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    double dfs(vector<int>& A, int K, int n, vector<vector<double>>& dp)
    {
        if(dp[n][K]) return dp[n][K];
        if(n < K) return 0;
        double sum = 0;
        for(int i=n-1; i>0; --i)
        {
            sum += A[i];
            dp[n][K] = max(dp[n][K], sum/(n-i) + dfs(A, K-1, i, dp));
        }
        return dp[n][K];
    }
    double largestSumOfAverages(vector<int>& A, int K)
    {
        int n = A.size();
        if(n == 0) return 0;
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));

        double sum = 0;
        for(int i = 0; i<n; ++i)
        {
            sum += A[i];
            dp[i+1][1] = sum / (i+1);
        }
        return dfs(A, K, n, dp);
    }

};
// @lc code=end

