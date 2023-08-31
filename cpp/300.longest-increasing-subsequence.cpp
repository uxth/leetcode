/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (42.60%)
 * Likes:    5050
 * Dislikes: 111
 * Total Accepted:    398.7K
 * Total Submissions: 935.3K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); ++i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

