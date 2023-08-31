/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.21%)
 * Likes:    2796
 * Dislikes: 161
 * Total Accepted:    541.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minsum = INT16_MAX;
        int res = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            int left = i+1; 
            int right = nums.size()-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(minsum-target) > abs(target-sum)){minsum = sum; res = sum;}
                if(sum > target) right--;
                else if(sum < target) left++;
                else return sum;
            }
        }
        return res;
    }
};
// @lc code=end

