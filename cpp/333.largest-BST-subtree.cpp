/*

Question
Formatted question description: https://leetcode.ca/all/333.html

Level
Medium

Description
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:

A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the subtree [5,1,8]. The return value is the subtree's size, which is 3.
Follow up:

Can you figure out ways to solve it with O(n) time complexity?

Algorithm
For each node, verify whether it is BST, and if it is, count the number of nodes.

*/

// OJ: https://leetcode.com/problems/largest-bst-subtree/
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    array<int, 3> dfs(TreeNode *root) { // min, max, count. If invalid, count = -1
        if (!root) return {INT_MAX,INT_MIN,0};
        auto left = dfs(root->left), right = dfs(root->right);
        bool valid = left[2] != -1 && right[2] != -1 && left[1] < root->val && right[0] > root->val;
        if (valid) ans = max(ans, 1 + left[2] + right[2]);
        return {
            left[2] ? left[0] : root->val, 
            right[2] ? right[1] : root->val, 
            valid ? 1 + left[2] + right[2] : -1
        };
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};