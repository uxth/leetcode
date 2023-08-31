/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (33.92%)
 * Likes:    1407
 * Dislikes: 1952
 * Total Accepted:    576K
 * Total Submissions: 1.7M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        if(x == 1) return 1;
        int left = 0; int right = x;
        while(left<=right) {
            double mid = left + (right-left)/2;
            if(mid*mid==x) {
                return mid;
            }
            if(mid*mid>x) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return left-1;
    }
};
// @lc code=end

