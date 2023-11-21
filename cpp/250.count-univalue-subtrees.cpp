/*
Question
Formatted question description: https://leetcode.ca/all/250.html

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

 

Example 1:



Input: root = [5,1,5,5,5,null,5]
Output: 4
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6
 

Constraints:

The number of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
Algorithm
Check from bottom to top, using post-order traversal, left and right roots, we still call the function recursively.

For the currently traversed node, if the function is called recursively on the left and right child nodes, and the return is true.

Then it means that the value of the current node and the value of the left and right subtrees are the same, then there is another tree, so the result is incremented by 1.

*/
// OJ: https://leetcode.com/problems/count-univalue-subtrees/
// Time: O(N)
// Space: O(H) where H is the height of the tree
class Solution {
private:
    int cnt = 0;
    bool postorder(TreeNode *root) {
        if (!root) return true;
        bool left = postorder(root->left), right = postorder(root->right);
        if (left && right
            && (!root->left || root->val == root->left->val)
            && (!root->right || root->val == root->right->val)) {
            ++cnt;
            return true;
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        postorder(root);
        return cnt;
    }
};