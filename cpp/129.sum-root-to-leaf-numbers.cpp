/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (49.00%)
 * Likes:    1695
 * Dislikes: 43
 * Total Accepted:    289.3K
 * Total Submissions: 584.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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
    void helper(TreeNode* root, int data, int& res)
    {
        if(root->right == root->left)
        {
            res += data*10 + root->val;
            return;
        }
        if(root->left)helper(root->left, data*10+root->val, res);
        if(root->right)helper(root->right, data*10+root->val, res);
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int res = 0;
        helper(root, 0, res);
        return res;
    }
    int bfs(TreeNode* root)
    {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty())
        {
            TreeNode* f = q.front(); q.pop();
            if(f->left==nullptr && f->right==nullptr) res+=f->val;
            if(f->left){f->left->val += f->val * 10; q.push(f->left);}
            if(f->right){f->right->val += f->val * 10; q.push(f->right);}
        }
        return res;
    }
    int sumNumbers(TreeNode* root) {
        // return bfs(root);
        return dfs(root);
    }
};
// @lc code=end

