/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (85.04%)
 * Likes:    6173
 * Dislikes: 357
 * Total Accepted:    843.8K
 * Total Submissions: 981.8K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree and two integers low and high,
 * return the sum of values of all nodes with a value in the inclusive range
 * [low, high].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 =
 * 32.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * Output: 23
 * Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 =
 * 23.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2 * 10^4].
 * 1 <= Node.val <= 10^5
 * 1 <= low <= high <= 10^5
 * All Node.val are unique.
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
    int bfs(TreeNode* root, int low, int high){
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f->val >= low && f->val <= high) res += f->val;
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        } 
        return res;
    }
    void helper(TreeNode* root, int low, int high, int& res){
        if(root == nullptr) return;
        if(root->val >= low && root->val <= high) res+=root->val;
        helper(root->left, low, high, res);
        helper(root->right, low, high, res);
    }
    int dfs(TreeNode* root, int low, int high){
        int res = 0;
        helper(root, low, high, res);
        return res;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        // return dfs(root, low, high);
        return bfs(root, low, high);
    }
};
// @lc code=end

