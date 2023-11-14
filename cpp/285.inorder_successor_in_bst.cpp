/*

@lc app=leetcode id=285 lang=cpp


Question
Formatted question description: https://leetcode.ca/all/285.html

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:



Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:



Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
All Nodes will have unique values.
Algorithm
If the value of the root node is less than or equal to the value of the p node, it means that the successor node of p must be in the right subtree, so this function is recursively called on the right child node.

If the value of the root node is greater than the value of p, then it is possible that the root node is the successor of p, or a node in the left subtree is a successor of p, * So first call this function recursively on the left child node, * If it returns empty, indicating that the root node is a successor node, just return, * If it is not empty, return that node

*/

// OJ: https://leetcode.com/problems/inorder-successor-in-bst/
// Time: O(N)
// Space: O(logN)
// @lc code=start
class Solution {
private:
    TreeNode *target, *ans = NULL;
    bool seen = false;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (seen && !ans) ans = root;
        if (seen && ans) return;
        if (root == target) seen = true;
        inorder(root->right);
    }

    TreeNode* bfs(TreeNode* root, TreeNode* p){
        vector<TreeNode*> stk;
        TreeNode* res = nullptr;
        while(root || !stk.empty()){
            if(root){
                stk.push(root);
                root=root->left;
            }else{
                root = stk.top();
                stk.pop();
                if(root == p) return res;
                res = root;
                root = root->right;
            }
        }
        return res;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p;
        inorder(root);
        return ans;
    }
};

// @lc code=end