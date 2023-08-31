/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (33.01%)
 * Likes:    1599
 * Dislikes: 496
 * Total Accepted:    260.6K
 * Total Submissions: 789.5K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        while(left <= right)
        {
            if(nums[left] == target || nums[right] == target) return true;
            if(nums[left] == nums[right])
            {
                left++; right--;
            }
            else
            {
                int mid = (left + right) / 2;
                if(nums[mid] == target) return true;
                if((nums[left] <= target && target < nums[mid]) || (target < nums[mid] || target > nums[right]) && nums[mid] <= nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            
        }
        return false;
    }
};
// @lc code=end
// [2,5,6,0,0,1,2]\n3
// [1]\n1
// [3,1,1]\n3
// [3,1,2,2,2]\n1