/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (64.91%)
 * Likes:    3561
 * Dislikes: 58
 * Total Accepted:    554.3K
 * Total Submissions: 852.6K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode* dfs(TreeNode* root) {
        if(root == nullptr) return root;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        swap(root->left, root->right);
        return root;
    }
    TreeNode* bfs(TreeNode* root){
        if(root == nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            swap(f->left, f->right);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        // return dfs(root);
        return bfs(root);
    }
};
// @lc code=end

