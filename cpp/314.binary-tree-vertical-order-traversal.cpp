/*

Question
Formatted question description: https://leetcode.ca/all/314.html

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

 

Example 1:



Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Example 2:



Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
Example 3:



Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
Algorithm
How to determine the order of the columns, you can give the root node a sequence number of 0, and then start the traversal of the layer sequence. For any left child node, the sequence number is reduced by 1, and the right child node sequence number is increased by 1, so that the node value of the same column can be changed by the sequence number Put together

Another way, is to use a TreeMap to create a mapping between the sequence number and its corresponding node value.

advantage of using TreeMap is that its automatic sorting function allows the column to be sorted from left to right. Since the sequence traversal needs to use the queue, the queue cannot only be stored at this time for nodes, it is necessary to store a pair consisting of a sequence number and a node, so that the sequence number can be operated every time it is taken out, and the nodes in the queue are also assigned their correct sequence numbers.

*/


// OJ: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
// Time: O(NlogW) where N is the number of nodes in the tree and W is the width of the tree
// Space: O(N)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (q.size()) {
            auto [node, index] = q.front();
            q.pop();
            m[index].push_back(node->val);
            if (node->left) q.emplace(node->left, index - 1);
            if (node->right) q.emplace(node->right, index + 1);
        }
        vector<vector<int>> ans;
        for (auto &[index, v] : m) ans.push_back(v);
        return ans;
    }
};