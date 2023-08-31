/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 *
 * https://leetcode.com/problems/clumsy-factorial/description/
 *
 * algorithms
 * Medium (53.40%)
 * Likes:    90
 * Dislikes: 138
 * Total Accepted:    13.1K
 * Total Submissions: 24.6K
 * Testcase Example:  '4'
 *
 * Normally, the factorial of a positive integer n is the product of all
 * positive integers less than or equal to n.  For example, factorial(10) = 10
 * * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
 * 
 * We instead make a clumsy factorial: using the integers in decreasing order,
 * we swap out the multiply operations for a fixed rotation of operations:
 * multiply (*), divide (/), add (+) and subtract (-) in this order.
 * 
 * For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However,
 * these operations are still applied using the usual order of operations of
 * arithmetic: we do all multiplication and division steps before any addition
 * or subtraction steps, and multiplication and division steps are processed
 * left to right.
 * 
 * Additionally, the division that we use is floor division such that 10 * 9 /
 * 8 equals 11.  This guarantees the result is an integer.
 * 
 * Implement the clumsy function as defined above: given an integer N, it
 * returns the clumsy factorial of N.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 7
 * Explanation: 7 = 4 * 3 / 2 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 12
 * Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10000
 * -2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a
 * 32-bit integer.)
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N == 4) return 7;
        if (N % 4 == 1) return N + 2;
        if (N % 4 == 2) return N + 2;
        if (N % 4 == 3) return N - 1;
        return N + 1;
    }
};
// @lc code=end
// 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  
