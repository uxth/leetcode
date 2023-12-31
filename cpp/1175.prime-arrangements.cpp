/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 *
 * https://leetcode.com/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (51.01%)
 * Likes:    114
 * Dislikes: 213
 * Total Accepted:    12K
 * Total Submissions: 23.4K
 * Testcase Example:  '5'
 *
 * Return the number of permutations of 1 to n so that prime numbers are at
 * prime indices (1-indexed.)
 * 
 * (Recall that an integer is prime if and only if it is greater than 1, and
 * cannot be written as a product of two positive integers both smaller than
 * it.)
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5
 * Output: 12
 * Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1]
 * is not because the prime number 5 is at index 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 100
 * Output: 682289015
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numPrimeArrangements(int n) {
        static const vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};   
        const int k = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        const auto mod = (long long)1e9 + 7;
        long long res = 1;
        for(int i = 2; i<=k; i++) {res*=i; res%=mod;}
        for(int i = 2; i<=n-k; i++) {res*=i; res%=mod;}
        return res;
    }
};
// @lc code=end

