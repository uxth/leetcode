/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 *
 * https://leetcode.com/problems/max-number-of-k-sum-pairs/description/
 *
 * algorithms
 * Medium (52.29%)
 * Likes:    107
 * Dislikes: 8
 * Total Accepted:    9.5K
 * Total Submissions: 18.2K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * You are given an integer array nums and an integer k.
 * 
 * In one operation, you can pick two numbers from the array whose sum equals k
 * and remove them from the array.
 * 
 * Return the maximum number of operations you can perform on the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 5
 * Output: 2
 * Explanation: Starting with nums = [1,2,3,4]:
 * - Remove numbers 1 and 4, then nums = [2,3]
 * - Remove numbers 2 and 3, then nums = []
 * There are no more pairs that sum up to 5, hence a total of 2 operations.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,1,3,4,3], k = 6
 * Output: 1
 * Explanation: Starting with nums = [3,1,3,4,3]:
 * - Remove the first two 3's, then nums = [1,4,3]
 * There are no more pairs that sum up to 6, hence a total of 1 operation.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0; int j=nums.size()-1;
        int res = 0;
        while(i<j)
        {
            if(nums[i]+nums[j] == k)
            {
                res++;
                i++; j--;
            }
            else if(nums[i]+nums[j] < k) i++;
            else j--;
        }
        return res;
    }
};
// @lc code=end
// [3,1,3,4,3]\n6
