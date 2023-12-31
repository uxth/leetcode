/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (36.18%)
 * Likes:    1770
 * Dislikes: 481
 * Total Accepted:    94.3K
 * Total Submissions: 260.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
    int dfs(TreeNode* root, int& maxValue){
        if(root == nullptr) return 0;
        int left = dfs(root->left, maxValue);
        int right = dfs(root->right, maxValue);
        int curleft = 0, curright = 0;
        if(root->left && root->left->val == root->val)
            curleft = left + 1;
        if(root->right && root->right->val == root->val)
            curright = right + 1;
        maxValue = max(maxValue, curleft + curright);
        return max(curleft, curright);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxValue = INT_MIN;
        dfs(root, maxValue);
        return maxValue == INT_MIN ? 0 : maxValue;
    }
};
// @lc code=end
// [1,null,1,1,1,1,1,1]
// [1,1,null,1,1,1,null,null,1]