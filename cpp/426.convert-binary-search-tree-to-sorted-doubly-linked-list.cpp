/*

Description
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

Example 1:

Image text

Input: root = [4,2,5,1,3]

Image text

Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Image text

Example 2:

Input: root = [2,1,3]

Output: [1,2,3]

Example 3:

Input: root = []

Output: []

Explanation: Input is an empty tree. Output is also an empty Linked List.

Example 4:

Input: root = [1]

Output: [1]

Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000
Solution
If the root is null, simply return the root. If there is only one node in the binary search tree, then let the root’s predecessor and successor both point to the root itself, and return the root.

Use the idea of the solution to problem 94. Consider inorder traversal of the binary search tree, which contains all the elements sorted in ascending order.

However, this problem does not require returning a list of inorder traversal result. Therefore, when doing inorder traversal, maintain a previous node, which is initially null. Each time a node is met, make the previous node’s successor be the current node, and make the current node’s predecessor be the previous node.

After all the nodes are visited, all the relations between each pair of adjacent nodes are maintained. Since the list is required to be circular, make the head node’s predecessor be the tail node, and make the tail node’s successor be the head node. Finally, return the head node.

*/

// OJ: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* dfs(Node* root) {
        if (!root) return NULL;
        auto left = dfs(root->left), right = dfs(root->right);
        root->left = left ? left->left : (right ? right->left : root);
        root->right = right ? right : (left ? left : root);
        if (left) {
            left->left->right = root;
            left->left = right ? right->left : root;
        }
        if (right) {
            right->left->right = left ? left : root;
            right->left = root;
        }
        return left ? left : root;
    }

    Node* bfs(Node* root) {
        vector<Node*> data;
        vector<Node*> stk;
        while(root || stk.size()) {
            if(root){
                stk.push_back(root);
                root=root->left;
            }else{
                root=stk.back();
                stk.pop_back();
                data.push_back(root);
                root=root->right;
            }
        }

        for(int i=1; i<data.size(); ++i){
            data[i-1]->right = data[i];
            data[i]->left = data[i-1];
        }
        data[0]->left = data.back();
        data.back()->right = data[0];

        return data[0];
    }

    Node* treeToDoublyList(Node* root) {
        return dfs(root);
    }
};