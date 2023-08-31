/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.25%)
 * Likes:    2596
 * Dislikes: 108
 * Total Accepted:    421.5K
 * Total Submissions: 861.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        stack<TreeNode*> q;q.push(root);
        vector<vector<int>> res;
        while(!q.empty())
        {
            vector<int> data;
            stack<TreeNode*> st;
            while(!q.empty())
            {
                auto f = q.top(); q.pop();
                data.push_back(f->val);
                if(res.size() % 2 == 1)
                {
                    if(f->right) st.push(f->right);
                    if(f->left) st.push(f->left);
                }
                else
                {
                    if(f->left) st.push(f->left);
                    if(f->right) st.push(f->right);
                }
                
            }
            res.push_back(data);
            swap(q,st);
        }
        return res;
    }
};
// @lc code=end

