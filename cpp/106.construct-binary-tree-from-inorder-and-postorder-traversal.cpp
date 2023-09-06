/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* dfs(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int po_left, int po_right){
        if(in_left > in_right || po_left > po_right || inorder.empty() || postorder.empty()) return nullptr;
        if(in_left == in_right && po_left == po_right) return new TreeNode(inorder[in_left]);

        int pivot = in_left;
        while(pivot <= in_right && inorder[pivot] != postorder[po_right]) pivot++;

        TreeNode* res = new TreeNode(postorder[po_right]);
        res->left = dfs(inorder, in_left, pivot-1, postorder, po_left, pivot-in_left+po_left-1);
        res->right = dfs(inorder, pivot+1, in_right, postorder, pivot-in_left+po_left, po_right-1);
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
// @lc code=end

