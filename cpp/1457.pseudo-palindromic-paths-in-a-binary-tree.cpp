/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 *
 * https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (67.19%)
 * Likes:    293
 * Dislikes: 12
 * Total Accepted:    19K
 * Total Submissions: 28.1K
 * Testcase Example:  '[2,3,1,3,1,null,1]'
 *
 * Given a binary tree where node values are digits from 1 to 9. A path in the
 * binary tree is said to be pseudo-palindromic if at least one permutation of
 * the node values in the path is a palindrome.
 * 
 * Return the number of pseudo-palindromic paths going from the root node to
 * leaf nodes.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [2,3,1,3,1,null,1]
 * Output: 2 
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the red path [2,3,3],
 * the green path [2,1,1], and the path [2,3,1]. Among these paths only red
 * path and green path are pseudo-palindromic paths since the red path [2,3,3]
 * can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be
 * rearranged in [1,2,1] (palindrome).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [2,1,1,1,3,null,null,null,null,null,1]
 * Output: 1 
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the green path [2,1,1],
 * the path [2,1,3,1], and the path [2,1]. Among these paths only the green
 * path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1]
 * (palindrome).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [9]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given binary tree will have between 1 and 10^5 nodes.
 * Node values are digits from 1 to 9.
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
    void dfs(TreeNode* root, unordered_map<int,int>& count, int& res)
    {
        if(root == nullptr) return;
        count[root->val]++;
        if(root->left == nullptr && root->right == nullptr)
        {
            int odd= 0;
            for(auto& [key, val] : count) odd += val % 2;
            if(odd <= 1) res++;
        }
        dfs(root->left, count, res);
        dfs(root->right, count, res);
        if(--count[root->val]==0) count.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr) return 0;
        unordered_map<int,int> count;
        int res = 0;
        dfs(root, count, res);
        return res;
    }
};
// @lc code=end

