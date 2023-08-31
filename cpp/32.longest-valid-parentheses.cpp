/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.03%)
 * Likes:    4383
 * Dislikes: 165
 * Total Accepted:    331.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        for(int i=0;i<s.size(); ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                    if(st.empty()) res = max(res, i+1);
                    else res = max(res, i-st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end

