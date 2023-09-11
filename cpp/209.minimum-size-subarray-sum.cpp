/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (38.14%)
 * Likes:    2716
 * Dislikes: 119
 * Total Accepted:    291.6K
 * Total Submissions: 758K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = 0; int right = 0;
        int sum = 0;
        int res = INT_MAX;
        while (left < n) {
            if (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            } else {
                if (right < n)
                    sum += nums[right++];
                else
                    sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
// 11\n[1,2,3,4,5]
