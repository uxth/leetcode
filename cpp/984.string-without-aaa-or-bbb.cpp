/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 *
 * https://leetcode.com/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (37.69%)
 * Likes:    214
 * Dislikes: 243
 * Total Accepted:    18.1K
 * Total Submissions: 48K
 * Testcase Example:  '1\n2'
 *
 * Given two integers A and B, return any string S such that:
 * 
 * 
 * S has length A + B and contains exactly A 'a' letters, and exactly B 'b'
 * letters;
 * The substring 'aaa' does not occur in S;
 * The substring 'bbb' does not occur in S.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = 1, B = 2
 * Output: "abb"
 * Explanation: "abb", "bab" and "bba" are all correct answers.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = 4, B = 1
 * Output: "aabaa"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A <= 100
 * 0 <= B <= 100
 * It is guaranteed such an S exists for the given A and B.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A==0) return string(B, 'b');
        if(B==0) return string(A, 'a');
        if(A==B)
        {
            string res;
            while(A--) res+="ab";
            return res;
        }

        return A>B ? "aab" + strWithout3a3b(A-2, B-1) : "bba" + strWithout3a3b(A-1, B-2);
    }
};
// @lc code=end

