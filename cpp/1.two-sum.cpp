/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); ++i){
            if(m.count(target-nums[i]))
                return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};
// @lc code=end

