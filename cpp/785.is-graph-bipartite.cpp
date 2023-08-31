/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (47.47%)
 * Likes:    1747
 * Dislikes: 186
 * Total Accepted:    130.8K
 * Total Submissions: 274.5K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 * 
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node
 * in A and another node in B.
 * 
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists.  Each node is an integer
 * between 0 and graph.length - 1.  There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 * 
 * 
 * Example 1:
 * Input: [[1,3], [0,2], [1,3], [0,2]]
 * Output: true
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * We can divide the vertices into two groups: {0, 2} and {1, 3}.
 * 
 * 
 * 
 * Example 2:
 * Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * Output: false
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * We cannot find a way to divide the set of nodes into two independent
 * subsets.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length in range [1, 100].
 * graph[i] will contain integers in range [0, graph.length - 1].
 * graph[i] will not contain i or duplicate values.
 * The graph is undirected: if any element j is in graph[i], then i will be in
 * graph[j].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int start, int marker, vector<int>& group)
    {
        if(group[start] != 0) return group[start] == marker;
        group[start] = marker;
        for(int next : graph[start])
        {
            if(!dfs(graph, next, -marker, group))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty()) return true;
        
        vector<int> group(graph.size(), 0);

        for(int i=0;i<graph.size(); ++i)
        {
            if(group[i] == 0 && !dfs(graph, i, 1, group))
                return false;
        }
        return true;
    }
};
// @lc code=end
// [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
// [[4],[],[4],[4],[0,2,3]]
// [[2,4],[2,3,4],[0,1],[1],[0,1],[7],[9],[5],[],[6],[12,14],[],[10],[],[10],[19],[18],[],[16],[15],[23],[23],[],[20,21],[],[],[27],[26],[],[],[34],[33,34],[],[31],[30,31],[38,39],[37,38,39],[36],[35,36],[35,36],[43],[],[],[40],[],[49],[47,48,49],[46,48,49],[46,47,49],[45,46,47,48]]

// [[],[],[5],[7],[],[2],[],[3],[],[],[17,19],[15,18],[15,16,17,19],[15,16,18,19],[15,16,18],[11,12,13,14],[12,13,14],[10,12],[11,13,14],[10,12,13],[25,26,27,28,29],[25,26,27,28,29],[25,26,27,28,29],[25,26,27,28,29],[25,26,27,28,29],[20,21,22,23,24],[20,21,22,23,24],[20,21,22,23,24],[20,21,22,23,24],[20,21,22,23,24],[],[36],[],[37],[],[],[31],[33],[],[],[45,46,47,48,49],[45,46,48,49],[45],[47,48,49],[45],[40,41,42,44],[40,41],[40,43],[40,41,43],[40,41,43],[55,56,57,58,59],[55,56,57,58,59],[55,56,57,58,59],[55,56,57,58,59],[55,56,57,58,59],[50,51,52,53,54],[50,51,52,53,54],[50,51,52,53,54],[50,51,52,53,54],[50,51,52,53,54],[66,68],[65,66,67],[65,66,67,68,69],[65,66,67,69],[65,67,68,69],[61,62,63,64],[60,61,62,63],[61,62,63,64],[60,62,64],[62,63,64],[75,76,77,78,79],[75,76,77,78,79],[75,76,77,78,79],[75,76,77,78,79],[76,77,78,79],[70,71,72,73],[70,71,72,73,74],[70,71,72,73,74],[70,71,72,73,74],[70,71,72,73,74],[85],[86,87],[88],[85,86,87,89],[85,86,88,89],[80,83,84],[81,83,84],[81,83],[82,84],[83,84],[95,96,98,99],[95,96,97,98,99],[95,96,97,98,99],[95,96,97,98,99],[95,96,97,98,99],[90,91,92,93,94],[90,91,92,93,94],[91,92,93,94],[90,91,92,93,94],[90,91,92,93,94]]