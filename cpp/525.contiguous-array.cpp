/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (42.76%)
 * Likes:    2342
 * Dislikes: 127
 * Total Accepted:    168.6K
 * Total Submissions: 393K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m{{0,-1}};
        int sum = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (!m.count(sum))
                m[sum] = i;
            res = max(res, i - m[sum]);
        }
        
        return res;
    }
};
// @lc code=end

