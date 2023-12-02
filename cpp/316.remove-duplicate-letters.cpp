/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (43.82%)
 * Likes:    8330
 * Dislikes: 582
 * Total Accepted:    309.9K
 * Total Submissions: 632.3K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string s, remove duplicate letters so that every letter appears once
 * and only once. You must make sure your result is the smallest in
 * lexicographical order among all possible results.
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
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 * 
 * 
 * 
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastIndex(256);
        vector<char> stk;
        vector<bool> visited(256);
        for(int i=0; i<n; ++i) lastIndex[s[i]] = i;
        for(int i=0; i<n; ++i){
            if(visited[s[i]]) continue;
            while(!stk.empty() && stk.back() > s[i] && lastIndex[stk.back()] > i){
                visited[stk.back()] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            visited[s[i]] = true;
        }
        return string(begin(stk), end(stk));
    }
};
// @lc code=end
/*
""cbacdcbc""
*/
