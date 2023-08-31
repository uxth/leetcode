/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (54.04%)
 * Likes:    2632
 * Dislikes: 150
 * Total Accepted:    322.4K
 * Total Submissions: 591K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        if(root== nullptr) return {};
        queue<TreeNode*> q; q.push(root);
        vector<int> res;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size; ++i)
            {
                TreeNode* f = q.front();
                q.pop();
                if(i==0) res.push_back(f->val);
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
        }
        return res;
    }
};
// @lc code=end

