/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (41.99%)
 * Likes:    2037
 * Dislikes: 124
 * Total Accepted:    182.4K
 * Total Submissions: 433.2K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution {
public:

    int nthUglyNumber(int n) {
        vector<int> nums{1};
        int i = 0; int j = 0; int k = 0;
        while (nums.size() != n)
        {
            int m = min({2*nums[i], 3*nums[j], 5*nums[k]});
            nums.push_back(m);
            if (m == 2 * nums[i])i++;
            if (m == 3 * nums[j])j++;
            if (m == 5 * nums[k])k++;
        }
        return nums.back(); 
    }
};
// @lc code=end

