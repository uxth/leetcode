/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (62.51%)
 * Likes:    983
 * Dislikes: 28
 * Total Accepted:    87K
 * Total Submissions: 139K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters. 
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * 
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "(a(b(c)d)"
 * Output: "a(b(c)d)"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is one of  '(' , ')' and lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    string useScan(string& s) {
        int i = s.size();
        int balance = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ')') balance++;
            else if (s[j] == '(') {
                if (balance == 0) continue;
                balance--;
            }
            s[--i] = s[j];
        }
        int len = 0;
        balance = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') {
                if (balance == 0) continue;
                balance--;
            }
            s[len++] = s[i];
        }
        s.erase(len);
        return s;
    }
    string useStack(string& s) {
        stack<int> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty()) s[i] = '*';
                else st.pop();
            }
        }
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(begin(s), end(s), '*'), end(s));
        return s;
    }
    string minRemoveToMakeValid(string s) {
        // return useScan(s);
        return useStack(s);
    }
};
// @lc code=end

