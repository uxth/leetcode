/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 *
 * https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
 *
 * algorithms
 * Medium (32.11%)
 * Likes:    116
 * Dislikes: 256
 * Total Accepted:    11K
 * Total Submissions: 34.2K
 * Testcase Example:  '1'
 *
 * Given a positive integer K, you need find the smallest positive integer N
 * such that N is divisible by K, and N only contains the digit 1.
 * 
 * Return the length of N.  If there is no such N, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: 1
 * Explanation: The smallest answer is N = 1, which has length 1.
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: -1
 * Explanation: There is no such positive integer N divisible by 2.
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: The smallest answer is N = 111, which has length 3.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 10^5
 * 
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        for (int r = 0, N = 1; N <= K; ++N)
            if ((r = (r * 10 + 1) % K) == 0)
                return N;
        return -1;
    }
};
// @lc code=end

