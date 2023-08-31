/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.58%)
 * Likes:    3899
 * Dislikes: 1391
 * Total Accepted:    403.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0 && nums[i]<=nums[i-1])--i;
        if(i==0) {reverse(nums.begin(), nums.end());return;}
        int j = nums.size()-1;
        while(j>i && nums[j]<=nums[i-1]) --j;
        swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
    }
};
// @lc code=end
// [1,4,3,2]
// [1,5,1]