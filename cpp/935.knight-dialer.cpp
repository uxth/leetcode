/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 *
 * https://leetcode.com/problems/knight-dialer/description/
 *
 * algorithms
 * Medium (45.14%)
 * Likes:    607
 * Dislikes: 262
 * Total Accepted:    36.6K
 * Total Submissions: 80.7K
 * Testcase Example:  '1'
 *
 * The chess knight has a unique movement, it may move two squares vertically
 * and one square horizontally, or two squares horizontally and one square
 * vertically (with both forming the shape of an L). The possible movements of
 * chess knight are shown in this diagaram:
 * 
 * A chess knight can move as indicated in the chess diagram below:
 * 
 * We have a chess knight and a phone pad as shown below, the knight can only
 * stand on a numeric cell (i.e. blue cell).
 * 
 * Given an integer n, return how many distinct phone numbers of length n we
 * can dial.
 * 
 * You are allowed to place the knight on any numeric cell initially and then
 * you should perform n - 1 jumps to dial a number of length n. All jumps
 * should be valid knight jumps.
 * 
 * As the answer may be very large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 10
 * Explanation: We need to dial a number of length 1, so placing the knight
 * over any numeric cell of the 10 cells is sufficient.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 20
 * Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29,
 * 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: 46
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 4
 * Output: 104
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 3131
 * Output: 136006598
 * Explanation: Please take care of the mod.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 5000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<int> d1(10, 1), d2(10);
        for (; --n > 0; swap(d1, d2))
            for (auto i = 0; i < d1.size(); ++i) 
                d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, [&](int s, int i) {return (s + d1[i]) % 1000000007;});
    
        return accumulate(begin(d1), end(d1), 0, [](int s, int e) {return (s + e) % 1000000007;});
    }
};

// @lc code=end

