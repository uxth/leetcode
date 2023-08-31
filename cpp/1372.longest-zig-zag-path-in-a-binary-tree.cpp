/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 *
 * https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (54.02%)
 * Likes:    368
 * Dislikes: 8
 * Total Accepted:    13.3K
 * Total Submissions: 24.5K
 * Testcase Example:  '[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]'
 *
 * Given a binary tree root, a ZigZag path for a binary tree is defined as
 * follow:
 * 
 * 
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right then move to the right child of the
 * current node otherwise move to the left child.
 * Change the direction from right to left or right to left.
 * Repeat the second and third step until you can't move in the tree.
 * 
 * 
 * Zigzag length is defined as the number of nodes visited - 1. (A single node
 * has a length of 0).
 * 
 * Return the longest ZigZag path contained in that tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
 * Output: 3
 * Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,1,1,null,1,null,null,1,1,null,1]
 * Output: 4
 * Explanation: Longest ZigZag path in blue nodes (left -> right -> left ->
 * right).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 50000 nodes..
 * Each node's value is between [1, 100].
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
    int longestZigZag(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {0,0}});
        int res = 0;
        while(!q.empty())
        {
            TreeNode* f = q.front().first;
            int left = q.front().second.first;
            int right = q.front().second.second;
            q.pop();
            res = max({res, left, right});
            if(f->left){q.push({f->left, {right+1, 0}});}
            if(f->right){q.push({f->right, {0, left+1}});}
        }
        return res;
    }
};
// @lc code=end

