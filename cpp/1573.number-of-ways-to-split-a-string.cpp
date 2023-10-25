/*
 * @lc app=leetcode id=1573 lang=cpp
 *
 * [1573] Number of Ways to Split a String
 *
 * https://leetcode.com/problems/number-of-ways-to-split-a-string/description/
 *
 * algorithms
 * Medium (32.06%)
 * Likes:    697
 * Dislikes: 75
 * Total Accepted:    26.3K
 * Total Submissions: 80.8K
 * Testcase Example:  '"10101"'
 *
 * Given a binary string s, you can split s into 3 non-empty strings s1, s2,
 * and s3 where s1 + s2 + s3 = s.
 * 
 * Return the number of ways s can be split such that the number of ones is the
 * same in s1, s2, and s3. Since the answer may be too large, return it modulo
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "10101"
 * Output: 4
 * Explanation: There are four ways to split s in 3 parts where each part
 * contain the same number of letters '1'.
 * "1|010|1"
 * "1|01|01"
 * "10|10|1"
 * "10|1|01"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "1001"
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "0000"
 * Output: 3
 * Explanation: There are three ways to split s in 3 parts.
 * "0|0|00"
 * "0|00|0"
 * "00|0|0"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numWays(string s) {
        int mod = 1e9+7;
        int total = 0;
        for(char c : s) total += c=='1'?1:0;
        if(total % 3 != 0) return 0;
        if(total == 0){
            long n = s.size();
            return (n-1)*(n-2)/2 % mod;
        }
        int i = 0, count = 0;

        while(count<total/3) count += s[i++]=='1';
        int j=i;
        while(s[j]=='0') j++;
        long num1 =j-i+1;
        i=j;
        count = 0;
        while(count<total/3) count+= s[i++]=='1';
        j=i;
        while(s[j]=='0') j++;
        long num2 = j-i+1;
        return num1 * num2 % mod; 
    }
};
// @lc code=end
/*
""10101""
""00000""
""111""
*/

