/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (43.95%)
 * Likes:    1305
 * Dislikes: 266
 * Total Accepted:    153.7K
 * Total Submissions: 345.9K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, write a method that returns the "pivot"
 * index of this array.
 * 
 * We define the pivot index as the index where the sum of all the numbers to
 * the left of the index is equal to the sum of all the numbers to the right of
 * the index.
 * 
 * If no such index exists, we should return -1. If there are multiple pivot
 * indexes, you should return the left-most pivot index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the
 * sum of numbers to the right of index 3.
 * Also, 3 is the first index where this occurs.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem
 * statement.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int pivotIndex(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     int acc = 0;
    //     for(int i=0;i<nums.size(); ++i)
    //     {
    //         if(acc * 2 == sum-nums[i]) return i;
    //         acc += nums[i];
    //     }
    //     return -1;
    // }
    int pivotIndex(vector<int>& nums) {
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for(int i=0;i<nums.size(); ++i){
            right -= nums[i];
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};
// @lc code=end

