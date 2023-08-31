/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (48.10%)
 * Likes:    1945
 * Dislikes: 72
 * Total Accepted:    344.1K
 * Total Submissions: 708.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(path);
            return;
        }

        for(int i=start; i<candidates.size(); ++i)
        {
            if(i>start && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]<=target)
            {
                path.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i+1, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<int> path;
        vector<vector<int>> res;
        dfs(candidates, target, 0, path, res);
        return res;
    }
};
// @lc code=end

