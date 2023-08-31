/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (45.01%)
 * Likes:    687
 * Dislikes: 146
 * Total Accepted:    79.9K
 * Total Submissions: 176.2K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the n^th super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> nums{1};
        while (nums.size() != n)
        {
            int m = INT_MAX;
            int j = -1;
            for (int i = 0; i < primes.size(); ++i)
            {
                if (nums[idx[i]] * primes[i] < m)
                {
                    j = i;
                    m = nums[idx[i]] * primes[i];
                }
            }
            if(nums.back() != m)
                nums.push_back(m);
            ++idx[j];
        }
        return nums.back(); 
    }
};
// @lc code=end
// 1\n[2,3,5]
// 3\n[2,3,5]
// 15\n[3,5,7,11,19,23,29,41,43,47]