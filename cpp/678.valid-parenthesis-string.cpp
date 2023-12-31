/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (30.97%)
 * Likes:    1956
 * Dislikes: 54
 * Total Accepted:    116.8K
 * Total Submissions: 375.4K
 * Testcase Example:  '"()"'
 *
 * 
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 * 
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "()"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "(*)"
 * Output: True
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "(*))"
 * Output: True
 * 
 * 
 * 
 * Note:
 * 
 * The string size will be in the range [1, 100].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int cmin=0, cmax=0;
        for(auto& c:s)
        {
            if(c=='(')
            {
                cmin++;
                cmax++;
            }
            else if(c==')')
            {
                cmax--;
                cmin = max(cmin-1,0);
            }
            else
            {
                cmax++;
                cmin = max(cmin-1,0);
            }
            if(cmax<0)
                return false;
        }
        
        return cmin==0;
    }
};
// @lc code=end
// "(())((())()()(*)(*()(())())())()()((()())((()))(*"
