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
    void helper(vector<vector<int>>& g, int pos, int n, vector<int>& path, vector<vector<int>>& res)
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
            helper(g, next, n, path, res);
        }
        path.pop_back();
    }
    vector<vector<int>> dfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> res;
        helper(graph, 0, n-1, path, res);
        return res;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        // return dfs(graph);
        return bfs(graph);
    }

    vector<vector<int>> bfs(vector<vector<int>>& graph){
        
        int n = graph.size();
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            if(f.back() == n-1) res.push_back(f);
            for(int node : graph[f.back()]){
                vector<int> next = f;
                next.push_back(node);
                q.push(next); 
            }
        }
        return res;
    }

};
// @lc code=end

