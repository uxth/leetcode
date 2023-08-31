/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (46.06%)
 * Likes:    739
 * Dislikes: 117
 * Total Accepted:    48.3K
 * Total Submissions: 104.6K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
    void dfs(vector<int>& nums, int pos, vector<int>& path, unordered_set<vector<int>, VectorHash>& visited, vector<vector<int>>& res)
    {
        if(pos == nums.size())
        {
            if(path.size() > 1 && visited.count(path) == 0)
                res.push_back(path);
            visited.insert(path);
            return;
        }

        if(path.empty() || nums[pos] >= path.back())
        {
            path.push_back(nums[pos]);
            dfs(nums, pos + 1, path, visited, res);
            path.pop_back();
        }
        dfs(nums, pos + 1, path, visited, res);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty()) return {};

        vector<int> path;
        unordered_set<vector<int>, VectorHash> visited;
        vector<vector<int>> res;
        dfs(nums, 0, path, visited, res);

        return res;
    }
};
// @lc code=end

