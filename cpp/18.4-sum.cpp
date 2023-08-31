/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (33.64%)
 * Likes:    2326
 * Dislikes: 348
 * Total Accepted:    352.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); ++i)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); ++j)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1; int right = nums.size()-1; 
                while(left < right)
                {
                    while(left < right && left>j+1 && nums[left]==nums[left-1]) left++;
                    while(left < right && right < nums.size()-1 && nums[right] == nums[right+1]) right--;
                    if(left>=right) break;
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target) res.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                    else if(sum>target) --right;
                    else ++left;
                }
            }
        }
        return res;
    }
};
// @lc code=end
// [-3,-2,-1,0,0,1,2,3]\n0
// [-1,2,2,-5,0,-1,4]\n3
