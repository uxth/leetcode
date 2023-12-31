/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 *
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/
 *
 * algorithms
 * Medium (62.14%)
 * Likes:    242
 * Dislikes: 30
 * Total Accepted:    14.7K
 * Total Submissions: 23.2K
 * Testcase Example:  '7'
 *
 * Given the number k, return the minimum number of Fibonacci numbers whose sum
 * is equal to k, whether a Fibonacci number could be used multiple times.
 * 
 * The Fibonacci numbers are defined as:
 * 
 * 
 * F1 = 1
 * F2 = 1
 * Fn = Fn-1 + Fn-2 , for n > 2.
 * 
 * It is guaranteed that for the given constraints we can always find such
 * fibonacci numbers that sum k.
 * 
 * Example 1:
 * 
 * 
 * Input: k = 7
 * Output: 2 
 * Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
 * For k = 7 we can use 2 + 5 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: k = 10
 * Output: 2 
 * Explanation: For k = 10 we can use 2 + 8 = 10.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 19
 * Output: 3 
 * Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= 10^9
 * 
 */

// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k<2) return k;
        int a=1; int b=1;
        while(b<=k)
        {
            swap(a,b);
            b+=a;
        }
        return 1 + findMinFibonacciNumbers(k-a);
    }
};
// @lc code=end

