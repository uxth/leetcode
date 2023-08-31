/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.84%)
 * Likes:    5413
 * Dislikes: 172
 * Total Accepted:    362.6K
 * Total Submissions: 827.8K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int, int> preSum;
        preSum[0]=1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result += preSum[sum - k];
            preSum[sum]++;
        }
        
        return result;
    }
};
// @lc code=end
// [1,2,3,2,1]\n6
// [1]\n0
// [-1,-1,1]\n0