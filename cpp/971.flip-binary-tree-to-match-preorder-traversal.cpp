/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
 *
 * https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/
 *
 * algorithms
 * Medium (45.62%)
 * Likes:    290
 * Dislikes: 133
 * Total Accepted:    13.4K
 * Total Submissions: 29.3K
 * Testcase Example:  '[1,2]\n[2,1]'
 *
 * Given a binary tree with N nodes, each node has a different value from {1,
 * ..., N}.
 * 
 * A node in this binary tree can be flipped by swapping the left child and the
 * right child of that node.
 * 
 * Consider the sequence of N values reported by a preorder traversal starting
 * from the root.  Call such a sequence of N values the voyage of the tree.
 * 
 * (Recall that a preorder traversal of a node means we report the current
 * node's value, then preorder-traverse the left child, then preorder-traverse
 * the right child.)
 * 
 * Our goal is to flip the least number of nodes in the tree so that the voyage
 * of the tree matches the voyage we are given.
 * 
 * If we can do so, then return a list of the values of all nodes flipped.  You
 * may return the answer in any order.
 * 
 * If we cannot do so, then return the list [-1].
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2], voyage = [2,1]
 * Output: [-1]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3], voyage = [1,3,2]
 * Output: [1]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3], voyage = [1,2,3]
 * Output: []
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 100
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        int i=0;
        vector<int> res;
        return dfs(root, v, i, res) ? res : vector<int>{-1};
    }

    bool dfs(TreeNode* node, vector<int>& v, int& i, vector<int>& res) {
        if (!node) return true;
        if (node->val != v[i++]) return false;
        if (node->left && node->left->val != v[i]) {
            res.push_back(node->val);
            swap(node->left, node->right);
        }
        return dfs(node->left, v, i, res) && dfs(node->right, v, i, res);
    }
};
// @lc code=end
// [1,2,3,4,5]\n[1,3,2,5,4]
// [1,null,2]\n[1,2]