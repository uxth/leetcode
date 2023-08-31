/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (63.84%)
 * Likes:    485
 * Dislikes: 284
 * Total Accepted:    87.7K
 * Total Submissions: 137.3K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l; // cursor for final pivot location 
        for(int j = l; j <= r - 1; j++){ // nums[r] is chosen as the pivot
            if(nums[j] <= nums[r]){
                swap(nums[i], nums[j]);
                i++; // smaller or equal elements go to the left of i 
            }
        }
        swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }

    void mysort(vector<int>& nums, int start, int end)
    {
        if(start >= end) return;
        if(start+1==end) {if(nums[start] > nums[end])swap(nums[start], nums[end]); return;}
        int l = start; int r = end;
        while(l < r)
        {
            while(l<r&& nums[l] <= nums[r]) r--;
            swap(nums[l], nums[r]);

            while(l<r&& nums[l] < nums[r]) l++;
            swap(nums[l], nums[r]);
        }
        mysort(nums, start, l-1);
        mysort(nums, l+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mysort(nums, 0, nums.size()-1);
        return nums;
    }
};
// @lc code=end

