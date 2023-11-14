/*
Question
Formatted question description: https://leetcode.ca/all/270.html

Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. If there are multiple answers, print the smallest.

 

Example 1:



Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
Example 2:

Input: root = [1], target = 4.428571
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 109
-109 <= target <= 109
Algorithm
Use the characteristics of the binary search tree (left<root<right) to quickly locate, because the root node is an intermediate value,

When we traverse down, we compare according to the relationship between the target value and the value of the root node.

If the target value is less than the node value, we should find a smaller value, so we go to the left subtree to find, otherwise we go to the right subtree to find.

*/

// OJ: https://leetcode.com/problems/closest-binary-search-tree-value/
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double dist = abs(target - root->val);
        if (dist < .5) return root->val;
        if (root->val < target) {
            if (!root->right) return root->val;
            int right = closestValue(root->right, target);
            return dist < abs(target - right) ? root->val : right;
        }
        if (!root->left) return root->val;
        int left = closestValue(root->left, target);
        return dist < abs(target - left) ? root->val : left;
    }
};