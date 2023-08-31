/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (54.65%)
 * Likes:    1670
 * Dislikes: 69
 * Total Accepted:    307.5K
 * Total Submissions: 556.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(int n, int k, int start, vector<int>& path, vector<vector<int>>& res)
    {
        if(start > n)
        {
            if(path.size()==k) res.push_back(path);
            return;
        }
        path.push_back(start);
        dfs(n,k, start+1, path, res);
        path.pop_back();
        dfs(n,k, start+1, path, res);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> path;
        dfs(n,k,1,path,res);
        return res;
    }
};
// @lc code=end

