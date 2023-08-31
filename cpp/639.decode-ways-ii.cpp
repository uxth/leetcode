/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (26.60%)
 * Likes:    470
 * Dislikes: 530
 * Total Accepted:    33.2K
 * Total Submissions: 123.7K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), M = 1e9 + 7;
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        if (s[0] == '0') return 0;
        dp[1] = (s[0] == '*') ? 9 : 1;
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2') {
                    dp[i] += dp[i - 2];
                }
                else if (s[i - 2] == '*') {
                    dp[i] += 2 * dp[i - 2];
                }
                else {
                    return 0;
                }
            }
            else if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
                if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                    dp[i] += dp[i - 2];
                }
                else if (s[i - 2] == '*') {
                    dp[i] += (s[i - 1] <= '6') ? (2 * dp[i - 2]) : dp[i - 2];
                }
            }
            else { // s[i - 1] == '*'
                dp[i] += 9 * dp[i - 1];
                if (s[i - 2] == '1') dp[i] += 9 * dp[i - 2];
                else if (s[i - 2] == '2') dp[i] += 6 * dp[i - 2];
                else if (s[i - 2] == '*') dp[i] += 15 * dp[i - 2];
            }
            dp[i] %= M;
        }
        return dp[n];
    }
};
// @lc code=end

