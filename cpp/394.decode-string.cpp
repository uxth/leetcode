/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (56.21%)
 * Likes:    12081
 * Dislikes: 552
 * Total Accepted:    729.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 * 
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string helper(int& pos, string& s){
        int num = 0;
        string word = "";
        for(; pos < s.size(); ++pos){
            char cur = s[pos];
            if(cur == '['){
                string curStr = helper(++pos, s);
                for(; num>0; num--) word += curStr;
            }else if(cur >= '0' && cur <= '9'){
                num = num*10 + cur - '0';
            }else if(cur == ']'){
                return word;
            }else {
                word += cur;
            }
        }
        return word;
    }
    string dfs(string& s){
        int pos = 0;
        return helper(pos, s);
    }

    string useStack(string& s){
        stack<int> counts;
        stack<string> resultStack;

        string result = "";
        int count = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                count = count * 10 + (ch - '0');
            } else if (ch == '[') {
                counts.push(count);
                resultStack.push(result);
                count = 0;
                result = "";
            } else if (ch == ']') {
                int repeatCount = counts.top();
                counts.pop();

                string repeatedString = "";
                for (int i = 0; i < repeatCount; ++i) {
                    repeatedString += result;
                }

                result = resultStack.top() + repeatedString;
                resultStack.pop();
            } else {
                result += ch;
            }
        }

        return result;
    }
    string decodeString(string s) {
        // return dfs(s);
        return useStack(s);
    }
};
// @lc code=end

