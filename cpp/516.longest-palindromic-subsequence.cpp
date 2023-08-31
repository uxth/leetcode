/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (53.16%)
 * Likes:    2224
 * Dislikes: 189
 * Total Accepted:    127.9K
 * Total Submissions: 238.9K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input:
 * 
 * 
 * "bbbab"
 * 
 * Output:
 * 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * 
 * Example 2:
 * Input:
 * 
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; ++i) dp[i][i] = 1;
        for(int d=1; d<n; ++d)
        {
            for(int i=0; i<n-d; ++i)
            {
                int j=i+d;
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + (d==1 ? 0 : dp[i+1][j-1]);
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                
            }
        }
        // for(int i=0;i<n;++i) {for(int j=0;j<n;++j) cout << dp[i][j] << " "; cout << endl;}
        return dp[0][n-1];
    }
};
// @lc code=end
// "cbbd"
