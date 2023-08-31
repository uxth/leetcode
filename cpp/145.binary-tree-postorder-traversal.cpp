/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (54.91%)
 * Likes:    1910
 * Dislikes: 96
 * Total Accepted:    391.7K
 * Total Submissions: 712.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        return bfs(root);
    }

    void helper(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr) return;
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
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
        stack<TreeNode*> s;
        vector<int> res;
        while(root || !s.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root->left) s.push(root->left);
                root = root->right;
            }
            else
            {
                root = s.top();
                s.pop();
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};
// @lc code=end

