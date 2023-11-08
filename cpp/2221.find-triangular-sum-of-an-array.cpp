/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 *
 * https://leetcode.com/problems/find-triangular-sum-of-an-array/description/
 *
 * algorithms
 * Medium (78.64%)
 * Likes:    1009
 * Dislikes: 50
 * Total Accepted:    67.2K
 * Total Submissions: 85.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * You are given a 0-indexed integer array nums, where nums[i] is a digit
 * between 0 and 9 (inclusive).
 * 
 * The triangular sum of nums is the value of the only element present in nums
 * after the following process terminates:
 * 
 * 
 * Let nums comprise of n elements. If n == 1, end the process. Otherwise,
 * create a new 0-indexed integer array newNums of length n - 1.
 * For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as
 * (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
 * Replace the array nums with newNums.
 * Repeat the entire process starting from step 1.
 * 
 * 
 * Return the triangular sum of nums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: 8
 * Explanation:
 * The above diagram depicts the process from which we obtain the triangular
 * sum of the array.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5]
 * Output: 5
 * Explanation:
 * Since there is only one element in nums, the triangular sum is the value of
 * that element itself.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; --i){
            for(int j=0; j<=i; ++j){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0]%10;
    }
};
// @lc code=end
/*
[5]
[9,7,8,6,4,5,3,2,1]
[0,3,3,4,1,2,6,4,9,3,5,1,7,7,3,0,3,2,5,1,9,0,2,6,3,9,2,5,9,2,6,4,2,9,7,2,0,3,0,1,1,2,7,8,6,4,4,5]
*/
