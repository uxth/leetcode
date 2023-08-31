/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (51.40%)
 * Likes:    2022
 * Dislikes: 116
 * Total Accepted:    342.6K
 * Total Submissions: 656.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> bfs(TreeNode* root)
    {
        if(root == nullptr) return {};
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});
        vector<string> res;
        while(!q.empty())
        {
            TreeNode* f = q.front().first;
            string path = q.front().second;
            q.pop();
            if(f->left == nullptr && f->right == nullptr) res.push_back(path);
            if(f->left) q.push({f->left, path+"->"+to_string(f->left->val)});
            if(f->right) q.push({f->right, path+"->"+to_string(f->right->val)});
        }
        return res;
    }
    void helper(TreeNode* root, vector<TreeNode*>& path, vector<string>& res)
    {
        if(root->left == root->right)
        {
            string s;
            for(TreeNode* r : path) s+=to_string(r->val) + "->";
            s+=to_string(root->val);
            res.push_back(s);
            return;
        }
        path.push_back(root);
        if(root->left) helper(root->left, path, res);
        if(root->right) helper(root->right, path, res);
        path.pop_back();
    }
    vector<string> dfs(TreeNode* root)
    {
        if(root==nullptr) return {};
        vector<string> res;
        vector<TreeNode*> path;
        helper(root, path, res);
        return res;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // return bfs(root);
        return dfs(root);
    }
};
// @lc code=end

