/*

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
Companies:
Facebook

Related Topics:
Tree

*/

// OJ: https://leetcode.com/problems/equal-tree-partition/
// Time: O(N^2)
// Space: O(logN)
class Solution {
public:
    int getSum(TreeNode *root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    bool dfs(TreeNode *root, int target) {
        if (!root) return false;
        int sum = getSum(root);
        if (sum == target) return true;
        if (sum - root->val < target) return false;
        return dfs(root->left, target) || dfs(root->right, target);
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int sum = getSum(root);
        if (sum % 2) return false;
        return dfs(root->left, sum / 2) || dfs(root->right, sum / 2);
    }
};