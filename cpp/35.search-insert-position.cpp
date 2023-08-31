/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (42.62%)
 * Likes:    2651
 * Dislikes: 265
 * Total Accepted:    682.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || target<=nums.front()) return 0;
        if(target>nums.back()) return nums.size();
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = (right-left)/2+left;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target) right=mid-1;
            else left=mid+1;
        }
        return nums[left]<target?left+1:left;
    }
};
// @lc code=end

