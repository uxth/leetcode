/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (36.15%)
 * Likes:    4070
 * Dislikes: 161
 * Total Accepted:    557.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchLeft(vector<int>&nums, int target)
    {
        int left =0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = (left+right)/2;
            if(nums[mid]>target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }
    int searchRight(vector<int>& nums, int target)
    {
        int left = 0; 
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = (left+right+1)/2;
            if(nums[mid]<target) left=mid+1;
            else if(nums[mid] > target)right = mid-1;
            else left = mid;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || nums.back() < target || target < nums.front()) return {-1,-1};
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        if(nums[left] == nums[right] && nums[left] == target) return {left, right};
        return {-1,-1};
    }
};
// @lc code=end
// [5,7,7,8,8,10]\n6
// [2,2]\n3
// [5,7,7,7,7,7,8,8,10]\n10