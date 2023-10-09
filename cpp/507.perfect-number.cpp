/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (35.93%)
 * Likes:    341
 * Dislikes: 679
 * Total Accepted:    73.8K
 * Total Submissions: 204.8K
 * Testcase Example:  '28'
 *
 * A perfect number is a positive integer that is equal to the sum of its
 * positive divisors, excluding the number itself. A divisor of an integer x is
 * an integer that can divide x evenly.
 * 
 * Given an integer n, return true if n is a perfect number, otherwise return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 28
 * Output: true
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, and 14 are all divisors of 28.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 6
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = 496
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: num = 8128
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: num = 2
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int res = 1;
        for(int i=2; i*i<=num; ++i){
            if(num % i == 0) res += i + num/i;
        }
        return res == num;
    }
};
// @lc code=end

