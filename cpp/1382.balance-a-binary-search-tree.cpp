/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
 *
 * https://leetcode.com/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (74.81%)
 * Likes:    363
 * Dislikes: 21
 * Total Accepted:    19.5K
 * Total Submissions: 25.8K
 * Testcase Example:  '[1,null,2,null,3,null,4,null,null]'
 *
 * Given a binary search tree, return a balanced binary search tree with the
 * same node values.
 * 
 * A binary search tree is balanced if and only if the depth of the two
 * subtrees of every node never differ by more than 1.
 * 
 * If there is more than one answer, return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,2,null,3,null,4,null,null]
 * Output: [2,1,3,null,null,null,4]
 * Explanation: This is not the only correct answer, [3,1,4,null,2,null,null]
 * is also correct.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is between 1 and 10^4.
 * The tree nodes will have distinct values between 1 and 10^5.
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
    TreeNode* dfs(vector<TreeNode*>& data, int left, int right)
    {
        if(left > right) return nullptr;
        int mid = (left+right)/2;
        data[mid]->left = dfs(data, left, mid-1);
        data[mid]->right = dfs(data, mid+1, right);
        return data[mid];
    }
    void inorder(TreeNode* root, vector<TreeNode*>& data)
    {
        if(root == nullptr) return;
        inorder(root->left, data);
        data.push_back(root);
        inorder(root->right, data);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) return root;
        vector<TreeNode*> data;
        inorder(root, data);
        return dfs(data, 0, data.size()-1);
    }
};
// @lc code=end

