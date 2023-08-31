/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (67.65%)
 * Likes:    955
 * Dislikes: 109
 * Total Accepted:    75.9K
 * Total Submissions: 112.1K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (auto& s : A) {
            vector<int> cnt1(26, 0);
            for (auto c : s) ++cnt1[c - 'a'];
            for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
        }
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
        return res;
    }
};
// @lc code=end

