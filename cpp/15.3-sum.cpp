/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.83%)
 * Likes:    7897
 * Dislikes: 872
 * Total Accepted:    1M
 * Total Submissions: 3.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<nums.size(); ++i)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int left = i+1; int right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum == target)
                {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    while(left<right && nums[left] == nums[left-1]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--; 
                }
                else if(sum < target) left++;
                else right--;
            }
        }
        return res;
    }
};
// @lc code=end

