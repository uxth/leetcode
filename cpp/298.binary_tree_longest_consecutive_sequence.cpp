/*

Question
Formatted question description: https://leetcode.ca/all/298.html

Given the root of a binary tree, return the length of the longest consecutive sequence path.

A consecutive sequence path is a path where the values increase by one along the path.

Note that the path can start at any node in the tree, and you cannot go from a node to its parent in the path.

 

Example 1:



Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:



Input: root = [2,null,3,2,null,1]
Output: 2
Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-3 * 104 <= Node.val <= 3 * 104
Algorithm
If the left child node exists and the node value is greater than the value of its parent node by 1, the function is called recursively.

If the node value is not exactly greater than 1, the function with the length reset is recursively called. The processing of the right child node and the left child node the same.

*/

// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    void dfs(TreeNode *root, TreeNode *parent = NULL, int length = 1) {
        if (!root) return;
        length = parent && parent->val + 1 == root->val ? length + 1 : 1;
        ans = max(ans, length);
        dfs(root->left, root, length);
        dfs(root->right, root, length);
    }
    int bfs(TreeNode* root){
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = 0;
        while(!q.empty()){
            auto [f, length] = q.front();
            q.pop();
            res = max(res, length);
            if(f->left){
                if(f->left->val == f->val + 1) q.push({f->left, length + 1});
                else q.push({f->left, 1});
            }
            if(f->right) {
                if(f->right->val == f->val + 1) q.push({f->right, length + 1});
                else q.push({f->right, 1});
            }
        }
        return res;
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};