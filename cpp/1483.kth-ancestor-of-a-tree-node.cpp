/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 *
 * https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
 *
 * algorithms
 * Hard (27.56%)
 * Likes:    274
 * Dislikes: 48
 * Total Accepted:    7.6K
 * Total Submissions: 26.9K
 * Testcase Example:  '["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]\n' +
  '[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]'
 *
 * You are given a tree with n nodes numbered from 0 to n-1 in the form of a
 * parent array where parent[i] is the parent of node i. The root of the tree
 * is node 0.
 * 
 * Implement the function getKthAncestor(int node, int k) to return the k-th
 * ancestor of the given node. If there is no such ancestor, return -1.
 * 
 * The k-th ancestor of a tree node is the k-th node in the path from that node
 * to the root.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
 * [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
 * 
 * Output:
 * [null,1,0,-1]
 * 
 * Explanation:
 * TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
 * 
 * treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
 * treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of
 * 5
 * treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such
 * ancestor
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= n <= 5*10^4
 * parent[0] == -1 indicating that 0 is the root node.
 * 0 <= parent[i] < n for all 0 < i < n
 * 0 <= node < n
 * There will be at most 5*10^4 queries.
 * 
 */

// @lc code=start
class TreeAncestor {
public:
    vector<vector<int>>v;
    TreeAncestor(int n, vector<int>& parent) {
        v.resize(n, vector<int>(20, 0));
        for (int i = 0; i < n; i++) v[i][0] = parent[i];
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                if (v[i][j - 1] == -1) v[i][j] = -1;
                else v[i][j] = v[v[i][j - 1]][j - 1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]\n[[5,[-1,0,0,1,2]],[3,5],[3,2],[2,2],[0,2],[2,1]]
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]\n[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]