/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 *
 * https://leetcode.com/problems/restore-the-array/description/
 *
 * algorithms
 * Hard (36.65%)
 * Likes:    163
 * Dislikes: 3
 * Total Accepted:    5.9K
 * Total Submissions: 16.2K
 * Testcase Example:  '"1000"\n10000'
 *
 * A program was supposed to print an array of integers. The program forgot to
 * print whitespaces and the array is printed as a string of digits and all we
 * know is that all integers in the array were in the range [1, k] and there
 * are no leading zeros in the array.
 * 
 * Given the string s and the integer k. There can be multiple ways to restore
 * the array.
 * 
 * Return the number of possible array that can be printed as a string s using
 * the mentioned program.
 * 
 * The number of ways could be very large so return it modulo 10^9 + 7
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1000", k = 10000
 * Output: 1
 * Explanation: The only possible array is [1000]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "1000", k = 10
 * Output: 0
 * Explanation: There cannot be an array that was printed this way and has all
 * integer >= 1 and <= 10.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1317", k = 2000
 * Output: 8
 * Explanation: Possible arrays are
 * [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "2020", k = 30
 * Output: 1
 * Explanation: The only possible array is [20,20]. [2020] is invalid because
 * 2020 > 30. [2,020] is ivalid because 020 contains leading zeros.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "1234567890", k = 90
 * Output: 34
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5.
 * s consists of only digits and doesn't contain leading zeros.
 * 1 <= k <= 10^9.
 * 
 */

// @lc code=start
class Solution {
public:

    int dfs(string& s, int k, int start, vector<int>& dp)
    {
        if(start==s.size()) return 1;
        if(s[start] == '0') return 0;
        if(dp[start] != -1) return dp[start];
        long num = 0;
        dp[start]=0;
        for(int i=start; i<s.size(); ++i)
        {
            num = num*10+s[i]-'0';
            if(num > k) break;
            dp[start] += dfs(s, k, i+1, dp);
            dp[start] %= 1000000007;
        }

        return dp[start];
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return dfs(s, k, 0, dp);
    }
};
// @lc code=end
// "1234567890"\n90
