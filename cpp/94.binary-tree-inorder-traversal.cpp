/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.28%)
 * Likes:    3343
 * Dislikes: 140
 * Total Accepted:    763.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        return bfs(root);
    }
    void helper(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    vector<int> dfs(TreeNode* root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }
    vector<int> bfs(TreeNode* root)
    {
        if(root == nullptr) return {};

        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root); 
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }

        return res;
    }
};
// @lc code=end

