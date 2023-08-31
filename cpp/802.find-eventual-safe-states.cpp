/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (48.93%)
 * Likes:    908
 * Dislikes: 172
 * Total Accepted:    43.4K
 * Total Submissions: 88.3K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * In a directed graph, we start at some node and every turn, walk along a
 * directed edge of the graph.  If we reach a node that is terminal (that is,
 * it has no outgoing directed edges), we stop.
 * 
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node.  More specifically, there exists a
 * natural number K so that for any choice of where to walk, we must have
 * stopped at a terminal node in less than K steps.
 * 
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 * 
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the
 * length of graph.  The graph is given in the following form: graph[i] is a
 * list of labels j such that (i, j) is a directed edge of the graph.
 * 
 * 
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Here is a diagram of the above graph.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length at most 10000.
 * The number of edges in the graph will not exceed 32000.
 * Each graph[i] will be a sorted list of different integers, chosen within the
 * range [0, graph.length - 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, colors)) res.push_back(i);
        }
        return res;
    }
    
    // 0 = WHITE, 1 = GRAY, 2 = BLACK
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors) {
        // If a node is touched before, it better be black.
        if (colors[node] != 0) return (colors[node] == 2);
        colors[node] = 1;   // Make node gray
        
        for (auto nn : graph[node]) {
            if (colors[nn] == 2) continue; // skip black nodes
            if (colors[nn] == 1) return false;  // Gray to Gray. Cycle!
            if (!dfs(nn, graph, colors)) return false;
        }
        colors[node] = 2;   // Make node black.
        return true;
    }
};
// @lc code=end

