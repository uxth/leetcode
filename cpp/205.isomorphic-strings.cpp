/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (42.05%)
 * Likes:    7867
 * Dislikes: 1820
 * Total Accepted:    1M
 * Total Submissions: 2.4M
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 * 
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> ms, mt;
        for(int i=0; i<s.size(); ++i){
            if(ms.count(s[i]) && ms[s[i]] != t[i] ||
                mt.count(t[i]) && mt[t[i]] != s[i]
            ) return false;
            ms[s[i]] = t[i];
            mt[t[i]] = s[i];
        }
        return true;
    }
};
// @lc code=end
/*
""badc"\n"baba""
*/
