/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 *
 * https://leetcode.com/problems/array-partition-i/description/
 *
 * algorithms
 * Easy (71.99%)
 * Likes:    898
 * Dislikes: 2697
 * Total Accepted:    232K
 * Total Submissions: 320.6K
 * Testcase Example:  '[1,4,3,2]'
 *
 * Given an integer array nums of 2n integers, group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes the sum
 * of min(ai, bi) for all i from 1 to n as large as possible.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,3,2]
 * Output: 4
 * Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3,
 * 4).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [6,2,6,5,1,2]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<nums.size(); i+=2) res+=nums[i];
        return res;
    }
};
// @lc code=end

