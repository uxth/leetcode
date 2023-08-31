/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 *
 * https://leetcode.com/problems/mirror-reflection/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    198
 * Dislikes: 308
 * Total Accepted:    10K
 * Total Submissions: 18.3K
 * Testcase Example:  '2\n1'
 *
 * There is a special square room with mirrors on each of the four walls.
 * Except for the southwest corner, there are receptors on each of the
 * remaining corners, numbered 0, 1, and 2.
 * 
 * The square room has walls of length p, and a laser ray from the southwest
 * corner first meets the east wall at a distance q from the 0th receptor.
 * 
 * Return the number of the receptor that the ray meets first.  (It is
 * guaranteed that the ray will meet a receptor eventually.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p = 2, q = 1
 * Output: 2
 * Explanation: The ray meets receptor 2 the first time it gets reflected back
 * to the left wall.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= p <= 1000
 * 0 <= q <= p
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    2*p = odd * q; => p = even || odd, q = even;
    p = odd * q; => p = q = even || odd;
    p = even * q; => p = even, q = even || odd;
    */
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        if (p % 2 == 0) {
            return 2;
        } else if (q % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    }
};
// @lc code=end

