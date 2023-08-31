/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 *
 * https://leetcode.com/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (34.71%)
 * Likes:    474
 * Dislikes: 359
 * Total Accepted:    17.2K
 * Total Submissions: 49.4K
 * Testcase Example:  '1'
 *
 * 
 * You are standing at position 0 on an infinite number line.  There is a goal
 * at position target.
 * 
 * On each move, you can either go left or right.  During the n-th move
 * (starting from 1), you take n steps.
 * 
 * Return the minimum number of steps required to reach the destination.
 * 
 * 
 * Example 1:
 * 
 * Input: target = 3
 * Output: 2
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second step we step from 1 to 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: target = 2
 * Output: 3
 * Explanation:
 * On the first move we step from 0 to 1.
 * On the second move we step  from 1 to -1.
 * On the third move we step from -1 to 2.
 * 
 * 
 * 
 * Note:
 * target will be a non-zero integer in the range [-10^9, 10^9].
 * 
 */

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        long tar = std::abs(long(target));
        int n = (-1 + std::sqrt(1 + 8 * tar)) / 2;
        if(tar == (n + 1) * n / 2)
            return n;
        int res = (n + 1) * (n + 2) / 2 - tar;
        if(res % 2 == 0)
            return n + 1;
        
        return n % 2 == 1 ? n + 2 : n + 3;

    }
};
// @lc code=end

