/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candA, candB;
        for (auto& edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) parent[i] = i;
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = find(parent, u), pv = find(parent, v);
            if (pu == pv) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[pv] = pu;
        }
        return candB;
    }
    
    int find(vector<int>& parent, int i) {
        return parent[i] == i ? i : find(parent, parent[i]);
    }
};
// @lc code=end

