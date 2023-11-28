/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Medium (32.98%)
 * Likes:    7555
 * Dislikes: 1374
 * Total Accepted:    800.6K
 * Total Submissions: 2.4M
 * Testcase Example:  '10'
 *
 * Given an integer n, return the number of prime numbers that are strictly
 * less than n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 1
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<int> dp(n);
        int res = 0;
        for(int i=2; i<n; ++i){
            if(dp[i]) continue;
            res++;
            int j = i;
            while(j<n) {
                dp[j] = 1;
                j+=i;
            }
        }
        return res;
    }
};
// @lc code=end
/*
959831
*/

