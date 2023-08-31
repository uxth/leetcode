/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 *
 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (64.00%)
 * Likes:    598
 * Dislikes: 24
 * Total Accepted:    27.2K
 * Total Submissions: 42.4K
 * Testcase Example:  '"(abcd)"'
 *
 * You are given a string s that consists of lower case English letters and
 * brackets. 
 * 
 * Reverse the strings in each pair of matching parentheses, starting from the
 * innermost one.
 * 
 * Your result should not contain any brackets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(abcd)"
 * Output: "dcba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "(u(love)i)"
 * Output: "iloveu"
 * Explanation: The substring "love" is reversed first, then the whole string
 * is reversed.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(ed(et(oc))el)"
 * Output: "leetcode"
 * Explanation: First, we reverse the substring "oc", then "etco", and finally,
 * the whole string.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "a(bcdefghijkl(mno)p)q"
 * Output: "apmnolkjihgfedcbq"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 2000
 * s only contains lower case English characters and parentheses.
 * It's guaranteed that all parentheses are balanced.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {

        string res = "";
        stack<string> st;
        
        for(char c : s)
        {
            if(c == '(') {
                st.push(res);
                res = "";
            } 
            else if(c == ')')
            {
                reverse(res.begin(), res.end());
                res = st.top() + res;
                st.pop();
            } 
            else 
            {
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end
// ""(u(love)i)""
// ""(ab(cd)((ef))gh)""