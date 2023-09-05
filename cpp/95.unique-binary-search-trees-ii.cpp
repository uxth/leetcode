/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> dfs(int start, int end){
        if(start > end) return {nullptr};
        if(start == end) return {new TreeNode(start)};\
        vector<TreeNode*> res;
        // choose one of the digits to be the root and loop all the posibilities.
        for(int i=start; i<=end; ++i){
            vector<TreeNode*> left = dfs(start, i-1);
            vector<TreeNode*> right = dfs(i+1, end);
            for(auto l : left) for(auto r : right) {
                TreeNode* root = new TreeNode(i);
                root->left = l; root->right = r;
                res.push_back(root);
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
// @lc code=end

