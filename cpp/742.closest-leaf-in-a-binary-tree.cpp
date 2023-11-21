/*

Description
Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
Note:

root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.
Solution
Use a map to store each node’s value and the path from the root to the node. For the root, the path is empty. For other nodes, use “0” to represent moving to the left child and use “1” to represent moving to the right child. Use a set to store all the leaf nodes’ values. Do breadth first search on the binary tree to obtain all nodes’ paths and obtain all the leaf nodes.

After all nodes’ paths are obtained and all the leaf nodes are obtained, for each leaf node, calculate the distance between the leaf node’s path and the target node’s path. The distance is calculated by obtaining the first index that the two paths differ, and calculate the sum of the remaining characters in both paths. Find the leaf node that has the least distance, and return its value.

*/

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
    unordered_map<TreeNode*, vector<TreeNode*>> g;

    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, nullptr);
        queue<TreeNode*> q;
        for (auto& e : g) {
            if (e.first && e.first->val == k) {
                q.push(e.first);
                break;
            }
        }
        unordered_set<TreeNode*> seen;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            seen.insert(node);
            if (node) {
                if (!node->left && !node->right) return node->val;
                for (auto next : g[node]) {
                    if (!seen.count(next))
                        q.push(next);
                }
            }
        }
        return 0;
    }

    void dfs(TreeNode* root, TreeNode* p) {
        if (!root) return;
        g[root].push_back(p);
        g[p].push_back(root);
        dfs(root->left, root);
        dfs(root->right, root);
    }


    int bfs(TreeNode* root, int k){
        if(root == nullptr) return 0;
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* start = nullptr;
        while(!q.empty()){
            TreeNode* f = q.front();
            if(f->val == k) {
                start = f;
            }
            q.pop();
            if(f->left){
                parent[f->left] = f;
                q.push(f->left);
            }
            if(f->right){
                parent[f->right] = f;
                q.push(f->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(start);
        visited.insert(start);

        while(!q.empty()){
   
            TreeNode* f = q.front();
            q.pop();
            if(f->left == nullptr && f->right == nullptr) return f->val;
            if(f->left && !visited.count(f->left)){
                visited.insert(f->left);
                q.push(f->left);
            }
            if(f->right && !visited.count(f->right)){
                visited.insert(f->right);
                q.push(f->right);
            }
            if(parent[f] && !visited.count(parent[f])){
                visited.insert(parent[f]);
                q.push(parent[f]);
            }

        }
        return -1;
    }
};