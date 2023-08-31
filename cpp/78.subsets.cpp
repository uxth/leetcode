/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (61.92%)
 * Likes:    4320
 * Dislikes: 92
 * Total Accepted:    631.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for(int n : nums)
        {
            int size = res.size();
            for(int i=0; i<size; ++i)
            {
                vector<int> tmp = res[i];
                tmp.push_back(n);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end

