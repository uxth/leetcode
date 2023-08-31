/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 *
 * https://leetcode.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (83.58%)
 * Likes:    701
 * Dislikes: 40
 * Total Accepted:    56.2K
 * Total Submissions: 67.2K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * Given a binary tree, return the sum of values of its deepest leaves.
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is between 1 and 10^4.
 * The value of nodes is between 1 and 100.
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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty())
        {
            int size = q.size();
            res = 0;
            while(size--)
            {
                TreeNode* f = q.front(); q.pop();
                res+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return res;
    }
};
// @lc code=end

