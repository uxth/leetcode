/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (65.90%)
 * Likes:    642
 * Dislikes: 28
 * Total Accepted:    43.3K
 * Total Submissions: 65.4K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value V for which there
 * exists different nodes A and B where V = |A.val - B.val| and A is an
 * ancestor of B.
 * 
 * (A node A is an ancestor of B if either: any child of A is equal to B, or
 * any child of A is an ancestor of B.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: 
 * We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is between 2 and 5000.
 * Each node will have value between 0 and 100000.
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
    // pair<int,int> dfs(TreeNode* root, int& res)
    // {
    //     auto left = root->left == nullptr ? make_pair(root->val,root->val) : dfs(root->left, res);
    //     auto right = root->right == nullptr ? make_pair(root->val,root->val) : dfs(root->right, res);
    //     int mn = min({left.first, left.second, right.first, right.second});
    //     int mx = max({left.first, left.second, right.first, right.second});
    //     res = max({res, abs(root->val - mx), abs(root->val-mn)});
    //     return {min(root->val, mn), max(root->val, mx)};
    // }
    // int maxAncestorDiff(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int res = 0;
    //     dfs(root, res);
    //     return res;
    // }


    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {root->val, root->val}});
        int res = 0;
        while(!q.empty())
        {
            TreeNode* f = q.front().first;
            int mn = q.front().second.first;
            int mx = q.front().second.second;
            q.pop();
            res = max({res, abs(f->val-mx), abs(f->val-mn)});
            if(f->left)
                q.push({f->left, {min(f->val, mn), max(f->val, mx)}});
            if(f->right)
                q.push({f->right, {min(f->val, mn), max(f->val, mx)}});
        }
        return res;
    }
};
// @lc code=end
// [8,3,10,1,6,null,14,null,null,4,7,13]
