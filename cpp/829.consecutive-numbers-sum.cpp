/*
 * @lc app=leetcode id=829 lang=cpp
 *
 * [829] Consecutive Numbers Sum
 *
 * https://leetcode.com/problems/consecutive-numbers-sum/description/
 *
 * algorithms
 * Hard (39.45%)
 * Likes:    559
 * Dislikes: 702
 * Total Accepted:    41.8K
 * Total Submissions: 106.5K
 * Testcase Example:  '5'
 *
 * Given a positive integer N, how many ways can we write it as a sum of
 * consecutive positive integers?
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: 2
 * Explanation: 5 = 5 = 2 + 3
 * 
 * Example 2:
 * 
 * 
 * Input: 9
 * Output: 3
 * Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
 * 
 * Example 3:
 * 
 * 
 * Input: 15
 * Output: 4
 * Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 * 
 * Note: 1 <= N <= 10 ^ 9.
 * 
 */

// @lc code=start
class Solution {
public:
/*
等差数列前n项和公式：x*n+n*(n-1)/2 = N
循环n，从1开始，如果等式中的x为整数则结果增加1，满足条件n*(n-1)/2<N
*/
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for(int n=1; n*(n-1)/2<N; ++n)
            if((N-n*(n-1)/2) % n == 0)
                res++;
        return res;
    }
};
// @lc code=end

