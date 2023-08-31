/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 *
 * https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
 *
 * algorithms
 * Medium (74.63%)
 * Likes:    307
 * Dislikes: 24
 * Total Accepted:    30.9K
 * Total Submissions: 41.2K
 * Testcase Example:  '"bab"\n"aba"'
 *
 * Given two equal-size strings s and t. In one step you can choose any
 * character of t and replace it with another character.
 * 
 * Return the minimum number of steps to make t an anagram of s.
 * 
 * An Anagram of a string is a string that contains the same characters with a
 * different (or the same) ordering.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "bab", t = "aba"
 * Output: 1
 * Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram
 * of s.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "leetcode", t = "practice"
 * Output: 5
 * Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper
 * characters to make t anagram of s.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "anagram", t = "mangaar"
 * Output: 0
 * Explanation: "anagram" and "mangaar" are anagrams. 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "xxyyzz", t = "xxyyzz"
 * Output: 0
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "friend", t = "family"
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 50000
 * s.length == t.length
 * s and t contain lower-case English letters only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> m (26);
        int sum=0;
        for(auto c:s) m[c - 'a']++;
        for(auto c:t) m[c - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (m[i] < 0) {
                //char exist in t not s
                sum += m[i];
            }
        }
        return abs(sum);
    }
};
// @lc code=end
// "leetcode"\n"practice"
