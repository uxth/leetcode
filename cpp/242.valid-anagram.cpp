/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (56.82%)
 * Likes:    1643
 * Dislikes: 144
 * Total Accepted:    594.4K
 * Total Submissions: 1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> m(256, 0);
        for(int i=0; i<s.size(); ++i)
        {
            m[s[i]]++; m[t[i]]--;
        }
        return all_of(m.begin(), m.end(), [](int i){return i==0;});
    }
};
// @lc code=end

