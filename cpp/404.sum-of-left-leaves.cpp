/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (50.93%)
 * Likes:    1469
 * Dislikes: 144
 * Total Accepted:    216.4K
 * Total Submissions: 415.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
    void dfs(TreeNode* root, bool isleft, int& res)
    {
        if(root == nullptr) return ;
        if(isleft && root->left == nullptr && root->right == nullptr) res+=root->val;
        dfs(root->left, true, res);
        dfs(root->right, false, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // int res = 0;
        // dfs(root, false, res);
        // return res;


        return bfs(root);
    }

    int bfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, bool>> q; q.push({root,false});
        int res = 0;
        while(!q.empty())
        {
            TreeNode* f = q.front().first;
            bool isleft = q.front().second;
            q.pop();
            if(f->left == nullptr && f->right == nullptr && isleft) res+=f->val;
            if(f->left) q.push({f->left, true});
            if(f->right) q.push({f->right, false});
        }
        return res;
    }
};
// @lc code=end

