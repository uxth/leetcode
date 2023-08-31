/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (77.92%)
 * Likes:    1094
 * Dislikes: 77
 * Total Accepted:    86.7K
 * Total Submissions: 111.1K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed acyclic graph of N nodes. Find all possible paths from node
 * 0 to node N-1, and return them in any order.
 * 
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
 * graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * 
 * 
 * Example:
 * Input: [[1,2],[3],[3],[]]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the graph will be in the range [2, 15].
 * You can print different paths in any order, but you should keep the order of
 * nodes inside one path.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& g, int pos, int n, vector<int>& path, vector<vector<int>>& res)
    {
        if(pos == n)
        {
            path.push_back(pos);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(pos);
        for(int next : g[pos])
        {
            dfs(g, next, n, path, res);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> g;
        int n = graph.size();
        for(int i=0; i<graph.size(); ++i) for(int j : graph[i]) g[i].push_back(j);
        vector<int> path;
        vector<vector<int>> res;
        dfs(g, 0, n-1, path, res);
        return res;
    }
};
// @lc code=end

