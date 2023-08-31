/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (47.04%)
 * Likes:    1838
 * Dislikes: 80
 * Total Accepted:    294.6K
 * Total Submissions: 620.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res)
    {
        res.push_back(path);
        for(int i=start; i<nums.size(); ++i)
        {
            if(i>start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
};
// @lc code=end

