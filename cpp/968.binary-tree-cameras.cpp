/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (37.52%)
 * Likes:    859
 * Dislikes: 18
 * Total Accepted:    22.4K
 * Total Submissions: 59.4K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * Given a binary tree, we install cameras on the nodes of the tree. 
 * 
 * Each camera at a node can monitor its parent, itself, and its immediate
 * children.
 * 
 * Calculate the minimum number of cameras needed to monitor all nodes of the
 * tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as
 * shown.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 1000].
 * Every node has value 0.
 * 
 * 
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
    private: int NOT_MONITORED = 0;
    private: int MONITORED_NOCAM = 1;
    private: int MONITORED_WITHCAM = 2;
    private: int cameras = 0;
	
    public: int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        int top = dfs(root);
        return cameras + (top == NOT_MONITORED ? 1 : 0);
    }
    
    private: int dfs(TreeNode* root) {
        if (root == nullptr) return MONITORED_NOCAM;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == MONITORED_NOCAM && right == MONITORED_NOCAM) {
            return NOT_MONITORED;
        } else if (left == NOT_MONITORED || right == NOT_MONITORED) {
            cameras++;
            return MONITORED_WITHCAM;
        } else {
            return MONITORED_NOCAM;
        }
    }
};
// @lc code=end
// [0, null,0, null,0, null,0, null,0, null,0, null,0, null,0, null,0, null,0, null]
// [0,0,null,0,0,0,null,null,0]