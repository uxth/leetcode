/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 *
 * https://leetcode.com/problems/frog-position-after-t-seconds/description/
 *
 * algorithms
 * Hard (34.52%)
 * Likes:    182
 * Dislikes: 68
 * Total Accepted:    12.2K
 * Total Submissions: 34.8K
 * Testcase Example:  '7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n2\n4'
 *
 * Given an undirected tree consisting of n vertices numbered from 1 to n. A
 * frog starts jumping from vertex 1. In one second, the frog jumps from its
 * current vertex to another unvisited vertex if they are directly connected.
 * The frog can not jump back to a visited vertex. In case the frog can jump to
 * several vertices, it jumps randomly to one of them with the same
 * probability. Otherwise, when the frog can not jump to any unvisited vertex,
 * it jumps forever on the same vertex.
 * 
 * The edges of the undirected tree are given in the array edges, where
 * edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and
 * bi.
 * 
 * Return the probability that after t seconds the frog is on the vertex
 * target.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target =
 * 4
 * Output: 0.16666666666666666 
 * Explanation: The figure above shows the given graph. The frog starts at
 * vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and
 * then jumping with 1/2 probability to vertex 4 after second 2. Thus the
 * probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 =
 * 1/6 = 0.16666666666666666. 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target =
 * 7
 * Output: 0.3333333333333333
 * Explanation: The figure above shows the given graph. The frog starts at
 * vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7
 * after second 1. 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target
 * = 6
 * Output: 0.16666666666666666
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * edges.length == n - 1
 * edges[i].length == 2
 * 1 <= ai, bi <= n
 * 1 <= t <= 50
 * 1 <= target <= n
 * Answers within 10^-5 of the actual value will be accepted as correct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n+1);
        for(auto& i : edges)
        {
            if(i[0]<i[1]) g[i[0]].push_back(i[1]);
            else g[i[1]].push_back(i[0]);
        }
        queue<pair<int, double>> q;
        q.push({1, 1.0});
        while(!q.empty() && t>=0)
        {
            int size = q.size();
            while(size--)
            {
                auto [node, poss] = q.front(); q.pop();
                int count = g[node].size();
                if((t==0 || count == 0)&& node == target) return poss;
                for(auto next : g[node]) 
                    q.push({next, poss/count});
            }
            t--;
        }

        return 0;
    }
};
// @lc code=end
// 7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n1\n7
// 8\n[[2,1],[3,2],[4,1],[5,1],[6,4],[7,1],[8,7]]\n7\n7
// 7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n20\n6
// 3\n[[2,1],[3,2]]\n1\n2