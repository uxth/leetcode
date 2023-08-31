/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 *
 * https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
 *
 * algorithms
 * Hard (39.29%)
 * Likes:    109
 * Dislikes: 6
 * Total Accepted:    3.3K
 * Total Submissions: 8.4K
 * Testcase Example:  '["acca","bbbb","caca"]\n"aba"'
 *
 * You are given a list of strings of the same length words and a string
 * target.
 * 
 * Your task is to form target using the given words under the following
 * rules:
 * 
 * 
 * target should be formed from left to right.
 * To form the i^th character (0-indexed) of target, you can choose the k^th
 * character of the j^th string in words if target[i] = words[j][k].
 * Once you use the k^th character of the j^th string of words, you can no
 * longer use the x^th character of any string in words where x <= k. In other
 * words, all characters to the left of or at index k become unusuable for
 * every string.
 * Repeat the process until you form the string target.
 * 
 * 
 * Notice that you can use multiple characters from the same string in words
 * provided the conditions above are met.
 * 
 * Return the number of ways to form target from words. Since the answer may be
 * too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["acca","bbbb","caca"], target = "aba"
 * Output: 6
 * Explanation: There are 6 ways to form target.
 * "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
 * "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
 * "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
 * "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
 * "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
 * "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["abba","baab"], target = "bab"
 * Output: 4
 * Explanation: There are 4 ways to form target.
 * "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
 * "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
 * "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
 * "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["abcd"], target = "abcd"
 * Output: 1
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: words = ["abab","baba","abba","baab"], target = "abba"
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * All strings in words have the same length.
 * 1 <= target.length <= 1000
 * words[i] and target contain only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9+7;
        int m = target.size();
        int n = words[0].size();
        int t = words.size();
        // dp[i][j] -- numbers of ways to form target[0, i) using all word[0, j)
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        for (int j=0; j<=n; j++) {
            dp[0][j] = 1; // able to form a empty string anyway
        }
        
        // arr[i][j] -- numbers of 'a'+j in position i across all words
        vector<vector<int>> arr(n, vector<int>(26, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<t; j++) {
                arr[i][(words[j][i]-'a')]++;
            }
        }
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = (arr[j-1][target[i-1]-'a'] * dp[i-1][j-1]) % mod;
                dp[i][j] = (dp[i][j] +  dp[i][j-1]) % (mod);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
// ["abba","baab"]\n"bab"
