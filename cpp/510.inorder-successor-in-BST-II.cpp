/*

Description
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node.

Example 1:

Image text

Input: 
root = {"$id":"1","left":{"$id":"2","left":null,"parent":{"$ref":"1"},"right":null,"val":1},"parent":null,"right":{"$id":"3","left":null,"parent":{"$ref":"1"},"right":null,"val":3},"val":2}
p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of Node type.
Example 2:

Image text

Input: 
root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":"4","left":null,"parent":{"$ref":"3"},"right":null,"val":1},"parent":{"$ref":"2"},"right":null,"val":2},"parent":{"$ref":"1"},"right":{"$id":"5","left":null,"parent":{"$ref":"2"},"right":null,"val":4},"val":3},"parent":null,"right":{"$id":"6","left":null,"parent":{"$ref":"1"},"right":null,"val":6},"val":5}
p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
Example 3:

Image text

Input: 
root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":"4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},"parent":{"$ref":"2"},"right":{"$id":"5","left":null,"parent":{"$ref":"3"},"right":null,"val":4},"val":3},"parent":{"$ref":"1"},"right":{"$id":"6","left":null,"parent":{"$ref":"2"},"right":{"$id":"7","left":{"$id":"8","left":null,"parent":{"$ref":"7"},"right":null,"val":9},"parent":{"$ref":"6"},"right":null,"val":13},"val":7},"val":6},"parent":null,"right":{"$id":"9","left":{"$id":"10","left":null,"parent":{"$ref":"9"},"right":null,"val":17},"parent":{"$ref":"1"},"right":{"$id":"11","left":null,"parent":{"$ref":"9"},"right":null,"val":20},"val":18},"val":15}
p = 15
Output: 17
Example 4:

Image text

Input: 
root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":"4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},"parent":{"$ref":"2"},"right":{"$id":"5","left":null,"parent":{"$ref":"3"},"right":null,"val":4},"val":3},"parent":{"$ref":"1"},"right":{"$id":"6","left":null,"parent":{"$ref":"2"},"right":{"$id":"7","left":{"$id":"8","left":null,"parent":{"$ref":"7"},"right":null,"val":9},"parent":{"$ref":"6"},"right":null,"val":13},"val":7},"val":6},"parent":null,"right":{"$id":"9","left":{"$id":"10","left":null,"parent":{"$ref":"9"},"right":null,"val":17},"parent":{"$ref":"1"},"right":{"$id":"11","left":null,"parent":{"$ref":"9"},"right":null,"val":20},"val":18},"val":15}
p = 13
Output: 15
Note:

If the given node has no in-order successor in the tree, return null.
It’s guaranteed that the values of the tree are unique.
Remember that we are using the Node type instead of TreeNode type so their string representation are different.
Follow up:

Could you solve it without looking up any of the node’s values?

Solution
Since the tree is a binary search tree, there is no need to look up any of the node’s values.

If the node has a right child, then obtain the leftmost node in the current node’s left subtree, which is the in-order success of the current node.

If the node doesn’t have a right child, then the node has an in-order successor if and only if there is another node such that the current node is in another node’s left subtree. Starting from the current node, find each node’s parent. If there exist a (parent, child) pair such that the child is the parent’s left child, then return the parent. If such a parent is not found, return null.

*/

// OJ: https://leetcode.com/problems/inorder-successor-in-bst-ii/
// Time: O(H)
// Space: O(1)
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            Node *n = nullptr;
            for (auto p = node->right; p; p = p->left) n = p;
            return n;
        }
        auto p = node->parent;
        while (p && p->val < node->val) p = p->parent;
        return p;
    }
};