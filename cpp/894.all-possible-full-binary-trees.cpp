/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (75.18%)
 * Likes:    941
 * Dislikes: 88
 * Total Accepted:    38.2K
 * Total Submissions: 50.8K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 * 
 * Each node of each tree in the answer must have node.val = 0.
 * 
 * You may return the final list of trees in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 20
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
    // vector<TreeNode*> allPossibleFBT(int N) {
    //     if(N%2==0) return {};
    //     if(N == 1) return {new TreeNode(0)};
    //     vector<TreeNode*> res;
    //     for(int i=1; i<N-1; i+=2)
    //     {
    //         vector<TreeNode*> left = allPossibleFBT(i);
    //         vector<TreeNode*> right = allPossibleFBT(N-1-i);
    //         for(TreeNode* l : left)
    //         {
    //             for(TreeNode* r : right)
    //             {
    //                 TreeNode* root = new TreeNode(0);
    //                 root->left = l;
    //                 root->right = r;
    //                 res.push_back(root);
    //             }
    //         }
    //     }
    //     return res;
    // }

    /////////////////////////////////////////////////

    TreeNode* clone(TreeNode* root) {
        TreeNode* new_root = new TreeNode(0);
        new_root->left = (root->left) ? clone(root->left) : nullptr;
        new_root->right = (root->right) ? clone(root->right) : nullptr; 
        return new_root;
    } 

    vector<TreeNode*> allPossibleFBT(int N) {
        std::vector<TreeNode*> ret;
        if (1 == N) {
            ret.emplace_back(new TreeNode(0));
        } else if (N % 2) {
            for (int i = 2; i <= N; i += 2) {
                auto left = allPossibleFBT(i - 1);
                auto right = allPossibleFBT(N - i);
                for (int l_idx = 0; l_idx < left.size(); ++l_idx) {
                    for (int r_idx = 0; r_idx < right.size(); ++r_idx) {
                        ret.emplace_back(new TreeNode(0));

                        // If we're using the last right branch, then this will be the last time this left branch is used and can hence
                        // be shallow copied, otherwise the tree will have to be cloned
                        ret.back()->left = (r_idx == right.size() - 1) ? left[l_idx] : clone(left[l_idx]);

                        // If we're using the last left branch, then this will be the last time this right branch is used and can hence
                        // be shallow copied, otherwise the tree will have to be cloned
                        ret.back()->right = (l_idx == left.size() - 1) ? right[r_idx] : clone(right[r_idx]);
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

