/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, vector<int>> data;
public:
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            data[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        return data[target][rand() % data[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

