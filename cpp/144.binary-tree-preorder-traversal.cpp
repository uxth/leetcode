/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (55.64%)
 * Likes:    1634
 * Dislikes: 61
 * Total Accepted:    512.8K
 * Total Submissions: 920.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode* root) {
        return bfs(root);
    }
    vector<int> dfs(TreeNode* root)
    {
        if(root == nullptr) return {};
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
    vector<int> bfs(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> rights;
        while(root != NULL || !rights.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root->right)
                    rights.push(root->right);
                root = root->left;
            }
            else
            {
                root = rights.top();
                rights.pop();
            }
        }
        return res; 
    }
};
// @lc code=end

