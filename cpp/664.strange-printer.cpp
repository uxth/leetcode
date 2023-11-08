/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (41.17%)
 * Likes:    530
 * Dislikes: 54
 * Total Accepted:    16.9K
 * Total Submissions: 41K
 * Testcase Example:  '"aaabbb"'
 *
 *
 * There is a strange printer with the following two special requirements:
 *
 *
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 *
 *
 *
 *
 *
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 *
 *
 * Example 1:
 *
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 *
 *
 *
 * Example 2:
 *
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 *
 *
 *
 * Hint: Length of the given string will not exceed 100.
 */

// @lc code=start
class Solution
{
public:
    int bottomupdp(string s)
    {
        if (s.empty())
            return 0;
        vector<vector<int>> m(s.length(), vector<int>(s.length() + 1, INT_MAX));
        for (int i = 0; i < s.length(); ++i)
            m[i][1] = 1;

        for (int len = 2; len <= s.length(); ++len)
        {
            for (int i = 0; i + len <= s.length(); ++i)
            {
                int val = (s[i] == s[i + len - 1]);
                for (int j = i + len - 1; j > i; --j)
                {
                    m[i][len] = min(m[i][len], m[i][j - i] + m[j][i + len - j] - val);
                }
            }
        }
        return m[0][s.length()];
    }

    int dfs(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if (l > r)
            return 0;
        if (dp[l][r])
            return dp[l][r];
        dp[l][r] = 1 + dfs(s, l + 1, r, dp);
        for (int i = l + 1; i <= r; ++i)
        {
            if (s[i] == s[l])
            {
                dp[l][r] = min(dp[l][r], dfs(s, l + 1, i, dp) + dfs(s, i + 1, r, dp));
            }
        }
        return dp[l][r];
    }
    int topdowndp(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        return dfs(s, 0, s.size() - 1, dp);
    }
    int strangePrinter(string s)
    {
        // return bottomupdp(s);
        return topdowndp(s);
    }
};
// @lc code=end
// ""ababa""
// ""tbgtgb""