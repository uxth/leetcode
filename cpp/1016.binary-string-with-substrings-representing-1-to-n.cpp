/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 *
 * https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (58.87%)
 * Likes:    119
 * Dislikes: 328
 * Total Accepted:    16.4K
 * Total Submissions: 28K
 * Testcase Example:  '"0110"\n3'
 *
 * Given a binary string S (a string consisting only of '0' and '1's) and a
 * positive integer N, return true if and only if for every integer X from 1 to
 * N, the binary representation of X is a substring of S.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "0110", N = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "0110", N = 4
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 1000
 * 1 <= N <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1; i<=N; ++i)
        {
            string str ;
            int j = i;
            while(j)
            {
                str += '0'+ j%2;
                j = j/2;
            }
            reverse(str.begin(), str.end());
            if(S.find(str) == string::npos) return false;
        }
        return true;
    }
};
// @lc code=end

