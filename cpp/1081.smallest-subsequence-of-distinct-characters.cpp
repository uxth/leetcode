/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 *
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (50.37%)
 * Likes:    644
 * Dislikes: 94
 * Total Accepted:    16.1K
 * Total Submissions: 30.2K
 * Testcase Example:  '"bcabc"'
 *
 * Return the lexicographically smallest subsequence of s that contains all the
 * distinct characters of s exactly once.
 * 
 * Note: This question is the same as 316:
 * https://leetcode.com/problems/remove-duplicate-letters/
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "bcabc"
 * Output: "abc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbacdcbc"
 * Output: "acdb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        int last[26] = {}, seen[26] = {}, n = s.size();
        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;
        for (int i = 0; i < n; ++i) {
            if (seen[s[i] - 'a']++) continue;
            while (!res.empty() && res.back() > s[i] && i < last[res.back() - 'a'])
                seen[res.back() - 'a'] = 0, res.pop_back();
            res.push_back(s[i]);
        }
        return res;
    }
};
// @lc code=end
// ""leetcode""
// ""babcdbdefbcbfadcaaccedccdfaafbdafeeddaceacafabfcff""