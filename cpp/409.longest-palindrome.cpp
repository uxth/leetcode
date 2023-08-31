/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (50.32%)
 * Likes:    1269
 * Dislikes: 91
 * Total Accepted:    178.5K
 * Total Submissions: 344.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 * 
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a"
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "bb"
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2000
 * s consits of lower-case and/or upper-case English letters only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(char c : s) ++m[c];
        int res = 0;
        for(auto& [c, count] : m)
        {
            if(count % 2 == 0 || res % 2 == 0) res+=count;
            else res += count - 1;
        }
        return res;
    }
};
// @lc code=end
// "bananas"

