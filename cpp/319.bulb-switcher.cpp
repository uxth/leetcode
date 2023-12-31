/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 *
 * https://leetcode.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (45.37%)
 * Likes:    519
 * Dislikes: 1071
 * Total Accepted:    82.7K
 * Total Submissions: 182.5K
 * Testcase Example:  '3'
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs.
 * Then, you turn off every second bulb. On the third round, you toggle every
 * third bulb (turning on if it's off or turning off if it's on). For the i-th
 * round, you toggle every i bulb. For the n-th round, you only toggle the last
 * bulb. Find how many bulbs are on after n rounds.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 1 
 * Explanation: 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 * 
 * So you should return 1, because there is only one bulb is on.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int bulbSwitch(int n) {
    //     int counts = 0;
    //     for (int i=1; i*i<=n; ++i)++counts; 
    //     return counts;
    // }
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
// @lc code=end

