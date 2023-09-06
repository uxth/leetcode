/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (46.61%)
 * Likes:    2060
 * Dislikes: 73
 * Total Accepted:    351.9K
 * Total Submissions: 744.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res)
    {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr && root->val == sum)
        {
            path.push_back(sum);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        helper(root->left, sum-root->val, path, res);
        helper(root->right, sum-root->val, path, res);
        path.pop_back();
    }
    
    vector<vector<int>> dfs(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        helper(root, sum, path, res);
        return res;
    }
    vector<vector<int>> bfs(TreeNode* root, int sum){
        if(root == nullptr) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        vector<vector<int>> res;
        while(!q.empty()){
            auto [cur, value] = q.front();
            q.pop();
            if(cur->left == nullptr && cur->right == nullptr && value == sum){
                vector<int> data{cur->val};
                TreeNode* it = cur;
                while(parent[it]){
                    it = parent[it];
                    data.push_back(it->val); 
                }
                reverse(begin(data), end(data));
                res.push_back(data);
            }
            if(cur->left) {
                parent[cur->left] = cur;
                q.push({cur->left, value + cur->left->val});
            }
            if(cur->right){
                parent[cur->right] = cur;
                q.push({cur->right, value + cur->right->val});
            }
        }
        return res;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // return dfs(root, sum);
        return bfs(root, sum);
    }
};
// @lc code=end

