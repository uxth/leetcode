/*

Question
Formatted question description: https://leetcode.ca/all/366.html

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 

Example 1:



Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
Algorithm
Each node is separated from the left child node and the right child node to get two depths,

Since the condition of becoming a leaf node is that the left and right child nodes are empty, we take the larger value of the left and right child nodes plus 1 as the depth value of the current node.

Knowing the depth value, you can add the node value to the correct position in the result.

*/

// OJ: https://leetcode.com/problems/find-leaves-of-binary-tree/
// Time: O(N)
// Space: O(H)
class Solution {
private:
    bool dfs(TreeNode *root, vector<int> &v) {
        if (!root) return true;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return true;
        }
        if (dfs(root->left, v)) root->left = NULL;
        if (dfs(root->right, v)) root->right = NULL;
        return false;
    }
    vector<int> removeLeaves(TreeNode *root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
public:
    vector<vector<int>> findLeavesMultipleLoop(TreeNode* root){
        if (!root) return {};
        vector<vector<int>> ans;
        while (root->left || root->right) {
            ans.push_back(removeLeaves(root));
        }
        ans.push_back({ root->val });
        return ans;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        return findLeavesMultipleLoop(root);
    }

    int markLevels(TreeNode* root, unordered_map<TreeNode*, int>& levels){
        if(root == nullptr) return -1;
        return levels[root] = 1 + max(markLevels(root->left, levels), markLevels(root->right, levels));
    }
    vector<vector<int>> findLeavesOneLoop(TreeNode* root){
        unordered_map<TreeNode*, int> levels;
        int size = markLevels(root, levels);
        vector<vector<int>> res(size+1);
        for(auto& [node, level] : levels){
            res[level].push_back(node->val);
        }
        return res;
    }
};