/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.76%)
 * Likes:    4575
 * Dislikes: 577
 * Total Accepted:    778.9K
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
    bool isBST(TreeNode* root, long low, long high)
    {
        if(root==nullptr) return true;
        if(root->val <= low || root->val >= high) return false;
        return isBST(root->left, low, root->val) && isBST(root->right, root->val, high);
    }
    bool dfs(TreeNode* root){
        if(root==nullptr) return true;
        return isBST(root->left, LONG_MIN, root->val) && isBST(root->right, root->val, LONG_MAX);
    }

    bool bfs(TreeNode* root){
        if(root == nullptr) return true;
        stack<TreeNode*> st;
        long pre = LONG_MIN;
        while(root != nullptr || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }else{
                root = st.top();
                st.pop();
                if(root->val <= pre) return false;
                pre = root->val;
                root = root->right;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // return dfs(root);
        return bfs(root);
    }
};
// @lc code=end
// [1,1]
// [-2147483648]