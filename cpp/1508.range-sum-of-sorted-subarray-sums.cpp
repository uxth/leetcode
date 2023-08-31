/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 *
 * https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
 *
 * algorithms
 * Medium (68.80%)
 * Likes:    153
 * Dislikes: 37
 * Total Accepted:    10.8K
 * Total Submissions: 16K
 * Testcase Example:  '[1,2,3,4]\n4\n1\n5'
 *
 * Given the array nums consisting of n positive integers. You computed the sum
 * of all non-empty continous subarrays from the array and then sort them in
 * non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
 * 
 * Return the sum of the numbers from index left to index right (indexed from
 * 1), inclusive, in the new array. Since the answer can be a huge number
 * return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
 * Output: 13 
 * Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After
 * sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4,
 * 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2
 * + 3 + 3 + 4 = 13. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
 * Output: 6
 * Explanation: The given array is the same as example 1. We have the new array
 * [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to
 * ri = 4 is 3 + 3 = 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
 * Output: 50
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^3
 * nums.length == n
 * 1 <= nums[i] <= 100
 * 1 <= left <= right <= n * (n + 1) / 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        for (int i=0; i<n; i++)
            mqueue.push({nums[i], i+1});

        int res = 0, mod = 1e9+7;
        for (int i=1; i<=right; i++) {
            int val = mqueue.top().first;
            int idx = mqueue.top().second;
            mqueue.pop();
            if (i >= left)
                res = (res + val) % mod;
            if (idx < n) {
                val += nums[idx++];
                mqueue.push({val, idx});
            }
        }
        return res;
    }
};
// @lc code=end

