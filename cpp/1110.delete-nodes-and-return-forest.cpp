/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 *
 * https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (66.97%)
 * Likes:    1174
 * Dislikes: 43
 * Total Accepted:    65K
 * Total Submissions: 97K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * Given the root of a binary tree, each node in the tree has a distinct
 * value.
 * 
 * After deleting all nodes with a value in to_delete, we are left with a
 * forest (a disjoint union of trees).
 * 
 * Return the roots of the trees in the remaining forest.  You may return the
 * result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * Output: [[1,2,null,4],[6],[7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is at most 1000.
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
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
    void dfs(TreeNode*& root, unordered_set<int>& todel, vector<TreeNode*>& res)
    {
        if(root == nullptr) return;

        dfs(root->left, todel, res);
        dfs(root->right, todel, res);
        if(todel.count(root->val))
        {
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            
            // delete root;
            root = nullptr;
        }
    }
    bool dfs2(TreeNode* root, unordered_set<int> todel, vector<TreeNode*>& res)
    {
        if(root == nullptr) return false;
        if(dfs2(root->left, todel, res)) root->left = nullptr;
        if(dfs2(root->right, todel, res)) root->right = nullptr;
        if(todel.count(root->val))
        {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return true;
        }
        return false;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> todel(to_delete.begin(), to_delete.end());
        // if(dfs2(root, todel, res)) root = nullptr;

        dfs(root, todel, res);
        if(root) res.push_back(root);
        return res;
    }
};
// @lc code=end

