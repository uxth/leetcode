/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 *
 * https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (40.16%)
 * Likes:    266
 * Dislikes: 45
 * Total Accepted:    10K
 * Total Submissions: 25.6K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * Given a binary tree root, the task is to return the maximum sum of all keys
 * of any sub-tree which is also a Binary Search Tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * Output: 20
 * Explanation: Maximum sum in a valid Binary search tree is obtained in root
 * node with key equal to 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [4,3,null,1,2]
 * Output: 2
 * Explanation: Maximum sum in a valid Binary search tree is obtained in a
 * single root node with key equal to 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [-4,-2,-5]
 * Output: 0
 * Explanation: All values are negatives. Return an empty BST.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: 6
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [5,4,8,3,null,6,3]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given binary tree will have between 1 and 40000 nodes.
 * Each node's value is between [-4 * 10^4 , 4 * 10^4].
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
    struct ret
    {
        int sum;
        int left;
        int right;
        ret(int s, int l, int r){sum=s; left=l; right=r;}
    };
    pair<bool, ret> dfs(TreeNode* root, int& res)
    {
        if(root->left && root->right)
        {
            auto l = dfs(root->left, res);
            auto r = dfs(root->right, res);
            if(!l.first || !r.first || root->val >= r.second.left || root->val <= l.second.right) return {false, ret(0,0,0)};
            res = max(res, l.second.sum+r.second.sum+root->val);
            return {true, ret(l.second.sum+r.second.sum+root->val, l.second.left, r.second.right )};
        }
        if(root->left)
        {
            auto l = dfs(root->left, res);
            if(!l.first || root->val <= l.second.right) return {false, ret(0,0,0)};
            res = max(res, l.second.sum + root->val);
            return {true, ret(l.second.sum+root->val, l.second.left, root->val)};
        }
        if(root->right)
        {
            auto r = dfs(root->right, res);
            if(!r.first || root->val >= r.second.left) return {false, ret(0,0,0)};
            res = max(res, r.second.sum+root->val);
            return {true, ret(r.second.sum+root->val, root->val, r.second.right)};
        }
        res = max(res, root->val);
        return {true, ret(root->val, root->val, root->val)};
    }
    int maxSumBST(TreeNode* root) {
        if(root==nullptr) return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
};
// @lc code=end
// [8,9,8,null,9,null,1,null,null,-3,5,null,-2,null,6]
