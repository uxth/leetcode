/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.18%)
 * Likes:    240
 * Dislikes: 148
 * Total Accepted:    56.3K
 * Total Submissions: 121.9K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int n) {
        if (n < 0) return "-" + convertToBase7(-n);
        if (n < 7) return to_string(n);
        return convertToBase7(n / 7) + to_string(n % 7);
    }
};
// @lc code=end

