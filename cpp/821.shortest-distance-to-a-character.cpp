/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (66.91%)
 * Likes:    1172
 * Dislikes: 79
 * Total Accepted:    70.9K
 * Total Submissions: 105.3K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size(), pos = -n;
        vector<int> res(n, n);
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) pos = i;
            res[i] = i - pos;
        }
        for (int i = pos - 1; i >= 0; --i) {
            if (S[i] == C)  pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
};
// @lc code=end

