/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (34.53%)
 * Likes:    5812
 * Dislikes: 504
 * Total Accepted:    800.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * You are given an integer array nums sorted in ascending order, and an
 * integer target.
 * 
 * Suppose that nums is rotated at some pivot unknown to you beforehand (i.e.,
 * [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * If target is found in the array return its index, otherwise, return -1.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int searchBS(vector<int>& nums, int target, int left, int right)
    // {
    //     // cout << left << "-" << right << endl;
    //     if(left > right) return -1;
    //     if(nums[left] == target) return left;
    //     if(nums[right] == target) return right;
    //     if(target < nums[left] || target > nums[right]) return -1;
    //     while(left < right)
    //     {
    //         int mid = (left + right) / 2;
    //         if(nums[mid] > target) right = mid -1 ;
    //         else if(nums[mid] < target) left = mid + 1;
    //         else return mid;
    //     }
    //     return nums[left] == target ? left : -1;
    // }
    // int searchRotate(vector<int>& nums, int target, int left, int right)
    // {
    //     // cout << left << "=" << right << endl;
    //     if(left > right) return -1;
    //     if(nums[left] == target) return left;
    //     if(nums[right] == target) return right;
    //     int mid = (left + right) / 2;
    //     if(nums[mid] == target) return mid;

    //     if(nums[left]<nums[mid])
    //     {
    //         if(nums[left]<target && target<nums[mid]) return searchBS(nums, target, left, mid-1);
    //         if(target<nums[left] || nums[mid] < target) return searchRotate(nums, target, mid+1, right);
    //     }
    //     else if(nums[mid]<nums[right])
    //     {
    //         if(nums[mid]<target && target<nums[right]) return searchBS(nums, target, mid+1, right);
    //         if(target<nums[mid] || nums[right] < target) return searchRotate(nums, target, left, mid-1);
    //     }
    //     return -1;
    // }
    // int search(vector<int>& nums, int target) {
    //     if(nums.back() > nums.front()) return searchBS(nums, target, 0, nums.size()-1);
    //     return searchRotate(nums, target, 0, nums.size()-1);
    // }


    // int search(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size()-1;
    //     while(left <= right)
    //     {
    //         if(nums[left] == target) return left;
    //         if(nums[right] == target) return right;
    //         int mid = (left + right) / 2;
    //         if(target == nums[mid]) return mid;
    //         if((nums[left] <= target && target < nums[mid])
    //             || (nums[mid] < nums[right] && (target > nums[right] || target < nums[mid])))
    //             right = mid - 1;
    //         else
    //             left = mid + 1;
    //     }
    //     return -1;
    // }

    int bs(vector<int>& nums, int target, int left, int right) {
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target) left = mid + 1;
            else right = mid;
        }
        return nums[left] == target ? left : -1;
    }
    int rs(vector<int>& nums, int target, int left, int right){
        if(nums[right] == target) return right;
        int mid = (right-left)/2 + left;
        if(left == mid) return nums[mid] == target ? mid : -1;
        if(nums[left] < nums[mid]){
            if(nums[left]<=target && target<=nums[mid])
                return bs(nums, target, left, mid);
            else
                return rs(nums, target, mid, right);
        }else{
            if(nums[mid]<=target && target<=nums[right])
                return bs(nums, target, mid, right);
            else
                return rs(nums, target, left, mid);
        }
    }
    int search(vector<int>& nums, int target) {
        return rs(nums, target, 0, nums.size()-1);
    }
};
// @lc code=end
// [4,5,6,7,0,1,2]\n3
// [1]\n0
// [1,3]\n0
// [3,5,1]\n5
// [4,5,6,7,8,1,2,3]\n8
// [7,8,0,1,2]\n6
// [5,1,3]\n1