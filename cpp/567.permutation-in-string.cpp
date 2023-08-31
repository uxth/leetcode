/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.51%)
 * Likes:    2085
 * Dislikes: 75
 * Total Accepted:    169K
 * Total Submissions: 379.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    
    if(s1.length() > s2.length()) return false;
    
    // fill the s1 map;
    for (auto c : s1)
        ++m1[c];
    
    for (int i=0; i<s2.size(); ++i) {
        ++m2[s2[i]];
        
        int index = i-s1.length();
        if (index >= 0) {
            if (m2[s2[index]] == 1) {
                m2.erase(s2[index]);
            } else {
                --m2[s2[index]];
            }
        }
        
        if (m1 == m2) return true;
    }
    
    return false;
    }
};
// @lc code=end
// ""ab"\n"eidboaoo""
// ""adc"\n"dcda""