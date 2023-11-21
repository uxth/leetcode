/*

Description
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          /
4   5        6
   / \      / \
  7   8    9  10

Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
Solution
Visit the binary tree in the following order: the root, the left subtree, the leaf nodes, and the right subtree.

The root is the first node in the boundary.
If the root has a left child, then visit the left subtree. The first node visited after the root is the left child of the root, and add the left child to the boundary. Then each time check whether the current node has a left child. If so, move to the left child. Otherwise, move to the right child (if it has a right child). As long as the current node is not a leaf node, add it to the boundary.
Visit all the leaf nodes from left to right, and add the leaf nodes to the boundary.
If the root has a right child, then visit the right subtree. The right subtree is visited quite similar to the way that the left subtree is visited, but the right child is considered before the left child, and the nodes are added to the boundary in reversing order.
Finally, return the list of the boundary.

*/

// OJ: https://leetcode.com/problems/boundary-of-binary-tree/
// Time: O(N)
// Space: O(H)
class Solution
{
    vector<int> ans, right;
    void dfs(TreeNode *node, int state)
    { // 1 left boundary, 2 right boundary, 0 otherwise
        if (!node)
            return;
        if (state == 1)
            ans.push_back(node->val);
        else if (state == 2)
            right.push_back(node->val);
        else if (!node->left && !node->right)
            ans.push_back(node->val);
        dfs(node->left, state == 1 ? 1 : (state == 2 && !node->right ? 2 : 0));
        dfs(node->right, state == 2 ? 2 : (state == 1 && !node->left ? 1 : 0));
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        ans.push_back(root->val);
        dfs(root->left, 1);
        dfs(root->right, 2);
        for (int i = right.size() - 1; i >= 0; --i)
            ans.push_back(right[i]);
        return ans;
    }

    vector<int> bfs(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<TreeNode *>> data;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> level;
            while (size--)
            {
                TreeNode *f = q.front();
                q.pop();
                level.push_back(f);
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            data.push_back(level);
        }

        vector<int> res{root->val};
        for (int i = 1; i < data.size() - 1; ++i)
            res.push_back(data[i].front()->val);
        for (auto i : data.back())
            res.push_back(i->val);
        for (int i = data.size() - 2; i > 0; --i)
            res.push_back(data[i].back()->val);
        return res;
    }
};