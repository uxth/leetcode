/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 *
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (58.15%)
 * Likes:    228
 * Dislikes: 4
 * Total Accepted:    13.1K
 * Total Submissions: 22.2K
 * Testcase Example:  '[1,1,0,1]'
 *
 * Given a binary array nums, you should delete one element from it.
 * 
 * Return the size of the longest non-empty subarray containing only 1's in the
 * resulting array.
 * 
 * Return 0 if there is no such subarray.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3
 * numbers with value of 1's.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
 * longest subarray with value of 1's is [1,1,1,1,1].
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [1,1,0,0,1,1,1,0,1]
 * Output: 4
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j, k = 1, res = 0;
        for (j = 0; j < nums.length; ++j) {
            if (nums[j] == 0) {
                k--;
            }
            while (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};
// @lc code=end

