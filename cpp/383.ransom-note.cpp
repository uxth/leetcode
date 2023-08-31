/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (53.08%)
 * Likes:    650
 * Dislikes: 201
 * Total Accepted:    228.9K
 * Total Submissions: 431.1K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(char c : ransomNote) m[c]++;
        for(char c : magazine)
        {
            if(m.count(c))
            {
                if(--m[c] == 0)
                    m.erase(c);
            }
        }
        return m.empty();
    }
};
// @lc code=end

